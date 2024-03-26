from random import randint

class Die:
    """骰子类"""
    def __init__(self, num_sides=6):
        """设置骰子面数"""
        self.num_sides = num_sides
    
    def roll(self):
        """返回得到面数"""
        return randint(1, self.num_sides)