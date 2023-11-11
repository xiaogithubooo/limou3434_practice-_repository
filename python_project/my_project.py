import matplotlib.pyplot as plt
import random

# 生成随机游走数据
num_steps = 5000
x = [0]  # 起始点为 (0, 0)
y = [0]
for _ in range(num_steps):
    # 在 x 和 y 方向上各随机走一步
    x.append(x[-1] + random.choice([-1, 1]))
    y.append(y[-1] + random.choice([-1, 1]))

# 绘制随机游走图
plt.figure(figsize=(8, 8))
plt.plot(x, y, marker='o', markersize=5, linestyle='-')
plt.title('Random Walk')
plt.xlabel('X')
plt.ylabel('Y')
plt.show()
