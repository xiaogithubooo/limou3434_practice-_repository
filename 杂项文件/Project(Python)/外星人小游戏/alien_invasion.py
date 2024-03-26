import sys
from time import sleep
import pygame
from settings import Settings
from ship import Ship
from bullet import Bullet
from alien import Alien 
from game_stats import GameStats
from button import Button
from scroeboard import Scoreboard

# 控制类
class AlienInvasion:
     """主要管理游戏资源和行为"""
     # 1.初始化游戏资源
     def __init__(self):
          """初始化游戏，创建资源"""
          # 初始化 pygame
          pygame.init()
        
          # 导入游戏相关设置
          self.settings = Settings()

          # 创建一个显示窗口，传递的是一个元组参数，代表屏幕的像素尺寸。
          # 最后还将窗口赋给类属性 screen，让每一个接口都可以使用窗口（类似于句柄）
          # 赋给 screen 的对象是一个 surface，在 pygame 中 surface 是属于对象的一部分，
          # 该对象主要是显示游戏元素，其中 set_mode() 返回的这个对象代表整个游戏窗口 
          # 激活游戏的动画循环后，每经过一次循环就会重绘这个 surface 对象，显示出变化
          # 小窗模式
          self.screen = pygame.display.set_mode((self.settings.screen_width, self.settings.screen_height))
          # 全屏模式
          # self.screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN) # FULLSCREEN 是全屏的意思，全屏使用 (0, 0) 来自适应当前设备屏幕
          # self.settings.screen_width = self.screen.get_rect().width
          # self.settings.screen_height = self.screen.get_rect().height

          # 设置时钟用来计时
          self.clock = pygame.time.Clock()
          
          # 设置项目标题
          pygame.display.set_caption("Alien Invasion")

          # 创建统计信息对象
          self.stats = GameStats(self)

          # 并创建记分牌
          self.sb = Scoreboard(self)

          # 创建飞船实例对象
          self.ship = Ship(self)
          # 创建子弹实例对象的编组（编组会自动调用每个精灵的 update()）
          self.bullets = pygame.sprite.Group()
          # 创建外星人实例对象编组
          self.aliens = pygame.sprite.Group()
          # 创建外星人舰队
          self._create_fleet()
          
          # 标记游戏是否结束
          self.game_active = False

          # 绘制按钮
          self.play_button = Button(self, "Play")

     def _create_fleet(self):
          """创建外星人舰队"""
          # 创建一个外星人，并且保存一份外星人宽度
          alien = Alien(self)
          alien_width, alien_height = alien.rect.size # 元组传递

          current_x, current_y = alien_width, alien_height
          while current_y < (self.settings.screen_height - 3 * alien_height):
               while current_x < (self.settings.screen_width - 2 * alien_width):
                    self._create_alien(current_x, current_y)
                    current_x += 2 * alien_width
               current_x = alien_width
               current_y += 2 * alien_height
     def _create_alien(self, x_position, y_position):
          new_alien = Alien(self)
          new_alien.x = x_position
          new_alien.rect.x = x_position
          new_alien.rect.y = y_position
          self.aliens.add(new_alien)

     # 2.运行游戏主逻辑
     def run_game(self):
          """开始游戏主题逻辑，处理不同的事件"""
          while True:
               # 处理事件
               self._check_events()

               if self.game_active: # 判断飞船是否用完
                    # 更新飞船
                    self.ship.update()
                    # 更新子弹
                    self._update_bullets()
                    # 更新舰队
                    self._update_aliens()

               # 绘制屏幕
               self._update_screen()
               # 设置帧率
               self.clock.tick(60)

     def _check_events(self):
          """检测 pygame 获取到的键盘和鼠标事件，这个函数会返回一个列表，
          所有的事件都会导致这个循环的运行，在循环内部，会编写一系列 if 语句，
          来对不同的事件进行不同的操作"""
          for event in pygame.event.get(): # 检测到玩家点击窗口的关闭按钮，进而调用 exit() 退出游戏
               if event.type == pygame.QUIT: # 退出
                    sys.exit()
               elif event.type == pygame.KEYDOWN: # 按下
                    self._check_keydown_events(event)
               elif event.type == pygame.KEYUP: # 松开
                    self._check_keyup_events(event)
               elif event.type == pygame.MOUSEBUTTONDOWN:
                    mouse_pos = pygame.mouse.get_pos()
                    self._check_play_button(mouse_pos)

     def _check_keydown_events(self, event):
          if event.key == pygame.K_RIGHT:
               self.ship.moving_right = True
          elif event.key == pygame.K_LEFT:
               self.ship.moving_left = True
          elif event.key == pygame.K_UP:
               self.ship.moving_top = True
          elif event.key == pygame.K_DOWN:
               self.ship.moving_bottom = True
          elif event.key == pygame.K_q or event.key == pygame.K_ESCAPE:
               sys.exit()
          elif event.key == pygame.K_SPACE:
               self._fire_bullet()
     def _check_keyup_events(self, event):
          if event.key == pygame.K_RIGHT:
               self.ship.moving_right = False
          elif event.key == pygame.K_LEFT:
               self.ship.moving_left = False
          elif event.key == pygame.K_UP:
               self.ship.moving_top = False
          elif event.key == pygame.K_DOWN:
               self.ship.moving_bottom = False
     def _check_play_button(self, mouse_pos):
          """在玩家单击 “Play” 按钮时开始游戏"""
          if self.play_button.rect.collidepoint(mouse_pos) and not self.game_active:
               # 还原游戏的设置
               self.settings.initialize_dynamic_settings()

               # 重置游戏的统计信息
               self.stats.reset_stats()
               self.game_active = True
               
               self.sb.prep_score()
               self.sb.prep_level()
               self.sb.prep_ships()

               # 清空外星人列表和子弹列表
               self.bullets.empty()
               self.aliens.empty()

               # 创建一个新的外星舰队，并将飞船放在屏幕底部的中央
               self._create_fleet()
               self.ship.center_ship()

     def _fire_bullet(self):
          """创建子弹，并加入编组"""
          if len(self.bullets) < self.settings.bullet_allowed:
               new_bullet= Bullet(self)
               self.bullets.add(new_bullet)

     def _update_bullets(self):
          # 更新子弹位置
          self.bullets.update()
          # 删除已近消失的子弹
          for bullet in self.bullets.copy(): # copy() 的原因是列表不允许在循环中变化
               if bullet.rect.bottom <= 0:
                    self.bullets.remove(bullet)
          # print(len(self.bullets))
          # 检查是否有子弹射中外星人
          self._check_bullet_alien_collisions()
     def _check_bullet_alien_collisions(self):
          """删除发生碰撞的子弹和外星人"""
          collisions = pygame.sprite.groupcollide(self.bullets, self.aliens, True, True)
          if collisions:
               for aliens in collisions.values():
                    self.stats.score += self.settings.alien_points * len(aliens)
               self.sb.prep_score()
               self.sb.check_high_score()
          if not self.aliens:
               self.bullets.empty()
               self._create_fleet()
               self.settings.increase_speed()

               # 提高等级
               self.stats.level += 1
               self.sb.prep_level()

     def _update_aliens(self):
          self._check_fleet_edges()
          self.aliens.update()
          # 检测外星人和飞船之间的碰撞
          if pygame.sprite.spritecollideany(self.ship, self.aliens):
               self._ship_hit()
          self._check_aliens_bottom()
     def _ship_hit(self):
          """响应飞船和外星人的碰撞"""
          if self.stats.ships_left > 0:
               # 减少飞船的个数
               self.stats.ships_left -= 1
               self.sb.prep_ships()
               # 清空子弹和外星人舰队
               self.bullets.empty()
               self.aliens.empty()
               # 创建新的外星舰队
               self._create_fleet()
               # 将飞船放置到屏幕底部中央
               self.ship.center_ship()
          else:
               self.game_active = False
     def _check_aliens_bottom(self):
          """检查是否有外星人到达了屏幕的下边缘"""
          for alien in self.aliens.sprites():
               if alien.rect.bottom >= self.settings.screen_height:
                    self._ship_hit()
                    break

     def _check_fleet_edges(self):
          """在有外星人到达边缘时采取相应的措施"""
          for alien in self.aliens.sprites():
               if alien.check_edges():
                    self._change_fleet_direction()
                    break
     def _change_fleet_direction(self):
          """将舰队下移，并且改变方向"""
          for alien in self.aliens.sprites():
               alien.rect.y += self.settings.fleet_drop_speed
          self.settings.fleet_direction *= -1

     def _update_screen(self):
          # 填充屏幕颜色
          self.screen.fill(self.settings.bg_color)

          # 绘制飞船图像
          self.ship.blitme()

          # 绘制子弹和外星人编组中的每一个精灵
          for bullet in self.bullets.sprites():
               bullet.draw_bullet()
          self.aliens.draw(self.screen)

          # 显示得分
          self.sb.show_score()

          # 如果游戏处于非活动状态，就绘制 "Play" 按钮
          if not self.game_active:
               self.play_button.draw_button()

          # 立刻更新屏幕（刷新缓存图像）
          pygame.display.flip()

# 运行游戏
if __name__ == '__main__':
     ai = AlienInvasion() # 创建实例
     ai.run_game() # 运行游戏