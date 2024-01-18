# ljp的python程序
# 自2022/12/20开始学习python
# 预计目标不多能使用python在第三方软件里做视频软件即可
# 本次开发时间： 2022/12/31 11:17
# # 1、可变序列：列表、字典
# # 列表操作后没有改变地址
# a = [1, 2, 3, 4]
# print(a, id(a))
# a.append(5)
# print(a, id(a))
# # 可以看到id值没有变化，字典操作后同理
#
# # 2、不可变序列：字符串、元组
# b = 'hello'
# print(b, id(a))
# b = b + ' world'
# print(b, id(b))
# # 可以看到表面上虽然是更改了，但是实际上却是换了另外一个变量

# # # 3、元组的创建
# # a = ('hehe', 99, 'str')
# # print(a, id(a), type(a))
# # b = tuple(('python', 's', 2, 4))
#
# # 4、单个元素的元组创建误区
# print(b, id(b), type(b))
# c = ('s')
# print(c, id(c), type(c))
# d = ('s', )
# print(d, id(d), type(d))

# # 5、空列表、空字典、空元组
# a = []
# a1 = list()
# print(a, type(a))
# b = {}
# b1 = dict()
# print(b, type(b))
# c = ()
# c1 = tuple()
# print(c, type(c))

# # 6、元组内部嵌套列表（不可变序列嵌套可变序列）
# y = (10, [20, 30], 9)
# print(y, type(y), id(y), end='\n\n')
#
# print(y[0], type(y[0]), id(y[0]))
# print(y[1], type(y[1]), id(y[1]))
# print(y[2], type(y[2]), id(y[2]), end='\n\n')
#
# # 可以看到这句话就会报错 y[0] = 100
# # 这句话也同样报错 y[1] = 100
#
# y[1].append(40)
# print(y, type(y), id(y), end='\n\n')
# print(y[0], type(y[0]), id(y[0]))
# print(y[1], type(y[1]), id(y[1]))
# print(y[2], type(y[2]), id(y[2]), end='\n\n')
# # 可以观察到列表的id没有改变，元组的id也没有变化

# # 7、元组的遍历
# # 创建一个元组
# t = tuple((0, 1, 3))
# for x in t:
#     print(x)
# print()

# # 8、集合的创建
# t = {'name', 8, 'limo'}
# print(t)
# T = {1, 2, 3, 4, 4, 5}
# print(T)
# # 可以看到去掉了一个重复的元素

# # 9、内置函数set()的使用
# # 整数序列转化为集合
# s = set(range(6))
# print(s)
#
# # 列表转化为集合
# print(set([3, 4, 55, 4]))
# # 元组转化为集合
# print(set((1, 2, 3, 43, 100, 33)))
# # 集合转化为集合
# print(set({'name', 'char', 3}))
# # 字符串序列转化为集合
# print(set('python'))
# 可以看出集合中的元素是无序、互异的

# # 10、定义空集合
# # ①尝试直接用{}定义一个集合
# s = {}
# print(s, type(s))
# # 会发现是一个字典类型而不是集合类型
#
# # ②用set()定义一个空白集合
# L = set()
# print(L, type(L))

# # 11、集合的操作
# A = {'break', 'word', 3, 4, 5}
# print(A)
# # (1)判断操作in或者not in
# print('break' in A)
# print('break' not in A, end='\n\n')
# # (2)集合元素的增加操作
# # ①使用add函数
# A.add(7)
# print(A)
# # ②使用update函数
# A.update({800, 900})
# A.update((1000, 2000))
# A.update([50000, 60000])
# A.update(range(0, 3))
# print(A)
# # (3)集合元素的删除操作
# # ①使用remove函数
# A.remove('word')
# # A.remove('ADD')  # 抛出错误KeyError
# print(A)
# # ②使用discard函数
# # A.discard('break')  # 没有抛出错误
# # A.discard('ADD')
# print(A)
# # ③使用pop函数，任意删除
# A.pop()
# A.pop()
# print(A)
# # ④使用clear函数清空
# A.clear()
# print(A)

# # 12、集合之间的关系
# a = {10, 20, 30, 40, 50}
# b = {20, 40, 30, 50, 10}
# c = {20, 40, 50}
# d = {30, 1, 2, 3}
# # ①相等与不相等
# print(a == b)
# print(a != c)
# print(a == c)
# # ②子集关系
# print(c.issubset(a))
# print(c.issubset(b))
# # ③超集关系
# print(a.issuperset(c))
# print(b.issuperset(c))
# print(a.issuperset(b))
# print(b.issuperset(a))
# # 注意相等也是超集关系
# # ④交集关系
# print(a.isdisjoint(d))
# # False表示有交集
# # True表示没有交集
# print(a.isdisjoint(a))

# # 13、集合的数学操作
# a = {10, 20, 30, 40, 50}
# b = {20, 40, 30, 50, 10}
# c = {20, 40, 50}
# d = {30, 1, 2, 3}
# e = {20, 100, 300, 3, 40}
# # ①交集
# print(c.intersection(e))
# print(c & e)
# # ②并集
# print(c.union(d))
# print(c | d)
# # ③差集
# print(a.difference(c))
# print(a - c)
# # ④对称差集
# print(d.symmetric_difference(e))
# print(d ^ e)

# # 14、集合生成式
# # 对比列表生成式[i**2 for i in range(1, 10)]
# a = {i**2 for i in range(1, 10)}
# print(a, type(a))
