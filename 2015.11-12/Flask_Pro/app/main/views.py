from datetime import datetime
from flask import render_template, session, redirect, url_for, flash, request, current_app, make_response
from flask.ext.login import login_required, current_user
from ..decorators import admin_required, permission_required

from . import main
from .forms import NameForm, EditProfileForm, EditProfileAdminForm, PostForm, CommentForm
from .. import db
from ..models import User, Permission, Role, Post, Comment
from ..email import send_email

@main.route('/',methods=['GET','POST'])
def index():
	form = PostForm()
	if current_user.can(Permission.WRITE_ARTICLES) and \
	  form.validate_on_submit():
	  post = Post(body = form.body.data, author=current_user._get_current_object())
	  db.session.add(post)
	  db.session.commit()
	  return redirect(url_for('main.index'))
	page = request.args.get('page',1,type=int)
	show_followed = False
	if current_user.is_authenticated:
		show_followed = bool(request.cookies.get('show_followed',''))
	if show_followed:
		query = current_user.followed_posts
	else:
		query = Post.query
	pagination = query.order_by(Post.timestamp.desc()).paginate(
		page, per_page=current_app.config['FLASKY_POSTS_PER_PAGE'],
		error_out=False)
	posts = pagination.items
	return render_template('index.html',current_time = datetime.utcnow(),form = form, posts=posts,pagination=pagination, show_followed=show_followed)

@main.route('/all')
@login_required
def show_all():
	resp = make_response(redirect(url_for('main.index')))
	resp.set_cookie('show_followed','',max_age=30*24*60*60)
	return resp

@main.route('/followed')
@login_required
def show_followed():
	resp = make_response(redirect(url_for('main.index')))
	resp.set_cookie('show_followed','1',max_age=30*24*60*60)
	return resp

@main.route('/rules')
def show_rules():
	return render_template('main/rules.html')

@main.route('/user/<username>')
def user_profile(username):
	user = User.query.filter_by(username = username).first()
	if user is None:
		abort(404)
	page = request.args.get('page',1,type=int)
	pagination = user.posts.order_by(Post.timestamp.desc()).paginate(
		page, per_page=current_app.config['FLASKY_POSTS_PER_PAGE'],
		error_out=False)
	posts = pagination.items
	return render_template('profile/user_profile.html',user=user,posts=posts)

@main.route('/user/edit-profile',methods=['GET','POST'])
@login_required
def edit_profile():
	form = EditProfileForm()
	if form.validate_on_submit():
		current_user.name = form.name.data
		current_user.location = form.location.data
		current_user.about_me = form.about_me.data
		db.session.add(current_user)
		db.session.commit()
		flash('Your profile has been updated')
		return redirect(url_for('main.user_profile',username=current_user.username))
	form.name.data = current_user.name
	form.location.data = current_user.location
	form.about_me.data = current_user.about_me
	return render_template('profile/edit_profile.html', form = form)

@main.route('/user/edit-profile/<int:id>',methods=['GET','POST'])
@login_required
@admin_required
def edit_profile_admin(id):
	user= User.query.get_or_404(id)
	form = EditProfileAdminForm(user=user)
	if form.validate_on_submit():
		user.emali = form.email.data
		user.username = form.username.data
		user.confirmed = form.confirmed.data
		user.role  = Role.query.get(form.role.data)
		user.name = form.name.data
		user.location = form.location.data
		user.about_me = form.about_me.data
		db.session.add(user)
		db.session.commit()
		flash('The profile has been updated')
		return redirect(url_for('main.user_profile',username = user.username))
	form.email.data = user.email
	form.username.data = user.username
	form.confirmed.data = user.confirmed
	form.role.data = user.role_id
	form.name.data = user.name
	form.location.data = user.location
	form.about_me.data = user.about_me
	return render_template('profile/edit_profile.html',form=form,user=user)

@main.route('/post/<int:id>',methods=['GET','POST'])
def post(id):
    post = Post.query.get_or_404(id)
    form = CommentForm()
    if form.validate_on_submit():
        comment = Comment(body= form.body.data, post = post,author = current_user._get_current_object())
        db.session.add(comment)
        db.session.commit()
        flash('Your comment has been published.')
        return redirect(url_for('main.post',id = post.id)+'#comments')
    page = request.args.get('page',1,type=int)
    if page==-1:
        page = (post.comments.count()-1)/ current_app.config['FLASKY_COMMENTS_PER_PAGE'] +1
    pagination = post.comments.order_by(Comment.timestamp.asc()).paginate(
        page, per_page = current_app.config['FLASKY_COMMENTS_PER_PAGE'],
        error_out = False)
    comments = pagination.items
    if current_user.is_anonymous:
        moderate = False
    else:
        if current_user.id == post.author_id or current_user.can(Permission.MODERATE_COMMENTS):
            moderate = True
        else:
            moderate = False
    return render_template('main/articles.html', posts=[post], form = form, comments= comments, pagination = pagination, moderate_set = moderate)

