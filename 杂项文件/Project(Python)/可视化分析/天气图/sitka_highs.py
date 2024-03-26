from pathlib import Path
from datetime import datetime
import matplotlib.pyplot as plt
import csv

# 打开文件读取数据
path = Path('天气图/death_valley_2021_simple.csv') # 获取文件关联
lines = path.read_text().splitlines() # 读取文件并以行为分割存储
reader = csv.reader(lines) # 读取 csv 数据转化为文本并且存储
header_row = next(reader) # 读取一行的文本数据，下一次读取将换行

# 择取并存储各字段
dates, highs, lows = [], [], []
for row in reader:
    try:
        current_date = datetime.strptime(row[2], '%Y-%m-%d') # 获取第 2 列的字段，转化为 date
        high = int(row[4]) # 获取第 4 列的字段，转化为 int
        low = int(row[5])
    except ValueError:
        print(f"Missing data for {current_date}")
    else:
        dates.append(current_date)
        highs.append(high)
        lows.append(low)

# 绘制并显示图表
fig, ax = plt.subplots() # 关联绘图
ax.plot(dates, highs, color='red')
ax.plot(dates, lows, color='blue')
ax.set_title('Table')
ax.set_xlabel('', fontsize=16)
ax.set_ylabel('Temperature(F)', fontsize=16)
ax.tick_params(labelsize=16)
fig.autofmt_xdate() # 设置斜体

# 填充折线间区域
ax.fill_between(dates, highs, lows, facecolor='blue', alpha=0.1)

plt.show()