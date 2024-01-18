def function(number):
    try:
        return 10 / number
    except ZeroDivisionError:
        print("Error: Incalid argument")

print(function(10))
print(function(3))
print(function(0))
print(function(1))