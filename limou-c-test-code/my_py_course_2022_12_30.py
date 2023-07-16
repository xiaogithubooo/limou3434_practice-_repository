# ljp的python程序
# 自2022/12/20开始学习python
# 预计目标不多能使用python在第三方软件里做视频软件即可
# 本次开发时间： 2022/12/30 16:33
'''
# 1、字典的key重复的情况
d = {'name': '张三', 'name': '李四', 'nni': 3434}
print(d)
# 2、字典的值重复情况
c = {'name1': 'lili', 'name2': 'yaya', 'name3': 'nini'}
print(c)
# 3、字典是无序的只可以通过key来查找，并且key必须是不可变序列
lst = [10, 20, 30, 40, 50]
# a = {lst: 100}
# print(a)
b = {'lst': 200}
print(b)
# 可以看到可变序列lst是不能放入字典作为key的
'''
'''
# 4、内置函数zip()的使用
# 这是两个列表
my_items = ['Fruits', 'Books', 'Others']
my_prices = [9, 78, 56]
a = zip(my_items, my_prices)
print(id(a))
print(type(a))
print(a)
print(list(a))
'''
'''
# 字典生成式
# ①这是两个列表
print()
my_items = ['Fruits', 'Books', 'Others']
my_prices = [9, 78, 56]

# ②这是复合后的字典
a = {x.upper()*3: y**2 for x, y in zip(my_items, my_prices)}
print(a)

# ③如果“key数量”小于“值的数量”
a = ['a', 'b', 'c']
b = [11, 22, 33, 44]
c = {a.upper(): b for a, b in zip(a, b)}
print(c)
# 以少的key列表来复合两个列表

# ④如果“key数量”大于“值的数量”
a = ['d', 'e', 'f', 'g']
b = [55, 66, 77, 88, 99]
c = {a.upper(): b for a, b in zip(a, b)}
print(c)
# 以少的值列表来复合两个列表
'''
