# demo 4.1.比萨
pizzas = ['beef', 'tomato', 'cheese']
print(pizzas)
for pizza in pizzas : 
    print(f'I like {pizza} pizza')
print('I really lov pizza')

# demo 4.2.动物
animals = ['dog', 'cat', 'bird']
for animal in animals : 
    print(animal, end = ' ')
print()

for animal in animals : 
    print(f'A {animal} would make a great pet.')
print('Any of these animals would make a great pet!')
print('----')

# demo4.3.数列20
nums = list(range(1, 21)) 
for num in nums :
    print(num, end = ' ')
print()

# demo4.4.100万/demo4.5.100万求和
add = 0
nums = list(range(1, 1_000_000 + 1)) 
for num in nums :
    add += num
    # print(num, end = ' ')
print(add)

# demo4.6.奇数
nums = list(range(1, 20, 2))
for num in nums :
    print(num, end = ' ')
print()
print('----')

# demo4.7.3的倍数
nums = list(range(3, 30 + 1))
for num in nums :
    if num % 3 == 0 :
        print(num, end=' ')
print()
print('----')
    
# demo4.8.立方
numbers = []
for num in range(1, 11) :
    numbers.append(num ** 3)
print(numbers)
print('----')

# demo4.9.立方推导式
lists = [num**3 for num in range(1, 11)]
print(lists)
print('----')

# demo4.10.切片
print(len(lists))
print(lists)
print('The first three iterms in the list are:')
print(lists[0:3])
print('Three iterms form the middle of the list are:')
index = len(lists) // 2 - 2
print(lists[index : index + 3])
print('The last three iterms in the list are:')
print(lists[-3:])
print('----')

# demo4.11.你的比萨，我的比萨
print(pizzas)
friend_pizzas = pizzas[:]
pizzas.append('durian')
friend_pizzas.append('chicken')

print('My favoritr pizzas are:', end = ' ')
it = 0
for it in pizzas :
    print(it, end = ' ')
print()

print("My friend's favoritr pizzas are:", end = ' ')
it = 0
for it in friend_pizzas :
    print(it, end = ' ')
print()

print('----')

# demo4.12.使用多个循环
# 前面写过很多了，不再重复书写了 

foods = ('上海青', '小白菜', '包菜', '生菜', '西洋菜')
for food in foods :
    print(food, end = ' ')
# foods[0] = '菜花' # 失败
print()
foods = ('上海青', '小白菜', '包菜', '菜花', '卷心菜')
for food in foods :
    print(food, end = ' ')
print()
print('----')

# demo4.14.PEP 8（略）

# demo4.15.代码审核

# 额外1.测试引用和赋值拷贝的现象
# my_nums = list(range(1, 10))
# he_nums = my_nums
# my_nums[1] = 100
# print(my_nums)
# print(he_nums)
# my_nums.append(1000000)
# print(my_nums)
# print(he_nums)

# 额外2.测试溢出现象
# number = 10 ** 10000000
# print(number)