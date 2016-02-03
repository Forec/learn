from flask import render_template, redirect, request, url_for, flash
from flask.ext.login import login_user, logout_user, login_required, current_user
from ..models import User
from ..email import send_email
from .forms import LoginForm, RegistrationForm, ChangePasswordForm, ChangeEmailForm, ResetPasswordForm, ConfirmResetPasswordForm
from . import auth
from .. import db

@auth.route('/login', methods=['GET','POST'])
def login():
	form = LoginForm()
	if form.validate_on_submit():
		user = User.query.filter_by(email=form.email.data).first()
		if user is not None and user.verify_password(form.password.data):
			login_user(user, form.remember_me.data)
			return redirect( request.args.get('next') or url_for('main.index'))
		flash('Invalid username of password.')
	return render_template('auth/login.html',form = form)

@auth.route('/logout')
@login_required
def logout():
	logout_user()
	flash('You have been logged out.')
	return redirect(url_for('main.index'))

@auth.route('/register', methods=['GET','POST'])
def register():
	form = RegistrationForm()
	if form.validate_on_submit():
		user = User(email =form.email.data, \
					username = form.username.data,\
					password = form.password.data)
		db.session.add(user)
		db.session.commit()
		token = user.generate_confirmation_token()
		send_email(user.email, 'Confirm your account', 'auth/email/confirm', user=user,token=token)
		login_user(user, False)
		flash('A confirmation email has been sent to you by email. Please confirm that mail to finish your registration.')
		return redirect(url_for('main.index'))
	return render_template('auth/register.html',form=form)

@auth.route('/confirm/<token>')
@login_required
def confirm(token):
	if current_user.confirmed:
		return redirect(url_for('main.index'))
	if current_user.confirm(token):
		flash('You have confirmed your account. Thanks!')
	else:
		flash('The confirmation link is invalid or has expired.')
	return redirect(url_for('main.index'))

@auth.before_app_request
def before_request():
	if current_user.is_authenticated:
		current_user.ping()
		if not current_user.confirmed\
		  and request.endpoint[:5] != 'auth.' \
		  and request.endpoint != 'static':
			return redirect(url_for('auth.unconfirmed'))

@auth.route('/unconfirmed')
def unconfirmed():
	if current_user.is_anonymous or current_user.confirmed:
		return redirect(url_for('main.index'))
	return render_template('auth/unconfirmed.html')

@auth.route('/confirm')
@login_required
def resend_confirmation():
	token = current_user.generate_confirmation_token()
	send_email(current_user.email, 'Confirm Your Account', 'auth/email/confirm', user=current_user, token = token)
	flash('A new confirmation email has been sent to you by email.')
	return redirect(url_for('main.index'))

@auth.route('/security_center',methods=['GET','POST'])
@login_required
def security_center():
	return render_template('auth/change/security_center.html');

@auth.route('/change_password', methods=['GET','POST'])
@login_required
def change_password():
	form = ChangePasswordForm()
	if form.validate_on_submit():
		if current_user.verify_password(form.old_password.data):
			current_user.password = form.new_password.data
			db.session.add(current_user)
			db.session.commit()
			return redirect(url_for('auth.change_successfully',type='password'))
		else:
			flash('Wrong Old password, input again')
			return redirect(url_for('auth.change_password'))
	return render_template('auth/change/change_password.html', form = form )

@auth.route('/change_email',methods=['GET','POST'])
@login_required
def change_email():
	form = ChangeEmailForm()
	if form.validate_on_submit():
		token = current_user.generate_change_email_token(new_email = form.New_email.data)
		send_email(form.New_email.data,'Confirm your new email','auth/change/change_email',user=current_user,token=token)
		flash('A confirmation email has been sent to your new email. Please confirm that mail to change your email address.')
		return redirect(url_for('main.index'))
	return render_template('auth/change/change_email_index.html', form = form)
		

@auth.route('/change_successfully/<type>')
@login_required
def change_successfully(type):
	return render_template('auth/change/change_successfully.html', user = current_user, type = type)

@auth.route('/confirm_email_change/<token>')
@login_required
def confirm_email_change(token):
	if current_user.confirm_change_email(token):
		flash('You have changed your email address. Thanks!')
	else:
		flash('The confirmation link is invalid or has expired.')
	return redirect(url_for('main.index'))

@auth.route('/reset_password',methods=['GET','POST'])
def reset_password():
	if not current_user.is_anonymous:
		flash('You are already online')
		return redirect(url_for('main.index'))
	form = ResetPasswordForm()
	if form.validate_on_submit():
		user = User.query.filter_by(email = form.Email.data).first()
		token = user.generate_reset_token()
		send_email(form.Email.data, 'Reset Your Password', 'auth/reset/reset_password',user=user,token=token)
		flash('A confirmation email has been sent to your new email. Please confirm that mail to change your email address.')
		return redirect(url_for('auth.login'))
	return render_template('auth/reset/reset_password_index.html',form=form)

@auth.route('/confirm_reset_password/<id>/<token>',methods=['GET','POST'])
def confirm_reset_password(id,token):
	if not current_user.is_anonymous:
		flash('You are already online')
		return redirect(url_for('main.index'))
	user = User.query.filter_by(id = id).first()
	if user is None:
		flash('User not existed!')
		return redirect(url_for('auth.login'))
	form = ConfirmResetPasswordForm()
	if user.confirm_reset_password(token):
		if form.validate_on_submit():
			user.password = form.newPassword.data
			db.session.add(user)
			db.session.commit()
			flash('You have reset your password successfully')
			return redirect(url_for('auth.login'))
		return render_template('auth/reset/confirm_reset_password.html',form=form)
	else:
		flash('The confirmation link is invalid or has expired.')
		return redirect(url_for('main.index'))
