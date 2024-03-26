import pygame
from pygame.sprite import Sprite

class Bullet(Sprite):
    """继承了 pygame.sprite 可以为相关元素编组，操控编组内的所有元素"""
    # 精灵是指一个可移动的图像对象，通常用于表示游戏中的角色、物体或特效
    # 精灵可以具有位置、大小、速度、动画等属性，并且可以与其他精灵进行交互
    def __init__(self, ai_game): # 根据 AlienInvasion 类创立子弹实例
        super().__init__()
        # 获取屏幕
        self.screen = ai_game.screen
        # 获取设置
        self.settings = ai_game.settings
        # 获取子弹颜色
        self.color = self.settings.bullet_color
        # 绘制子弹，由于精灵对象不是直接的图像文件，因此需要创建出一个矩形，不然无法直接作为矩形
        self.rect = pygame.Rect(0, 0, self.settings.bullet_width, self.settings.bullet_height)
        # 设置和飞船一样的位置
        self.rect.midtop = ai_game.ship.rect.midtop
        # 存储子弹的位置
        self.y = float(self.rect.y)

    def update(self):
        """向上移动子弹"""
        # 更新子弹的准确位置
        self.y -= self.settings.bullet_speed
        self.rect.y = self.y

    def draw_bullet(self):
        """在屏幕上绘制子弹"""
        pygame.draw.rect(self.screen, self.color, self.rect)


