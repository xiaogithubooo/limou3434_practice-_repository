""" 文件描述
存放关于 Flask 对象的相关配置
"""

import os

USERNAME                = os.getenv('EIMOU_DATABASE_USER')
PASSWORD                = os.getenv('EIMOU_DATABASE_PASSWORD')
SERVER_IP               = os.getenv('EIMOU_DATABASE_HOST')
SERVER_PORT             = '3306'
DATABASE_NAME           = os.getenv('QAAP_DATABASE_NAME')

DB_URI                  = 'mysql+pymysql://{}:{}@{}:{}/{}?charset=utf8mb4'.format(USERNAME, PASSWORD, SERVER_IP, SERVER_PORT, DATABASE_NAME)
SQLALCHEMY_DATABASE_URI = DB_URI