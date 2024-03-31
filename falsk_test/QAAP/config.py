""" 文件描述
存放关于 Flask 对象的相关配置
"""

import os


# 数据库配置
USERNAME                = os.getenv('EIMOU_DATABASE_USER')
PASSWORD                = os.getenv('EIMOU_DATABASE_PASSWORD')
SERVER_IP               = os.getenv('EIMOU_DATABASE_HOST')
SERVER_PORT             = '3306'
DATABASE_NAME           = os.getenv('QAAP_DATABASE_NAME')
DB_URI                  = 'mysql+pymysql://{}:{}@{}:{}/{}?charset=utf8mb4'.format(USERNAME, PASSWORD, SERVER_IP, SERVER_PORT, DATABASE_NAME)
SQLALCHEMY_DATABASE_URI = DB_URI

# 邮箱配置
MAIL_SERVER = 'smtp.qq.com'                             # SMTP 服务器地址(这里配置的是 qq 的)
MAIL_USE_SSL = True                                     # 使用 SSL 加密
MAIL_PORT = 465                                         # qq 邮箱服务器公开的端口号
MAIL_USERNAME = os.getenv('MAIL_NAME')                  # 邮箱账户
MAIL_PASSWORD = os.getenv('MAIL_SMTP')                  # 授权密码
MAIL_DEFAULT_SENDER = ('limou', os.getenv('MAIL_NAME')) # 默认发送者

if __name__ == '__main__':
    print(SQLALCHEMY_DATABASE_URI)
    print(MAIL_USERNAME)
    print(MAIL_PASSWORD)