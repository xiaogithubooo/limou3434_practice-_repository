# ljp的python程序
# 自2022/12/20开始学习python
# 预计目标不多能使用python在第三方软件里做视频软件即可
# 本次开发时间： 2022/12/24 10:39

# 1、注释的方法
# 注释①，用#注释
# 注释②，用三引号注释
# 注释③，在开头注释编码方式，可以改变.py文件的字符集（语法格式为 #coding：gdk）
''' 据说python对于换行和空格什么的颇为严谨？ '''

# 2、交互输入函数input的使用
num = input('你好，您叫什么名字呢？')
print('您好，', num, '很高兴认识你')

# 3、类型转化函数的使用（写法一）
a = input('请输入一个加数')
a = int(a)
b = input('请输入另一个加数')
b = int(b)
print(type(a), type(b))
print(a+b)

# 4、类型转化函数的使用（写法二）
a = int(input('请输入一个加数'))
b = int(input('请在输入一个被加数'))
print(a, '+', b, '=', a+b, '\n')

# 5、python中的运算符
print(1 + 2)
print(1 - 2)
print(1 * 2)
print(1 / 2)
print(1 // 2)
print(1 % 2)
print(2 ** 3)
# 这个//是取整符号，在python中除法/是完整的
# **是幂运算，2**3就是2*2*2=8

# 6、取余与整除的负数情况
print('\n')
print(2 % -3)
print(2 % 3)
print(-2 % 3)

print(11 // -2)
print(-11 // 2)
print(11 // 2)

# 7、赋值运算符的链式赋值
a = b = c = 20
print('链式赋值后a、b、c各种的值为')
print(a, b, c)

# 8、参数赋值
a = 10
a += 30
print('这个a赋值后的最后结果=', a)

# 9、系列解包赋值操作（一一对应）
a, b, c, d = 1, 2, 3, 4
print('复制后abcd的值为', a, b, c, d)

# 10、交换函数的python写法
a, b = 5, 3
print('交换前', 'a=', a, 'b=', b)
a, b = b, a
print('交换后', 'a=', a, 'b=', b)

# 11、两种判断相等的结果
a = 1
b = 1
print(a == b)
print(a is b)
lst1 = [11, 22, 33, 44]
lst2 = [11, 22, 33, 44]
print(lst1 == lst2)
print(lst1 is lst2)

# 12、in的使用
s = 'abcdf'
print('w' in s)
print('d' in s)
