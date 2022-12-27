# ljp的python程序
# 自2022/12/20开始学习python
# 预计目标不多能使用python在第三方软件里做视频软件即可
# 本次开发时间： 2022/12/27 11:01
'''
# 1、while循环语句
a = 1
while a < 10:
    print(a)
    a += 1
'''
'''
# 2、while循环语句计算0到4的和
a = 0
sum = 0
# sum为什么会出现黄线呢？？？
while a <= 4:
    sum += a
    a += 1
print(sum)
'''
'''
# 3、while循环语句：计算1-100之间的偶数和
a = 1
my_sum = 0
while a <= 100:
    if a % 2 == 0:
        my_sum += a
    a += 1
print(my_sum)
'''
'''
# 4、for-in循环
for item in 'Python':
    print(item)
print('\n')
# 取出来每一个字符，肤质给了item
# in后面必须是可迭代对象
for a in range(2, 10, 1):
    print(a)
print('\n')
# 用for循环计算1-100之间的偶数和
a = 1
my_sum_1 = 0
# 循环100次
for _ in range(0, 100, 1):
    if a % 2 == 0:
        my_sum_1 += a
    a += 1
print(my_sum_1)
'''
'''
# 5、for-in（100·999）水仙化数的要求
for a in range(100, 1000, 1):
    ge = a % 10
    shi = a // 10 % 10
    bai = a // 100
    # print(bai, shi, ge)
    # 判断
    if ge**3+shi**3+bai**3==a:
        print('水仙花数：', a)
# 输出的就是水仙花数
'''
'''
# 6、流程控制语句，密码输入
for a in range(3):
    pwd = input('请输密码（3次以内）')
    if pwd == '8888':
        print('密码正确')
        break
    else:
        print('密码输入不正确', a+1, '次')
    if a == 2:
        print('--请稍后再尝试密码--')
'''
'''
# 7、使用continue来找出5的倍速
for item in range(1, 51):
    if item % 5 != 0:
        continue
    print(item)
'''
'''
# 8、else语句的python特性
for a in range(3):
    pwd = input('请输密码（3次以内）')
    if pwd == '8888':
        print('密码正确')
        break
    else:
        print('密码输入不正确', a+1, '次')
# 下面这个else只会在循环不遇到break时候执行
else:
    print('--三次输入错误，请稍后再尝试密码--')
print('\n')
'''
'''
# 9、实验循环中的else
for a in range(3):
    print(a)
else:
    print('hahaha')
# 可以看到hahaha还是会被打印出来的，千万别理解成“循环就打印，而不循环就不打印”
'''
'''
# 10、嵌套循环打印3*4的”*矩形“
for i in range(1, 4):
    for j in range(1, 5):
        print('*', end='\t')
    # 下面的print是为了打印行数
    print()
# 利用双循环就可以打印出3*4的”*矩形“
'''
'''
# 11、输出一个九九乘法表
for i in range(1, 10):
    for j in range(1, i+1):
        print(j, '*', i, '=', i*j, end='\t')
    # 注意print本身可以当作换行来用
    print()
'''
'''
# 12、实验print('\n')和print()是否有区别
print('***********')
print('\n')
print('***********')
print()
print('***********')
# 可以看到多了一行换行，这说明python的内置函数print本身自带换行符号，可以通过end来取消
'''
'''
# 13、用方括号列表的使用
# 一个变量
a = 10
# 一个列表
a = ['hello', 'world', 98]
print(id(a))
print(type(a))
print(a)
'''
'''
# 14、创建列表的内置函数
a = list(['hello', 'world'])
print(id(a))
print(type(a))
'''
'''
# 15、列表的索引（两种）
a = list(['hello', 2, 3.2])
print(a[0])
print(a[-1])
'''
'''
# 16、获取索引函数
lst = ['hello', 'world', 98]
print(lst.index(98))
print(lst.index(98, 0, 3))
# 可以看到输出了索引2，正好是98的位置
'''