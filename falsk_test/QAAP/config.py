"""
配置文件：存放关于 Flask 对象的相关配置
"""
import os

# 创建 SQLAlchemy 对象
SQLALCHEMY_DATABASE_URI = (
    f"mysql+pymysql://"
    f"{os.getenv('EIMOU_DATABASE_USER')}:{os.getenv('EIMOU_DATABASE_PASSWORD')}@"
    f"{os.getenv('EIMOU_DATABASE_HOST')}:3306/{os.getenv('EIMOU_DATABASE_NAME')}"
    "?charset=utf8mb4"
)