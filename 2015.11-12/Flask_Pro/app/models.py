from . import db
from markdown import markdown
from . import login_manager
from flask.ext.login import UserMixin, AnonymousUserMixin
from werkzeug.security import generate_password_hash, check_password_hash
from flask import current_app, request
from . import db, login_manager
from itsdangerous import TimedJSONWebSignatureSerializer as Serialzer
from app.exceptions import ValidationError
from datetime import datetime
import hashlib
import bleach

class Comment(db.Model):
	__tablename__ = 'comments'
	id = db.Column(db.Integer, primary_key =True)
	body = db.Column(db.Text)
	body_html = db.Column(db.Text)
	timestamp = db.Column(db.DateTime, default=datetime.utcnow)
	author_id = db.Column(db.Integer, db.ForeignKey('users.id'))
	post_id = db.Column(db.Integer, db.ForeignKey('posts.id'))

	@staticmethod
	def on_changed_body(target, value, oldvalue, initiator):
		allowed_tags = ['a', 'abbr', 'acronym', 'b', 'code', 'em','i','strong']
		target.body_html = bleach.linkify(bleach.clean(
			markdown(value, output_format = 'html'),
			tags=allowed_tags, strip = True))

	@staticmethod
	def generate_fake(count=100):
		from random import seed, randint
		import forgery_py
		seed()
		user_count = User.query.count()
		post_count = Post.query.count()
		for i in range(count):
			u = User.query.offset(randint(0,user_count - 1)).first()
			p = Post.query.offset(randint(0,post_count - 1)).first()
			c = Comment(body = forgery_py.lorem_ipsum.sentences(randint(1,5)),
						timestamp = forgery_py.date.date(True),
						author = u, post = p)
			db.session.add(c)
			db.session.commit()

class Post(db.Model):
	__tablename__ = 'posts'
	id = db.Column(db.Integer, primary_key = True)
	body = db.Column(db.Text)
	timestamp = db.Column(db.DateTime, index = True, default = datetime.utcnow)
	author_id = db.Column(db.Integer, db.ForeignKey('users.id'))
	body_html = db.Column(db.Text)
	comments = db.relationship('Comment', backref='post', lazy='dynamic')

	def to_json(self):
		json_post = {
			'url' : url_for('api.get_post', id =self.id, _external = True),
			'body': self.body,
			'body_html': self.body_html,
			'timestamp': self.timestamp,
			'author': url_for('api.get_user', id = self.author._id, _external = True),
			'comments': url_for('api.get_post_comments', id = self.id, _external = True),
			'comment_count': self.comments.count()
			}
		return json_post

	@staticmethod
	def from_json(json_post):
		body = json_post.get('body')
		if body is None or body =='':
			raise ValidationError('post does not have a body')
		return Post(body = body)
	
	@staticmethod
	def generate_fake(count=100):
		from random import seed, randint
		import forgery_py
		seed()
		user_count=User.query.count()
		for i in range(count):
			u=User.query.offset(randint(0,user_count-1)).first()
			p = Post(body=forgery_py.lorem_ipsum.sentences(randint(1,5)),
					 timestamp=forgery_py.date.date(True),
					 author=u)
			db.session.add(p)
			db.session.commit()

	@staticmethod
	def on_changed_body(target, value, oldvalue, initiator):
		allowed_tags = ['a', 'abbr',  'acronym', 'b', 'blockquote', 'code',
						'em', 'i', 'li', 'ol','pre','strong','ul','h1','h2','h3','p','h4',
						'h5','h6']
		target.body_html =bleach.linkify(bleach.clean(markdown(value, output_format='html'), tags=allowed_tags, strip=True))

db.event.listen(Post.body, 'set', Post.on_changed_body)
db.event.listen(Comment.body, 'set', Comment.on_changed_body)

class Follow(db.Model):
	__tablename__ = 'follows'
	follower_id = db.Column(db.Integer, db.ForeignKey('users.id'), primary_key = True)
	followed_id = db.Column(db.Integer, db.ForeignKey('users.id'), primary_key = True)
	timestamp = db.Column(db.DateTime, default = datetime.utcnow)

