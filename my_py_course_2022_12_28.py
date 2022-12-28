# ljp的python程序
# 自2022/12/20开始学习python
# 预计目标不多能使用python在第三方软件里做视频软件即可
# 本次开发时间： 2022/12/28 15:42

'''
# 1、列表的性质
lst_1 = [10, 20, 30, 40, 50, 60, 70, 80]
# start = 1, stop=6, step=1
lst_2 = lst_1[1: 6: 1]
# 理解成将列表切出一部分（从下标1开始到下标6（不计算6），步长为1）
print('\t原列', id(lst_1))
print('\t', lst_1)
print('\t切片', id(lst_2))
print('\t', lst_2)
# 可以看到两个列表的id发生了改变，所以新的切片本质也是列表
'''
'''
# 2、步长不为1的情况
lst_1 = [10, 20, 30, 40, 50, 60, 70, 80]
lst_2 = lst_1[2: 6: 2]
# 从下标2开始，一直到6（不计算6），步长为2
print(lst_2)
# [30, 50]
'''
'''
# 3、省略切片的参数
lst = [10, 20, 30, 40, 50, 60, 70, 80]
# 下标为1开始，到下标为6（不算6），步长为2
# ==>[20,40,60]
print(lst[1:6:2])

# 下标为1开始，到下标为6（不算6），步长默认为1
# ==>[20,30,40,50,60]
print(lst[1:6:])

# 下标从1开始，到末尾最后一个元素结束结束（算），步长为2
# ==>[20,40,60,80]
print(lst[1::2])

# 下标从第一个元素开始，到下标为6（不算6），步长为2
# ==>[10,30,50]
print(lst[:6:2])
'''
'''
# 4、当参数全省略时
lst = [1, 2, 3, 4, 5, 6, 7]
print(lst)
print(lst[::])
# 可以看到列表原样输出了
'''
'''
# 5、负数的情况
lst = [1, 2, 3, 4, 5, 6, 7]
# 反过来输出了
print(lst[::-1])
print(lst[-1:-6:-1])
'''
'''
# 6、列表元素的判断
lst = [10, 20, 'word']
print(10 in lst)
print(10 not in lst)
'''
'''
# 7、列表的遍历
lst = [10, 20, 30, 40]
for a in lst:
    print(a)
'''
'''
# 8、列表的添加操作
# ①append的使用
lst_1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
print(lst_1, end='')
print(id(lst_1))
lst_1.append(100)
print(lst_1, end='')
print(id(lst_1))
print()
# ②extend的使用
lie_2 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
lit_3 = ['hello', 'word']
print(lie_2, end='')
print(id(lie_2))
lie_2.extend(lit_3)
print(lie_2, end='')
print(id(lie_2))
print()
# 可以看到对列表操作后id没有发生变化
# 另外，哪怕两个列表的值和是一样的，id也不同
# ③insert的使用
c = [1, 2, 3]
print(c)
c.insert(1, 100)
print(c)
print()
# ④利用切片在任意位置上添加多个元素
ls_1 = [True, False, 'hello']
ls_2 = [1, 2, 3]
print(ls_1)
ls_1[1::] = ls_2
print(ls_1)
print()
'''
'''
# 9、可append以将一个列表作为一个元素添加进去
a = [10, 20, 30]
b = ['a', 'b']
print(a)
a.append(b)
print(a)
'''
'''
# 10、列表的删除操作
a = [10, 20, 30, 10, 10, 30]
b = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print(a)
print()

# ①使用remove函数删除
a.remove(10)
print(a)
print()
# 可以看出移除了重复10中的第一个
# a.remove(100) # 则会抛出错误

# ②使用pop删除指定索引或最后一个元素
a.pop(1)
print(a)
print()

a.pop()
print(a)
print()

# ④切片操作删除
print(b)
new_b = b[1:3:1]
print('切片后产生新的列表（截取法）:', new_b)
# print(b) # 这里说明切片对原列表是没有影响的
# 不产生新的列表，而是真实的删除
b[1:3:1] = []
print('切片后不产新的列表（替代法）:', b)
print()

# ⑤清除列表所有元素clear函数
b.clear()
print(b)
print()

# ⑥删除列表del函数
del b
print(b)
print()
'''
'''
# 11、列表元素的修改操作
lst = [10, 20, 30, 40]
# 为指定索引元素赋予一个新值
print(lst)
lst[2] = 100
print(lst)
print()
# 为指定的切片赋予一个新值
lst[1:3] = [300, 400, 500, 600]
print(lst)
'''
'''
# 12、列表元素的排序操作
# ①写法一
a = [40, 34, 1, 3, 50, 100, 56]
print('排序前的列表', a, id(a))
a.sort()
print('排序后的顺序列表', a, id(a))
a.sort(reverse=True)
print('排序后的逆序列表', a, id(a))
# 由此可以看出是在原列表上进行排序的
# 注意：顺序是可以使用reverse=False的，只不过这个函数默认顺序
print()
# ②写法二
b = [100, 34, 4, 50, 9]
print('排序前的列表', b, id(b))
new_b = sorted(b)
print('排序后的顺序列表', new_b, id(new_b))
new_b = sorted(b, reverse=True)
print('排序后的逆序列表', new_b, id(new_b))
'''
'''
# 13、列表生成式
a = [i**2 for i in range(1, 10)]
print(a)
# i**2就是根据i的值产生了“f(i)结果值”
'''