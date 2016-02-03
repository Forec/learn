from flask.ext.wtf import Form
from wtforms import StringField, PasswordField, BooleanField, SubmitField, BooleanField
from wtforms.validators import Required, Length, Email, Regexp, EqualTo
from wtforms import ValidationError
from ..models import User

class LoginForm(Form):
    email = StringField('Email', validators = [Required(),Length(1,64),Email()])
    password = PasswordField('Password', validators=[Required(),Length(4,18)])
    remember_me = BooleanField('Keep me logged in')
    submit = SubmitField('Log In')

class RegistrationForm(Form):
    email = StringField('Email', validators = [Required(), Length(1,64), Email()])
    username = StringField('Username', validators = [Required(), Length(1,64), Regexp('^[A-Za-z0-9_.]+$',0,\
                                                                                 'Usernames must have only letters, numbers, dots or underscores')])
    password = PasswordField('Password',validators=[Required(),Length(4,18),\
                                                    EqualTo('password2',message='Passwords must match')])
    password2 = PasswordField('Confirm Password', validators = [Required(),Length(4,18)])
    accept = BooleanField('Accept <a href="/rules">rules</a>, attention: Must Accept, or you won\'t be allowed to register.', validators = [Required()])
    submit = SubmitField('Register')
    def validate_email(self, field):
        if User.query.filter_by(email = field.data).first():
            raise ValidationError('Email already registered.')
    def validate_username(self, field):
        if User.query.filter_by(username = field.data).first():
            raise ValidationError('Username already in use.')
        
class ChangePasswordForm(Form):
    old_password = PasswordField('Old Password', validators = [Required(), Length(4,18)])
    new_password = PasswordField('New Password', validators = [Required(), Length(4,18), \
                                                             EqualTo('new_password2',message='Passwords must match')])
    new_password2  = PasswordField('Confirm Password', validators = [Required(), Length(4, 18)])
    submit = SubmitField('Update Password')

class ChangeEmailForm(Form):
    New_email = StringField('New email address', validators = [Required(), Email()])
    submit = SubmitField('Update Email')
    def validate_New_email(self, field):
        if User.query.filter_by(email = field.data).first():
            raise ValidationError('Email already registerd.')
                       
class ResetPasswordForm(Form):
    Email = StringField('Your email address', validators = [Required(), Email()])
    submit = SubmitField('Submit')
    def validate_Email(self, field):
        if User.query.filter_by(email = field.data).first() is None:
            raise ValidationError('Email not registered')

class ConfirmResetPasswordForm(Form):
    newPassword = PasswordField('New Password', validators = [Required(), Length(4,18),\
                                                              EqualTo('newPassword2',message='Passwords must match')])
    newPassword2 = PasswordField('Confirm Password', validators = [Required(), Length(4, 18)])
    submit = SubmitField('Reset Password')