@main.route('/edit-post/<int:id>', methods=['GET','POST'])
@login_required
def edit_post(id):
    post = Post.query.get_or_404(id)
    if current_user != post.author and \
      not current_user.can(Permission.ADMINISTER):
      abort(403)
    form = PostForm()
    if form.validate_on_submit():
        post.body = form.body.data
        db.session.add(post)
        flash('The post has been updated')
        return redirect(url_for('.post',id = post.id))
    form.body.data=post.body
    return render_template('main/edit_articles.html',form = form)

@main.route('/delete-post/<int:id>', methods=['GET','POST'])
@login_required
def delete_post(id):
    post= Post.query.get_or_404(id)
    if current_user != post.author and not current_user.can(Permission.ADMINISTER):
        abort(403)
    flash('Attention! The delete operation can\'t be recovered!')
    form = PostForm()
    if form.validate_on_submit():
        post.body = form.body.data
        db.session.add(post)
        flash('The post has been updated')
        return redirect(url_for('.post',id = post.id))
    form.body.data=post.body
    return render_template('main/confirm_delete_post.html',post = post,form=form)

@main.route('/delete-post-confirm/<int:id>')
@login_required
def delete_post_confirm(id):
    post = Post.query.get_or_404(id)
    if current_user != post.author and not current_user.can(Permission.ADMINISTER):
        abort(403)
    db.session.delete(post)
    db.session.commit()
    return redirect(url_for('main.index'))

@main.route('/follow/<username>')
@login_required
@permission_required(Permission.FOLLOW)
def follow(username):
    user = User.query.filter_by(username=username).first()
    if user is None:
        flash('Invalid User.')
        return redirect(url_for('main.index'))
    if current_user.is_following(user):
        flash('You are already following this user.')
        return redirect(url_for('main.user_profile',username=username))
    current_user.follow(user)
    flash('You are now following %s.'% username)
    return redirect(url_for('main.user_profile', username=username))

@main.route('/unfollow/<username>')
@login_required
@permission_required(Permission.FOLLOW)
def unfollow(username):
    user = User.query.filter_by(username=username).first()
    if user is None:
        flash('Invalid User.')
        return redirect(url_for('main.index'))
    if not current_user.is_following(user):
        flash('You didn\'t follow this user.')
        return redirect(url_for('main.user_profile',username=username))
    current_user.unfollow(user)
    flash('You have unfollowed %s.'% username)
    return redirect(url_for('main.user_profile', username=username))

@main.route('/followers/<username>')
def followers(username):
    user = User.query.filter_by(username=username).first()
    if user is None:
        flash('Invalid User')
        return redirect(url_for('main.index'))
    page = request.args.get('page',1,type=int)
    pagination = user.followers.paginate(
        page, per_page = current_app.config['FLASKY_FOLLOWERS_PER_PAGE'],
        error_out = False)
    follows = [{'user':item.follower, 'timestamp': item.timestamp} for item in pagination.items]
    return render_template('main/followers.html', user=user, title='Followers of', endpoint='main.followers', \
                           pagination = pagination, follows = follows)

@main.route('/followed_by/<username>')
def followed_by(username):
    user = User.query.filter_by(username=username).first()
    if user is None:
        flash('Invalid User')
        return redirect(url_for('main.index'))
    page = request.args.get('page',1,type=int)
    pagination = user.followed.paginate(
        page, per_page = current_app.config['FLASKY_FOLLOWERS_PER_PAGE'],
        error_out = False)
    follows = [{'user':item.followed, 'timestamp': item.timestamp} for item in pagination.items]
    return render_template('main/followers.html', user=user, title='Follows from', endpoint='main.followed_by', \
                           pagination = pagination, follows = follows)

@main.route('/moderate')
@login_required
@permission_required(Permission.MODERATE_COMMENTS)
def moderate():
    page = request.args.get('page',1,type =int)
    pagination = Comment.query.order_by(Comment.timestamp.desc()).paginate(page, per_page = current_app.config['FLASKY_COMMENTS_PER_PAGE'],error_out = False)
    comments= pagination.items
    return render_template('main/moderate.html', comments= comments, pagination = pagination, page = page)

@main.route('/moderate_delete/<int:id>')
@login_required
def moderate_delete(id):
    comment = Comment.query.get_or_404(id)
    if( not current_user.can(Permission.MODERATE_COMMENTS) ) and( current_user.id != comment.author_id ) and (current_user.id != Post.query.filter_by(id = comment.post_id).first().author_id):
        abort(403)
    else:
        db.session.delete(comment)
        db.session.commit()
        if ( current_user.can(Permission.MODERATE_COMMENTS)):
            return redirect(url_for('main.moderate', page= request.args.get('page',1,type=int)))
        else:
            return redirect(url_for('main.post',id = comment.post_id))
