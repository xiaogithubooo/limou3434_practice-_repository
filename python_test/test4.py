# demo5.1.条件测试（略）

# demo5.2.更多条件测试
str1 = 'limou'
str2 = 'dimou'
str3 = 'limou'
if str1 == str2:
    print('==')
else:
    print('!=')

if str1 == str3:
    print('==')

list = list(range(1, 10, 2))
print(list)
number = 6
if number not in list:
    print(f'无{number}')
else:
    print(f'有{number}')

# demo5.3~5.11.测试代码
print(list)
list = []
tuple = tuple(range(1, 10))
print(tuple)
if tuple:
    print('YES!!!')
else:
    print('NO!!!')

# 额外.python是否存在短路效益（存在）
def function():
    print('call function()')
    return True
i = 1
if i != 1 or function():
    print('NO')
else:
    print('OK')