class User(UserMixin, db.Model):
	__tablename__ = 'users'
	id = db.Column(db.Integer, primary_key = True)
	email = db.Column(db.String(64),unique = True, index = True)
	username = db.Column(db.String(64), unique = True, index = True)
	passwd_hash = db.Column(db.String(128))
	confirmed = db.Column(db.Boolean, default=False)
	role_id = db.Column(db.Integer, db.ForeignKey('roles.id'))
	posts = db.relationship('Post',backref='author',lazy='dynamic')
	comments = db.relationship('Comment', backref = 'author', lazy='dynamic')
	name = db.Column(db.String(64))
	location = db.Column(db.String(64))
	about_me = db.Column(db.Text())
	member_since = db.Column(db.DateTime(), default = datetime.utcnow)
	last_seen = db.Column(db.DateTime(), default = datetime.utcnow)
	avatar_hash = db.Column(db.String(32))
	followed = db.relationship('Follow', foreign_keys=[Follow.follower_id],
							   backref=db.backref('follower', lazy='joined'),
							   lazy = 'dynamic',
							   cascade='all, delete-orphan')
	followers = db.relationship('Follow', foreign_keys=[Follow.followed_id],
							   backref=db.backref('followed', lazy='joined'),
							   lazy = 'dynamic',
							   cascade='all, delete-orphan')
	
	def __init__(self, **kwargs):
		super(User,self).__init__(**kwargs)
		if self.role is None:
			if self.email == current_app.config['FLASKY_ADMIN']:
				self.role = Role.query.filter_by(permissions=0xff).first()
			if self.role is None:
				if self.confirmed == True:
					self.role = Role.query.filter_by(name='User').first()
				else:
					self.role = Role.query.filter_by(default = True).first()
		if self.email is not None and self.avatar_hash is None:
			self.avatar_hash = hashlib.md5(self.email.encode('utf-8')).hexdigest()
		# self.follow(self)
		self.followed.append(Follow(followed=self))

	def can(self, permissions):
		return self.role is not None and\
		  ( self.role.permissions & permissions ) == permissions

	def is_administrator(self):
		return self.can(Permission.ADMINISTER)

	def ping(self):
		self.last_seen = datetime.utcnow()
		db.session.add(self)
		db.session.commit()

	def to_json(self):
		json_user = {
			'url': url_for('api.get_post', id =self.id ,_external  = True),
			'username' : self.username,
			'menber_since': self.member_since,
			'last_seen': self.last_seen,
			'posts': url_for('api.get_user_posts', id = self.id, _external = True),
			'followed_posts': url_for('api.get_user_followed_posts', id = self.id, _external = True),
			'post_count': self.posts.count()
			}
		return json_user
	
	@property
	def password(self):
		raise AttributeError('password is not a readable attribute')

	@property
	def followed_posts(self):
		return Post.query.join(Follow, Follow.followed_id == Post.author_id)\
		  .filter(Follow.follower_id == self.id)

	@password.setter
	def password(self, password):
		self.passwd_hash = generate_password_hash(password)

	def verify_password(self, password):
		return check_password_hash(self.passwd_hash, password)

	def generate_confirmation_token(self, expiration=3600):
		s = Serialzer(current_app.config['SECRET_KEY'], expiration)
		return s.dumps({'confirm':self.id})
	def confirm(self,token):
		s = Serialzer( current_app.config['SECRET_KEY'] )
		try:
			data = s.loads(token)
		except:
			return False
		if data.get('confirm') != self.id:
			return False
		self.confirmed = True
		self.role = Role.query.filter_by(name='User').first()
		db.session.add(self)
		db.session.commit()
		return True

	def generate_change_email_token(self,new_email, expiration = 3600):
		s = Serialzer(current_app.config['SECRET_KEY'], expiration)
		return s.dumps({'confirm':self.id, 'old_email':self.email, 'new_email':new_email})

	def confirm_change_email(self, token):
		s = Serialzer(current_app.config['SECRET_KEY'])
		try:
			data = s.loads(token)
		except:
			return False
		if data.get('confirm') != self.id or data.get('old_email') != self.email:
			return False
		self.email = data.get('new_email')
		self.avatar_hash = hashlib.md5(self.email.encode('utf-8')).hexdigest()
		db.session.add(self)
		db.session.commit()
		return True

	def generate_reset_token(self, expiration = 3600):
		s = Serialzer(current_app.config['SECRET_KEY'], expiration)
		return s.dumps({'confirm':self.id, 'old_password':self.passwd_hash})

	def confirm_reset_password(self,token):
		s = Serialzer(current_app.config['SECRET_KEY'])
		try:
			data = s.loads(token)
		except:
			return False
		if data.get('confirm') != self.id or data.get('old_password') != self.passwd_hash:
			return False
		return True

	def gravatar(self, size=100, default='identicon', rating='g'):
		if request.is_secure:
			url="https://secure.gravatar.com/avatar"
		else:
			url="http://www.gravatar.com/avatar"
		hash = self.avatar_hash or hashlib.md5(self.email.encode('utf-8')).hexdigest()
		return '{url}/{hash}?s={size}&d={default}&r={rating}'.format(url=url, hash=hash, size=size,default=default,rating=rating)

	def generate_auth_token(self, expiration = 3600):
		s = Serializer(current_app.config['SECRET_KEY'],
					   expires_in = expiration)
		return s.dumps({'id':self.id})

	@staticmethod
	def verify_auth_token(token):
		s = Serializer(current_app.config['SECRET_KEY'])
		try:
			data = s.loads(token)
		except:
			return None
		return User.query.get(data.get('id'))

	@staticmethod
	def generate_fake(count=100):
		from sqlalchemy.exc import IntegrityError
		from random import seed, randint
		import forgery_py
		seed()
		user_count = User.query.count()
		for i in range(count):
			u = User(email=forgery_py.internet.email_address(),
					 username=forgery_py.internet.user_name(True),
					 password=forgery_py.lorem_ipsum.word(),
					 confirmed=True,
					 name=forgery_py.name.full_name(),
					 location=forgery_py.address.city(),
					 about_me=forgery_py.lorem_ipsum.sentence(),
					 member_since=forgery_py.date.date(True))
			for j in range(i):
				ut=User.query.offset(randint(0,user_count-1)).first()
				if ut is not None:
					u.follow(ut)
			db.session.add(u)
			try:
				db.session.commit()
			except IntegrityError:
				db.session.rollback()
				db.session.commit()

	@staticmethod
	def add_self_follows():
		for user in User.query.all():
			if not user.is_following(user):
				user.follow(user)
				db.session.add(user)
				db.session.commit()

	def follow(self,user):
		if not self.is_following(user):
			f = Follow(follower=self, followed=user)
			db.session.add(f)
			db.session.commit()

	def unfollow(self, user):
		f = self.followed.filter_by(followed_id=user.id).first()
		if f:
			db.session.delete(f)
			db.session.commit()

	def is_following(self, user):
		return self.followed.filter_by(followed_id=user.id).first() is not None

	def is_followed_by(self, user):
		return self.followers.filter_by(follower_id = user.id).first() is not None
	
	def __repr__(self):
		return '<User: %r>' % self.username

