#!/mnt/Profession/Develop/Python/Flask_Pro/venv/bin python3
import os
from app import create_app, db
from flask.ext.script import Manager, Shell
from flask.ext.migrate import Migrate, MigrateCommand

app = create_app(os.getenv('FLASK_CONFIG') or 'default')
manager = Manager(app)
migrate = Migrate(app,db)

def make_shell_context():
	from app.models import User, Question, Role, Post, Comment, Follow
	return dict(app =app, db = db, User = User, Question = Question,\
                Role = Role, Post =Post, Comment= Comment, Follow=Follow)
manager.add_command("shell",Shell(make_context =make_shell_context))
manager.add_command('db',MigrateCommand)

@manager.command
def test():
	''' Run the unit tests.'''
	import unittest
	tests = unittest.TestLoader().discover('tests')
	unittest.TextTestRunner(verbosity=2).run(tests)

@manager.command
def init():
	'''Init the database'''
	from app.models import User, Role
	db.drop_all()
	db.create_all()
	Role.insert_roles()
	u = User(email='forec@bupt.edu.cn',\
             username = 'forec',\
             password = 'test',\
             confirmed = True,\
             role = Role.query.filter_by(name='Administrator').first(),\
             name = 'forec',\
             location = 'Beijing, China',\
             about_me = 'Wait for updating')
	db.session.add(u)
	db.session.commit()
	
if __name__ == '__main__':
	manager.run()
