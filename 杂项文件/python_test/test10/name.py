from name_function import get_formatted_name

print("Enter 'q' at any time to quit.")
while True:
    first = input("\nPlease give me a first name: ")
    if first == 'q':
        break
    last = input("Please give me a last name: ")
    if last == 'q':
        break

    formated_name = get_formatted_name(first, last)
    print(f"\tNeatly formatted name: {formated_name}.")

# class Car:
#     def __init__(self, make, model, year):
#         self.make = make
#         self.model = model
#         self.year = year
#         self.odmeter_reading = 0
    
#     def get_descriptive_name(self):
#         long_name = f'{self.year} {self.make} {self.model}'
#         return long_name.title()
    
#     def read_odmter(self):
#         print(f'This car has {self.odmeter_reading} miles on it.')

#     def update_odometer(self, mileage):
#         if mileage >= self.odmeter_reading:
#             self.odmeter_reading = mileage
#         else:
#             print("You can't roll back an odometer!")

#     def increment_odometer(self, miles):
#         self.odmeter_reading += miles

# class ElectricCar(Car):
#     def __init__(self, make, model, year):
#         super().__init__(make, model, year)

# my_leaf = ElectricCar('nisan', 'leaf', 2023)
# print(my_leaf.get_descriptive_name())