# 1、尝试使用python的打印函数
print('hello word')
print('Py\nthon')
print(' ')
print('hello\tworld')
print('helloooo\tworld')
print('\a')

# 2、尝试python的转义字符
print('http:\\\\www.baidu.com')
print('我说\"您好！\"')
# 不希望字符串中的转义字符起作用可以在字符串最前面加上r或者R
print(r'我说\"您好！\"')
# 因此就可以将上面的语句改成如下语句
print(r'我说：“您好”\\')

# 3、尝试python的打开文件函数
# fp = open('C:/Users/DELL/Desktop/py_测试', 'a+')
# print('hello', file=fp)
# fp.close()

# 4、尝试输出一个字符集内的汉字
print(chr(0b100111001011000))

# 5、就可以看到保留字的具体有哪些
import keyword
print(keyword.kwlist)

# 6、变量的使用
num = 234
print(id(num))  # 获取内存地址
print(type(num))  # 获取类型
print(num)  # 获取值


