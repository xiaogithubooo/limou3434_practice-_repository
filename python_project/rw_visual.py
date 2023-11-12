import matplotlib.pyplot as plt
from random_walk import RandomWalk

rw = RandomWalk()
rw.fill_walk()

plt.style.use('classic')
fig, ax = plt.subplots()
# ax.scatter(rw.x_value, rw.y_value, s=15)
ax.plot(rw.x_value, rw.y_value)
ax.set_aspect('equal')
plt.show()