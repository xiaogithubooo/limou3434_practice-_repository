import requests
import plotly.express as px

# 用户输入语言
language = input("输入想要查询的语言项目:")

language_to_table_color = {
    "java": "red",
    "c++": "blue",
    "python": "purple",
    "php": "yellow",
    "go": "black",
    "ruby": "green",
}

# API 调用方式
url = 'https://api.github.com/search/repositories'
url += f'?q=language:{language}' # 搜索项目
url += '+sort:stars'        # 以 stars 排序
url += '+stars:>10000'       # 只搜索 stars 数量在 10000 以上的项目

# API 调用返回
headers = {'Accept': 'application/vnd.github.v3+json'} # 指定头文件，要求使用 v3 版本，并且返回 JSON 的结果
r = requests.get(url, headers=headers)  # 使用 requests 调用 API
sup = requests.get('https://api.github.com/rate_limit', headers=headers)

print(f'Status code: {r.status_code} and {sup.status_code}')  # 返回退出码查看是否调用成功

# API 结果处理
response_dict = r.json()
monitor_dict = sup.json()

# API 数据分析

# 输出数据包含的字段“total_count总数”、“incomplete_results不完整结果”、“item项目”
print(f'数据包含字段:{response_dict.keys()}')
print(f"检索符合条件仓库数:{response_dict['total_count']}") # API 调用返回多少个库（满足条件的库）
print(f"是否有足够时间处理:{not response_dict['incomplete_results']}") # 输出是否在调用期间处理完毕
print(f"可用于分析的仓库数:{len(response_dict['items'])}") # Python 项目的具体信息（默认只返回前 30 个，若需获取更多仓库，可以请求额外的数据页）
print(f"剩余可调用次数:{monitor_dict['resources']['search']['remaining']}")

# 绘制所有仓库关键信息图（仓库名字、拥有者及其登录名、项目星星数、项目URL、创建时间、最后更新时间、仓库描述）
repo_dicts = response_dict['items']
repo_names, repo_stars, repo_hover_texts = [], [], []
for repo_dict in repo_dicts:
    # 关键对应关系
    repo_names.append(f"<a href='{repo_dict['html_url']}'>{repo_dict['name']}</a>")
    repo_stars.append(repo_dict['stargazers_count'])
    # 悬浮文本信息
    repo_hover_texts.append(f"{repo_dict['owner']['login']}<br />{repo_dict['description']}")

# 绘制可视化图像
title = f"Most-Starred-{language}-Projects on Github"
labels = {'x': 'Repository', 'y': 'Stars'}
fig = px.bar(x=repo_names,
             y=repo_stars,
             title=title,
             labels=labels,
             hover_name=repo_hover_texts)
fig.update_layout(title_font_size=28,
                  xaxis_title_font_size=20,
                  yaxis_title_font_size=20)
fig.update_traces(marker_color=f'{language_to_table_color.get(language, f"No {language} value assigned.")}',
                  marker_opacity=0.6)
fig.show()

# 补充：下面代码可以仓库的关键字信息
# repo_dict = response_dict['items'][0]
# print(len(repo_dict)) # 查看一个仓库内具有的关键字数量
# for key in sorted(repo_dict):
#     """输出仓库内的关键字"""
#     print(key)