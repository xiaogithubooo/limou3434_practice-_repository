import random
import time
import copy
import pygame
import sys

# 设置宽度和长度
WIDTH = 30
HEIGHT = 30

# 设置每个细胞方块的大小
CELL_SIZE = 20

# 设置屏幕的宽度和高度
SCREEN_WIDTH = WIDTH * CELL_SIZE
SCREEN_HEIGHT = HEIGHT * CELL_SIZE

# 初始化 pygame
pygame.init()
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))

# 创建并初始化列表
nextCells = []
for x in range(WIDTH):
    column = []
    for y in range(HEIGHT):
        if random.randint(0, 1) == 0:
            column.append('O')
        else:
            column.append(' ')
    nextCells.append(column)

# 生存游戏循环逻辑
while True:
    # 清空屏幕
    screen.fill((0, 0, 0))
    
    # 拷贝游戏列表，包括内部列表
    currentCells = copy.deepcopy(nextCells)

    # 绘制细胞方块
    for y in range(HEIGHT):
        for x in range(WIDTH):
            cell = currentCells[x][y]
            cell_rect = pygame.Rect(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE)
            if cell == 'O':
                pygame.draw.rect(screen, (255, 255, 255), cell_rect)
    
    # 刷新屏幕显示
    pygame.display.update()

    # 处理事件
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # 判断每一个细胞查看是否存活
    for x in range(WIDTH):
        for y in range(HEIGHT):
            leftCoord = (x - 1) % WIDTH
            rightCoord = (x + 1) % WIDTH
            aboveCoord = (y - 1) % HEIGHT
            belowCoord = (y + 1) % HEIGHT

            numNeighbors = 0

            if currentCells[leftCoord][aboveCoord] == 'O':
                numNeighbors += 1
            if currentCells[x][aboveCoord] == 'O':
                numNeighbors += 1
            if currentCells[rightCoord][aboveCoord] == 'O':
                numNeighbors += 1
            if currentCells[leftCoord][y] == 'O':
                numNeighbors += 1

            if currentCells[rightCoord][y] == 'O':
                numNeighbors += 1
            if currentCells[leftCoord][belowCoord] == 'O':
                numNeighbors += 1
            if currentCells[x][belowCoord] == 'O':
                numNeighbors += 1
            if currentCells[rightCoord][belowCoord] == 'O':
                numNeighbors += 1

            if currentCells[x][y] == 'O' and (numNeighbors == 2 or numNeighbors == 3):
                nextCells[x][y] = 'O'
            elif currentCells[x][y] == ' ' and numNeighbors == 3:
                nextCells[x][y] = 'O'
            else:
                nextCells[x][y] = ' '

    # 设置适当的延迟
    time.sleep(0.1)
