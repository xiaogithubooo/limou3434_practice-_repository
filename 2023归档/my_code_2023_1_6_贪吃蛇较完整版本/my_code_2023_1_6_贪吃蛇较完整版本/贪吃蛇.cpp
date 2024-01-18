#define _CRT_SECURE_NO_WARNINGS 1
#include<easyx.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define NODE_WIDTH 40
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//<一、自定义封装结构体>
typedef struct//①封装坐标结构体（节点的网格段XY坐标）
{
	int x;
	int y;
}node;
enum direction//②封装方向枚举体
{
	eUp,//上
	eDown,//下
	eLeft,//左
	eRight//右
};
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//<二、自定义封装函数>
void paintGrid()//<①画网格函数>
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
node snakeMove(node* snake, int length, int direction)//<②生成蛇新的坐标数组函数>
{//（蛇的坐标结构体数组指针，蛇的节点个数，蛇的前进方向）
	node tail = snake[length - 1];//记录下此时蛇的最尾部节点坐标

	for (int i = length - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];//让后面的数组变成前面的数组，即将每个前面的节点覆盖掉后面的节点（蛇头在前，蛇尾在后），蛇头节点后续再根据方向进行重定义坐标
	}

	node newHead;//创建新的蛇头坐标变量
	newHead = snake[0];//将原蛇头的坐标传到上面的变量中
	//根据键盘输入方向改变新的蛇头坐标（注意枚举体的运用，枚举体内部成员在这里可以直接写出来）
	if (direction == eUp)
	{
		newHead.y--;
	}
	else if (direction == eDown)
	{
		newHead.y++;
	}
	else if (direction == eLeft)
	{
		newHead.x--;
	}
	else if (direction == eRight)
	{
		newHead.x++;
	}

	snake[0] = newHead;//赋予新的头

	return tail;//返回蛇最尾部节点坐标，方便吃掉食物后不删除尾部节点坐标
}
void paintSnake(node* snake, int n)//<③初始化画蛇函数>
{//（蛇的坐标结构体指针，蛇的节点数量）
	int left, top, right, bottom;//某一段蛇节点的左上、右下坐标
	for (int i = 0; i < n; i++)
	{
		left = snake[i].x * NODE_WIDTH;
		top = snake[i].y * NODE_WIDTH;
		right = (snake[i].x + 1) * NODE_WIDTH;
		bottom = (snake[i].y + 1) * NODE_WIDTH;

		solidrectangle(left, top, right, bottom);//画蛇的一个小节点（默认颜色为白色）
	}
}

void changeDirection(enum direction* pD)//<④检查输入方向函数>
{//（枚举体指针变量）
	if (_kbhit() != 0)//查看缓冲区是不是空的
	{
		char c = _getch();//输入a、s、d、w四个方向键到c中
		switch (c)
		{
		case 'w':
			if (*pD != eDown)//如果原蛇头方向不是向下才可以向上
				*pD = eUp;
			break;
		case 's':
			if (*pD != eUp)//如果原蛇头方向不是向上才可以向下
				*pD = eDown;
			break;
		case 'a':
			if (*pD != eRight)//如果原蛇头方向不是向右才可以向左
				*pD = eLeft;
			break;
		case 'd':
			if (*pD != eLeft)//如果原蛇头方向不是向左才可以向右
				*pD = eRight;
			break;
		}
	}
}
node createFood(node* snake, int length)//<⑤生成食物的坐标>
{//（蛇的节点坐标结构体指针，蛇的节点数）
	node food;
	while (1)
	{
		food.x = rand() % (800 / NODE_WIDTH);//先生成食物的随机坐标，并且限制在一定的范围内
		food.y = rand() % (600 / NODE_WIDTH);

		int i;
		for (i = 0; i < length; i++)
		{
			if (snake[i].x == food.x && snake[i].y == food.y)//保证食物和蛇节点坐标不重叠
			{
				break;//如果发生坐标冲突，跳出内循环
			}
			
		}
		if (i < length)
		{
			continue;//由于坐标发生冲突，跳出了内循环，所以循环数没有再增加，使用continue重新回到循环开头生成符合的食物节点
		}
		else
		{
			break;
		}
	}
	return food;//返回食物的坐标（注意噢，这是返回两个数的例子，以后可以学习一下）
}
void paintFood(node food)//<⑥生成食物节点函数>
{//（传入食物的节点坐标数据）
	int left, top, right, bottom;
	left = food.x * NODE_WIDTH;
	top = food.y * NODE_WIDTH;
	right = (food.x + 1) * NODE_WIDTH;
	bottom = (food.y + 1) * NODE_WIDTH;
	setfillcolor(YELLOW);//食物的颜色
	solidrectangle(left, top, right, bottom);//绘出食物矩形
	setfillcolor(WHITE);//填充颜色改回白色，避免后续填充绘画出现误用
}
bool isGameOver(node* snake, int length)//⑦<游戏结束判定函数>（注意返回值是布尔值）
{//（蛇节点坐标结构体指针，蛇的长度）
	if (snake[0].x < 0 || snake[0].x>800 / NODE_WIDTH)//蛇头超出左右窗体
	{
		return true;
	}
	if (snake[0].y < 0 || snake[0].y>600 / NODE_WIDTH)//蛇头超出上下窗体
	{
		return true;
	}

	for (int i = 1; i < length; i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)//判断蛇头是否和蛇生身坐标重叠
		{
			return true;
		}
	}
	return false;
}
void reset(node* snake, int* pLength, enum direction* d)//⑧复位蛇的数据函数
{//（蛇的节点坐标，蛇节点长度指针，前进方向指针）
	snake[0] = node{ 5,7 };//加node是为了赋予两个坐标（已经是结构体了，这里可以注意一下……）
	snake[1] = node{ 4,7 }; 
	snake[2] = node{ 3,7 };
	snake[3] = node{ 2,7 };
	snake[4] = node{ 1,7 };
	*pLength = 5;
	*d = eRight;
}
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+







