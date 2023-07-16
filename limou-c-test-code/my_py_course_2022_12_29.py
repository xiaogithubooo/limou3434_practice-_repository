# ljp的python程序
# 自2022/12/20开始学习python
# 预计目标不多能使用python在第三方软件里做视频软件即可
# 本次开发时间： 2022/12/29 9:58
'''
# 1、字典的创建
# ①花括号
a = {'张三': 10, '李四': 'jkj', 'limo': 45}
print(a)
print(type(a))
print(id(a))
print()
# ②内置函数dict()
b = dict(name='jack', age=20)
print(b)
print(type(b))
print(id(b))
print()
'''
'''
# 2、字典的元素查找
a = {'张三': 10, '李四': 'jkj', 'limo': 45}
b = dict(name='jack', age=20)
print(a)
print(a['张三'])
# print(a['李某'])

print(b)
print(b.get('name'))
# print(b.get('李某'))只返回None
# print(b.get('李某', 10000))而10000就是查找key时不到值时默认值
'''
'''
# 3、字典key的判断
a = {'张三': 10, '李四': 'jkj', 'limo': 45}
print('李四' in a)
print('李四' not in a)
'''
'''
# 4、字典的增、删、改
# ①字典的删除
a = {'张三': 10, '李四': 'jkj', 'limo': 45}
print(a)
del a['张三']
print(a)
a.clear()
print(a)
print()
# ②字典的增加
a = {'张三': 10, '李四': 'jkj', 'limo': 45}
print(a)
a['lili'] = 999
print(a)
# 叁字典的修改
a['lili'] = 1000
print(a)
print()
'''
'''
# 5、字典的视图和转化
a = {'张三': 10, '李四': 'jkj', 'limo': 45}
print(a)
print(type(a))
# ①获取键视图
my_keys = a.keys()
print(my_keys)
print(type(my_keys), end='\n\n')

# ②获取值视图
my_values = a.values()
print(my_values)
print(type(my_values), end='\n\n')

# ③获取键值对
my_items = a.items()
print(my_items)
print(type(my_items), end='\n\n')
# 其中上面的结果有元组的存在

print('“键”转化为列表', list(my_keys))
print('“值”转化为列表', list(my_values))
'''
'''
# ６、字典的遍历
a = {'张三': 10, '李四': 'jkj', 'limo': 45}
print(a)
for b in a:
    print(b, a[b], a.get(b))
'''
