import pygame
from pygame.sprite import Sprite

urls = [
    "./image/Aircraft1.bmp",
    "./image/Aircraft2.bmp",
    "./image/Aircraft3.bmp"
]

# 飞机类
class Ship(Sprite):
    """管理飞船的类"""
    def __init__(self, ai_game): # ai_game 是 AlienInvasion 的一个实例
        """初始化飞船并且设置初始位置"""
        super().__init__()
        # 导入游戏相关设置        
        self.settings = ai_game.settings
        
        # 得到 AlienInvasion 实例的窗口（返回 surface 对象），并获取屏幕的矩阵属性
        self.screen = ai_game.screen
        self.screen_rect = ai_game.screen.get_rect()

        # 加载飞船图像（返回 surface 对象）
        self.i = 0
        self.image = pygame.image.load(urls[self.i])
        self.image = pygame.transform.scale(self.image, (64, 64)) # 缩放图片
        self.rect = self.image.get_rect() # 获取飞机的矩阵属性
        self.rect.midbottom = self.screen_rect.midbottom # 将游戏对象的矩形框的中下部坐标设置为游戏窗口的中下部坐标，从而使游戏对象位于屏幕底部中央位置 
        
        # 飞船方向标记
        self.moving_right = False
        self.moving_left = False
        self.moving_top = False
        self.moving_bottom = False
        
        # 飞船坐标
        self.x = float(self.rect.x)
        self.y = float(self.rect.y)

    def update(self):
        """根据移动标志调整飞船位置"""
        if self.moving_right and self.rect.right < self.screen_rect.right:
            self.x += self.settings.ship_speed
        elif self.moving_left and self.rect.left > 0:
            self.x -= self.settings.ship_speed
        elif self.moving_top and self.rect.top > 0:
            self.y -= self.settings.ship_speed
        elif self.moving_bottom and self.rect.bottom < self.screen_rect.bottom:
            self.y += self.settings.ship_speed
        
        self.rect.x = self.x
        self.rect.y = self.y

    def blitme(self):
        """在指定位置绘制飞船"""
        self.screen.blit(self.image, self.rect)
        self.i += 1
        self.i %= 3
        self.image = pygame.image.load(urls[self.i])
        self.image = pygame.transform.scale(self.image, (64, 64))

    def center_ship(self):
        """将飞船置于屏幕底部中央"""
        self.rect.midbottom = self.screen_rect.midbottom
        self.x = float(self.rect.x)