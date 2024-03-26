# 设置类
class Settings:
    """将游戏的相关设置都交由该类控制"""
    def __init__(self):
        """游戏设置"""
        # 屏幕参数
        self.screen_width = 500
        self.screen_height = 500
        self.bg_color = (230, 230, 230)
        
        # 飞船参数
        self.ship_speed = 5 # 飞船速度
        self.ship_limit = 3 # 飞船个数

        # 子弹参数
        self.bullet_speed = 6.0 # 子弹速度
        self.bullet_width = 5 # 子弹宽度
        self.bullet_height = 15 # 子弹高度
        self.bullet_color = (60, 60, 60) # 子弹颜色
        self.bullet_allowed = 8 # 子弹允许数量

        # 外星人参数
        self.alien_speed = 5.0
        self.fleet_drop_speed = 10
        self.fleet_direction = 1

        # 以什么样的速度加快游戏节奏
        self.speedup_scale = 1.5
        # 以什么样的速度调高加分
        self.score_scale = 1.5
        # 初始化会变化的属性
        self.initialize_dynamic_settings() 

    def initialize_dynamic_settings(self):
        """初始化随着游戏进行而变化的设置"""
        self.ship_speed = 1.5
        self.bullet_speed = 2.5
        self.alien_speed = 1.0
        self.fleet_direction = 1
        self.alien_points = 50 # 击落一个时的记分

    def increase_speed(self):
        """提高速度设置的值和外星人击落分数"""
        self.ship_speed *= self.speedup_scale
        self.bullet_speed *= self.speedup_scale
        self.alien_speed *= self.speedup_scale
        self.alien_points = int(self.alien_points * self.score_scale)
        print(self.alien_points)
