from pathlib import Path
import plotly.express as px
import json
import pandas as pd

# 将数据作为字符串读取并转为 python 对象
path = Path('散点图/eq_data_30_day_m1.geojson')
try:
    contents = path.read_text()
except:
    contents = path.read_text(encoding='utf-8')

all_eq_data = json.loads(contents)

# 将数据文件转化为跟更易于阅读的版本
# path = Path('散点图/readable_eq_data.geojson')
# readable_contents = json.dumps(all_eq_data, indent=4) # 这里设置缩进
# path.write_text(readable_contents)

# 创建地震列表
all_eq_data = all_eq_data['features'] # 提取字典 'features' 对应的值
# print(len(all_eq_data))

# 提取地址震级、位置顺序
mags, titles, lons, lats = [], [], [], []
for eq_dict in all_eq_data:
    mag = eq_dict['properties']['mag'] ** 10
    title = eq_dict['properties']['title']
    lon = eq_dict['geometry']['coordinates'][0]
    lat = eq_dict['geometry']['coordinates'][1]

    mags.append(mag)
    titles.append(title)
    lons.append(lon)
    lats.append(lat)

# 根据数据绘图
data = pd.DataFrame(
    data=zip(lons, lats, titles, mags),
    columns=['经度', '纬度', '位置', '震级']
) # 封装数据
# data.head() # 类似 Linux 中的 head 指令，只是方便查看前几行字段

fig = px.scatter(
    data,
    x='经度',
    y='纬度',
    range_x=[-200, 200],
    range_y=[-90, 90],
    width=800,
    height=800,
    title='全球地震散点图',
    size='震级',
    size_max=60,
    color='震级',
    hover_name='位置',
)

fig.show()

