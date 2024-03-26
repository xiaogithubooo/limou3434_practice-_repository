import pygame
from pygame.sprite import Sprite

class Alien(Sprite):
    """外星人类"""
    def __init__(self, ai_game):
        super().__init__()
        self.screen = ai_game.screen
        
        # 加载外星人图像并且创建矩阵属性
        self.image = pygame.image.load("./image/UFO.bmp")
        self.image = pygame.transform.scale(self.image, (64, 64)) # 缩放图片

        self.rect = self.image.get_rect()

        # 设置外星人位置，左边距为外星人宽度，上边距为外星人高度
        self.rect.x = self.rect.width 
        self.rect.y = self.rect.height 

        # 记录外星人的水平位置
        self.x = float(self.rect.x)

        # 导入外星人设置
        self.settings = ai_game.settings

    def check_edges(self):
        """检查外星人是否处于边缘"""
        screen_rect = self.screen.get_rect()
        return (self.rect.right >= screen_rect.right) or (self.rect.left <= 0)

    def update(self):
        """更新外星人数据"""
        self.x += self.settings.alien_speed * self.settings.fleet_direction
        self.rect.x = self.x