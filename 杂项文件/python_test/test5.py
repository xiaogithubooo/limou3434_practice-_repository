alion = {'color': 'red', 'points': 5}
print(alion)
alion['x'] = 2
alion['y'] = 3
print(alion)
alion['color'] = 'green'
print(alion)
del alion['points']
print(alion)

table = {'list': [1, 2, 3], 'tuple': (4, 5, 6), 'dict': {'A': 1 , 'B': 2}}
print(table['list'])
print(table['tuple'])
print(table.get('dict', 'No dict!'))
print(table.get('table', 'No table!'))
print(table)

for k in table:
    print(f'{k}')

#demo 6.1.