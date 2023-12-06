#include "snake.hpp"

//初始化窗口
void GameInit()
{
	srand((unsigned)time(NULL));							//设置伪随机数

	initgraph(WINDOW_LENGTH, WINDOW_WIDTH, EX_SHOWCONSOLE);	//创建一个窗体
	setbkcolor(WINDOW_COLOUR);								//背景颜色属性
	cleardevice();											//刷新背景颜色

	//默认逻辑坐标原点和物理坐标原点重叠，这里只是占位提示用的注释
}

//绘制网格
void PrintGrid()
{
	for (int x = 0; x <= 800; x += NODE_WIDTH)
	{
		line(x, 0, x, 600);
	}
	for (int y = 0; y <= 600; y += NODE_WIDTH)
	{
		line(0, y, 800, y);
	}
}

//更新蛇坐标
node SnakeMove(node* snake, int snakeLength, direction dir)
{
	//记录下蛇的尾部节点坐标
	node tail = snake[snakeLength - 1];

	//将每个前面的节点覆盖掉后面的节点
	for (int i = snakeLength - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];
	}

	//蛇头节点根据方向进行重定义坐标
	node newHead;
	newHead = snake[0];
	if (dir == eUp)
	{
		newHead.y--;
	}
	else if (dir == eDown)
	{
		newHead.y++;
	}
	else if (dir == eLeft)
	{
		newHead.x--;
	}
	else if (dir == eRight)
	{
		newHead.x++;
	}
	snake[0] = newHead;

	return tail;//返回蛇最尾部节点坐标，方便吃掉食物后不删除尾部节点坐标
}

//绘制蛇
void PrintSnake(node* snake, int snakeLength)
{
	//某一段蛇节点的左上、右下坐标
	int left, top;
	int right, bottom;

	//遍历蛇结点的每一个结点
	for (int i = 0; i < snakeLength; i++)
	{
		//绘制蛇的某个节点
		left = snake[i].x * NODE_WIDTH;
		top = snake[i].y * NODE_WIDTH;

		right = (snake[i].x + 1) * NODE_WIDTH;
		bottom = (snake[i].y + 1) * NODE_WIDTH;

		if(i == 0)	setfillcolor(SNAKE_HEAD_COLOUR);
		fillrectangle(left, top, right, bottom);
		
		setfillcolor(SNAKE_BODY_COLOUR);
	}
	setfillcolor(WHITE);
}

//检查输入方向
void ChangeDirection(enum direction* pD)
{
	if (_kbhit() != 0)//检查控制台窗口的按键是否被按下，按下返回非零值
	{
		char signal = _getch();	//输入 a、s、d、w 四个方向键到 signal 中，不回显
		switch (signal)
		{
		case 'w':
			if (*pD != eDown)	//如果原蛇头方向不是向下才可以向上
				*pD = eUp;
			break;
		case 's':
			if (*pD != eUp)		//如果原蛇头方向不是向上才可以向下
				*pD = eDown;
			break;
		case 'a':
			if (*pD != eRight)	//如果原蛇头方向不是向右才可以向左
				*pD = eLeft;
			break;
		case 'd':
			if (*pD != eLeft)	//如果原蛇头方向不是向左才可以向右
				*pD = eRight;
			break;
		case VK_ESCAPE:
			printf("游戏已退出，感谢您的游玩\n");
			exit(0);
		case VK_SPACE:
			printf("游戏暂停...输入空格键位恢复...\n");
			while (1)
			{
				signal = _getch();
				if (signal == VK_SPACE)
				{
					printf("游戏继续进行\n");
					break;
				}
				else if (signal == VK_ESCAPE)
				{
					printf("游戏暂停...输入空格键位恢复...\n");
					exit(0);
				}
			}
		}
	}
}

//生成食物的坐标
node CreateFood(node* snake, int snakeLength)
{
	node food;
	while (1)
	{
		//先生成食物的随机坐标，并且限制在一定的范围内
		//推导也比较简单：
		//x * (NODE_WIDTH) < WINDOW_LENGTH 推出 x < WINDOW_LENGTH / NODE_WIDTH
		//y * (NODE_WIDTH) < WINDOW_WIDTH 推出 y < WINDOW_WIDTH / NODE_WIDTH
		food.x = rand() % (WINDOW_LENGTH / NODE_WIDTH);
		food.y = rand() % (WINDOW_WIDTH / NODE_WIDTH);

		//保证食物和蛇节点坐标不重叠
		int i;
		for (i = 0; i < snakeLength; i++)
		{
			if (snake[i].x == food.x && snake[i].y == food.y)
			{
				//如果发生坐标冲突则跳出内循环
				break;
			}
		}
		if (i < snakeLength)
		{
			//由于坐标发生冲突，跳出了内循环，所以循环数没有再增加，使用 continue 重新回到循环开头生成符合的食物节点
			continue;
		}
		else
		{
			//没有和蛇结点坐标冲突的食物坐标，准备返回结点
			break;
		}
	}
	return food;//返回食物的坐标（注意噢，这是返回两个数的例子，以后可以学习一下）
}

//绘制食物
void PaintFood(node food)
{
	//食物的左上、右下坐标
	int left, top;
	int right, bottom;

	left = food.x * NODE_WIDTH;
	top = food.y * NODE_WIDTH;

	right = (food.x + 1) * NODE_WIDTH;
	bottom = (food.y + 1) * NODE_WIDTH;

	//设置食物颜色，并且绘制食物
	setfillcolor(FOOD_COLOUR);
	solidrectangle(left, top, right, bottom);

	//填充颜色改回白色，避免后续填充绘画出现误用（EasyX 库默认使用白色填充）
	setfillcolor(WHITE);
}

//检测游戏结束条件
bool IsGameOver(node* snake, int snakeLength)
{
	//超出窗口的情况，注意 EasyX 库的设备坐标系
	if (snake[0].x < 0 || snake[0].x * NODE_WIDTH > WINDOW_LENGTH)//蛇头超出左右窗体
	{
		return true;
	}
	if (snake[0].y < 0 || snake[0].y * NODE_WIDTH > WINDOW_WIDTH)//蛇头超出上下窗体
	{
		return true;
	}

	//蛇自己吃到自己的情况
	for (int i = 1; i < snakeLength; i++)
	{
		//判断蛇头是否和蛇生身坐标重叠
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
		{
			return true;
		}
	}

	//都不满足就返回假
	return false;
}

//复位蛇数据
void Reset(node* snake, int* pLength, enum direction* dir)
{
	snake[0] = node{ 5, 7 };
	snake[1] = node{ 4, 7 };
	snake[2] = node{ 3, 7 };
	snake[3] = node{ 2, 7 };
	snake[4] = node{ 1, 7 };
	*pLength = 5;
	*dir = eRight;
}

//进度条
void Process()
{
	const char* progressBar = "\\|/-";
	int rate = 0;
	char bar[SIZE] = { 0 };
	int num = strlen(progressBar);
	while (rate <= MAX_RATE)
	{
		printf("[%-50s][%d%%][%c]\r", bar, rate * 2, progressBar[rate % num]);
		fflush(stdout);
		Sleep(PROGRESS_BAR_SPEED);
		bar[rate++] = STYLE;
	}
	printf("\n");
}