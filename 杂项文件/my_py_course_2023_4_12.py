# ljp的python程序
# 自2022/12/20开始学习python
# 预计目标不多能使用python在第三方软件里做视频软件即可
# 本次开发时间： 2023/4/12 8:53
a, b = input().split()
a = float(a)
b = float(b)
c1 = b * 0.1
c2 = b * 0.5
if a < (c1 + b):
    print("OK")
elif (c1 + b) <= a < (c2 + b):
    print("Exceed x%,Ticket 200!")
else:
    print("Exceed x%,License Revoked!")
