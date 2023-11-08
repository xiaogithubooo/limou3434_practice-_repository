# demo2.1.简单信息
message = "This a message"
print(message)

# demo2.2.多条简单信息
message = "This a message too"
print(message)

# demo2.3.个性化信息
name = "limou"
print(f"Hello {name}, would you like to learn some Python today?")

# demo2.4.调整名字的大小写
print(name.lower())# 全小写
print(name.upper())# 全大写
print(name.title())# 首字母大写

# demo2.5.名言1
print('Albert Einstein once said, "A person who never made a mistake never tried anything new."')

# demo2.6.名言2
famous_person = 'Albert Einstein'
message = '"A person who never made a mistake never tried anything new."'
print(f"{famous_person} once said, {message}")

# demo2.7.删除人名中的空白
name = "   \tlimou3434\n  "
print(name)
print(name.lstrip())
print(name.rstrip())
print(name.strip())

# demo2.8.文件拓展名
filename = 'python_notes.txt'
filename = filename.removesuffix('.txt')
print(filename)

# demo2.9.数字8
number1, number2 = 3, 5
print(number1 + number2)

number1, number2 = 1_00_08, 1_0000
print(number1 - number2)

number1, number2 = 2, 4
print(number1 * number2)

number1, number2 = 24, 3
print(number1 / number2)

# demo2.10.最喜欢的数
number = 9
print('I love ' + f"{number}")

# demo2.11.添加注释
# Hello, I am limou3434.

# demo2.12.Python之禅
import this