class AnonymousUser(AnonymousUserMixin):
	def can(self, permissions):
		return False
	def is_administrator(self):
		return False
	def is_anonymous(self):
		return True

login_manager.anonymous_user = AnonymousUser

class Role(db.Model):
	__tablename__ = 'roles'
	id = db.Column(db.Integer, primary_key = True)
	name = db.Column(db.String(64))
	default = db.Column(db.Boolean, default = False, index = True)
	permissions = db.Column(db.Integer)
	users = db.relationship('User',backref='role',lazy = 'dynamic')

	@staticmethod
	def insert_roles():
		roles = {
			'Uncheck_user':(0x00, True),
			'User': (Permission.FOLLOW |
					  Permission.COMMENT |
					  Permission.WRITE_ARTICLES, False),
			'Moderator': (Permission.FOLLOW |
						   Permission.COMMENT |
						   Permission.WRITE_ARTICLES |
						   Permission.MODERATE_COMMENTS, False),
			'Administrator': (0xff, False)
			}
		for r in roles:
			role = Role.query.filter_by(name=r).first()
			if role is None:
				role = Role(name=r)
			role.permissions = roles[r][0]
			role.default = roles[r][1]
			db.session.add(role)
		db.session.commit()

	def __repr__(self):
		return '<Role: %r>' % self.name

class Permission:
	FOLLOW = 0x01						  # follow other users
	COMMENT = 0x02						  # comment on other users' articles
	WRITE_ARTICLES = 0x04				  # write articles
	MODERATE_COMMENTS = 0x08			  # moderate users' comments
	ADMINISTER = 0x80					  # administer
	#  anynomous 0x00 0b00000000   read only
	#  user	 0x07 0b00000111   write articles, comment, follow ( default user )
	#  helper admin 0x0f 0b00001111	  add moderation on normal user
	#  administer  0xff	 0b11111111	  all permissions
	
class Question(db.Model):
	__tablename__ = 'questions'
	ques = db.Column(db.String(1024))
	id = db.Column(db.String(64))
	quesid = db.Column(db.Integer, primary_key = True)
	def __repr__(self):
		return 'Ques from %r is : %r'%(self.id,self.ques)

@login_manager.user_loader
def load_user(user_id):
	return User.query.get(int(user_id))
