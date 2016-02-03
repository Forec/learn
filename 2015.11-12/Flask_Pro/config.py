import os
basedir = os.path.abspath(os.path.dirname(__file__))

class Config:
    SECRET_KEY = os.environ.get('SECRET_KEY') or 'tempsecretkeyincodes'
    SQLALCHEMY_COMMIT_ON_TEARDOWN = True
    SQLALCHEMY_TRACK_MODIFICATIONS = True
    FLASKY_MAIL_SUBJECT_PREFIX = '[Forec]'
    FLASKY_MAIL_SENDER = '284103820@qq.com' # 'Forec <forec@bupt.edu.cn>'
    FLASKY_ADMIN = os.environ.get('FLASKY_ADMIN') or 'forec@bupt.edu.cn'
    FLASKY_POSTS_PER_PAGE = 20
    FLASKY_FOLLOWERS_PER_PAGE = 20
    FLASKY_COMMENTS_PER_PAGE = 10
    
    @staticmethod
    def init_app(app):
        pass

class DevelopmentConfig(Config):
    DEBUG = True
    MAIL_SERVER = 'smtp.qq.com'
    MAIL_PORT = 25
#    MAIL_USE_TLS = True
    MAIL_USERNAME = '284103820@qq.com'#os.environ.get('MAIL_USERNAME')
    MAIL_PASSWORD = 'Freedom2016' #os.environ.get('MAIL_PASSWORD') or 
    SQLALCHEMY_DATABASE_URI = os.environ.get('DEV_DATABASE_URL') or \
      'mysql://forec:VKDARK@localhost/webdb'

class TestingConfig(Config):
    TESTING = True
    SQLALCHEMY_DATABASE_URI = os.environ.get('TEST_DATABASE_URL') or \
      'mysql://forec:VKDARK@localhost/webdb'

class ProductionConfig(Config):
    DEBUG = False
    MAIL_SERVER = 'smtp.qq.com'
    MAIL_PORT = 25
#    MAIL_USE_TLS = True
    MAIL_USERNAME = '284103820@qq.com'#os.environ.get('MAIL_USERNAME')
    MAIL_PASSWORD = 'Freedom2016' #os.environ.get('MAIL_PASSWORD') or 
    SQLALCHEMY_DATABASE_URI = os.environ.get('DATABASE_URL') or \
      'mysql://forec:VKDARK@localhost/webdb'

config = {
    'development' : DevelopmentConfig,
    'testing' : TestingConfig,
    'production' : ProductionConfig,
    'default' : ProductionConfig#DevelopmentConfig
    }