//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//前提说明：
//<网格水平20等分，竖直15等份（从0开始）>
//<蛇用白色的矩形格子表示，食物为一矩形格子黄色>
//
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+







//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//<主函数部分>
int main()
{
	//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
	//<基础设置>
	initgraph(800, 600, EX_SHOWCONSOLE);//创建一个窗体
	setbkcolor(RGB(164, 225, 202));//背景颜色属性
	cleardevice();//刷新背景颜色
	//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
	//<默认逻辑坐标原点为物理坐标原点>
	//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
	//<初始化蛇和食物>
	node snake[100] = { {5,7},{4,7},{3,7},{2,7},{1,7} };//初始蛇，下标为0、1、2、3、4（蛇头（5，7））
	int length = 5;//蛇的初始长度
	enum direction d = eRight;//默认初始化蛇头的方向是向右
	srand((unsigned)time(NULL));
	node food = createFood(snake, length);//第一次生成食物节点
	int number = 0;//统计吃掉的食物
	int num = 0;//统计失败次数
	//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
	//进入循环判断>
	printf("*贪吃蛇游戏进行中*\n");
	while (1)
	{
		cleardevice();//清空全屏窗体
		paintGrid();//绘制网格函数
		paintSnake(snake, length);//画出初始化后的蛇（以及坐标数组更新后的蛇）
		//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
		paintFood(food);//绘制食物
		//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
		//<停滞500毫秒>
		Sleep(500);
		//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
		//<检查键盘输入>
		changeDirection(&d);//检查是否有键盘输入，有的话修改蛇头的方向（利用指针修改d的值）
		//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
		//<更新蛇的坐标>
		node lastTail = snakeMove(snake, length, d);//改变蛇头方向后的新坐标数组，并且返回储存了最尾部节点的坐标（注意：这里的snake是数组，可以直接传数组名字）
		//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
		//<判断蛇是否吃掉食物>
		if (snake[0].x == food.x && snake[0].y == food.y)//如果蛇头节点和食物节点重合，说明吃到食物了
		{
			if (length < 100)//限制蛇的长度
			{
				snake[length] = lastTail;//食物坐标变成蛇头
				length++;//蛇的长度翻倍
				number++;//统计吃到食物的数量
				printf("<吃掉食物%d次>\n", number);
			}
			food = createFood(snake, length);//再次生成食物
		}
		//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
		//<判断游戏结束>
		//（1）蛇头撞到墙壁
		//（2）蛇头吃到蛇身
		if (isGameOver(snake, length) == true)
		{
			num++;
			printf("|游戏失败%d次|\n\n", num);
			Sleep(1000);
			number = 0;
			reset(snake, &length, &d);//复位蛇的数据
			food = createFood(snake, length);//再次随机生成食物
		}
	}
	//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
	int o = getchar();
	closegraph();
	return 0;
}