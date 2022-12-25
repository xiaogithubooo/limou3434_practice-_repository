# ljp的python程序
# 自2022/12/20开始学习python
# 预计目标不多能使用python在第三方软件里做视频软件即可
# 本次开发时间： 2022/12/25 10:28
# 1、顺序结构
print('------------程序开始------------')
print('第一步：***')
print('第二步，***')
print('第三步，***')
print('------------程序结束------------')

# 2、测试对象的布尔值
# 第①类
print(bool(False))
print(bool(0))
print(bool(0.0))
print(bool(0.00))
print(bool(None))
print(bool(''))
# 不是特别懂python的字符是如何存储的，print(bool('\0'))
# ②空列表
print(bool([]))
print(bool(list()))
# ③空元组
print(bool(()))
print(bool(tuple()))
# ④空字典
print(bool({}))
print(bool(dict()))
# ⑤空集合
print(bool(set()))
# ⑥其他对象的布尔值都是True

# 3、if语句的使用
# 余额存储变量
money = 10000
s = int(input('请输入取款金额：'))
# 判断金额是否充足
if money >= s:
    money = money-s
    print('取款成功，余额为：', money)
else:
    print('取款金额过大！')

# 4、多分支语句的使用
num = int(input('请输入一个整数:'))
if num < 0:
    print('是负数')
elif num == 0:
    print('是零')
elif num > 0:
    print('是正数')
else:
    print('请检查输入数是否为正确输入')

# 5、嵌套语句
answer = input('您是会员吗？')
a = int(input('输入本次金额'))
if answer == 'y':
    print('会员')
    if money >= 200:
        print('8折后，付款金额为：', a*0.8)
    elif money >= 100:
        print('9折后，付款金额为', a*0.9)
else:
    print('非会员')
    if money >= 200:
        print('9.5折后，付款金额为：', a*0.95)
    elif money >= 100:
        print('不打折，付款金额为', a)

# 6、比较大小
num_a = int(input('请输入一个整数'))
num_b = int(input('请输入一个整数'))
'''
if num_a >= num_b:
    print(num_a, '大于等于', num_b)
else:
    print(num_a, '小于', num_b)
'''
print('使用条件表达式比较打印')
print(str(num_a) + '大于等于' + str(num_b) if num_a >= num_b else str(num_a) + '小于' + str(num_b))

# 7、pass语句的使用
answer = input('您是会员吗？')
if answer == 'y':
    pass
else:
    pass

# 8、range函数的使用
a = range(10)
b = range(5, 15)
c = range(2, 20, 2)
print(list(a))
print(list(b))
print(list(c))
# 用in判断10是否在a中存在
print(10 in a)
print(10 not in a)
