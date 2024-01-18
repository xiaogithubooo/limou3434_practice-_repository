import plotly.express as px
from die import Die

# 创建两颗骰子
die1 = Die()
die2 = Die()

# 存储投掷结果
results = []
for roll_num in range(10000):
    result = die1.roll() + die2.roll()
    results.append(result)

# 统计投掷频数
frequencies = []
max_result = die1.num_sides + die2.num_sides
poss_results = range(2, max_result+1)
for value in poss_results:
    frequencies.append(results.count(value))

# 输出可视网页
title = "This a table"
labels = {'x': 'input', 'y': 'output'}
fig = px.bar(x=poss_results, y=frequencies, title=title, labels=labels)
fig.update_layout(xaxis_dtick=1)
fig.show()