# demo3.1.姓名
names = ['limou', 'dimou', 'eimou', 'rimou']
i = 0
while i < 4 :
    print(names[i].title())
    i += 1

# demo3.2.问候语
i = 0
while i < 4 :
    print(f"Hell, {names[i]}!")
    i += 1

# demo3.3.自己的列表
tools = ['BMW', 'Ferrari', 'Dongfeng Nissan', 'Handa motorcycle']
i = 1
while i < 4 :
    print(f'I would like to own a {tools[i]}')
    i += 1
print('----')

# demo3.4.嘉宾名单
names = []
names.append('Dimou3434')
names.append('Limou3434')
names.append('Eimou3434')
i = 0
while i < 3 :
    print(f'To {names[i]} Invite everyone to dinner.')
    i += 1
print('----')

# demo3.5.修改嘉宾名单
name = 'Limou3434'
names.remove('Limou3434')
names.append('Gimou3434')
i = 0
while i < 3 :
    print(f'To {names[i]} Invite everyone to dinner.')
    i += 1
print('----')

# demo3.6.添加嘉宾
names.insert(0, 'Iimou3434')
names.insert(len(names) // 2, 'Yimou3434')
names.append('Fimou3434')
i = 0
while i < len(names) :
    print(f'To {names[i]} Invite everyone to dinner.')
    i += 1
print('----')

# demo3.7.缩短名单
while 2 != len(names) :
    name = names.pop()
    print(f"{name}, I'm sorry to disturb you...")

i = 0
while i < len(names) :
    print(f'{names[i]}, welcome!')
    i += 1
print('----')

# demo3.8.放眼世界
places = ['shanghai', 'guangzhou', 'beijin', 'chongqing', 'neimenggu']
print(places)
print(sorted(places))
print(places)
places.reverse()
print(places)
places.reverse()
print(places)
places.sort()
print(places)
places.sort(reverse=True)
print(places)

# demo3.9.晚餐嘉宾
print(len(names))

# demo3.10.尝试使用各个函数
# 都完成了，就是上面的东西

# demo3.11.有意引发错误
#     print(names[3])
#           ~~~~~^^^
# IndexError: list index out of range