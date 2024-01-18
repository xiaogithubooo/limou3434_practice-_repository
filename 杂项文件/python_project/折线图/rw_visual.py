import matplotlib.pyplot as plt
from random_walk import RandomWalk

rw = RandomWalk()
rw.fill_walk()

# 绘制随机图
plt.style.use('classic')
fig, ax = plt.subplots(figsize=(9, 9))
point_number = range(rw.num_points)
ax.scatter(rw.x_value, rw.y_value, c=point_number, cmap=plt.cm.Blues, edgecolors='none', s=15)
ax.set_aspect('equal')

# 绘制起点和终点
ax.scatter(0, 0, c='green', edgecolor='none', s=100)
ax.scatter(rw.x_value[-1], rw.y_value[-1], c='red', edgecolor='none', s=100)

# 隐藏坐标轴
ax.get_xaxis().set_visible(False)
ax.get_yaxis().set_visible(False)

# 改变窗口适应屏幕


# 显示绘图
plt.show()