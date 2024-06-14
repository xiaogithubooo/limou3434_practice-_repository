#include "snake.hpp"

int main()
{
	// 设置游戏参数
	node snake[100] = {
		{5,7}, {4,7}, {3,7}, {2,7}, {1,7}
	};										// 蛇坐标
	int snakeLength;						// 蛇长度
	enum direction dir;						// 蛇方向
	node food;								// 食物坐标
	int eatingTimes = 0;					// 统计吃掉的食物
	int failTimes = 0;						// 统计失败次数
	int speedUp = 2;						// 提速用的变量


	// 游戏初始化
	InterfaceInit();						// 游戏界面初始化
	SnakeInit(snakeLength, dir);			// 蛇初始化
	FoodInit(snake, snakeLength, food);		// 食物初始化


	// 运行游戏逻辑
	printf("贪吃蛇游戏进行中，请输入 w、a、s、d 来移动蛇\n");
	while (1)
	{
		// 绘制窗口、蛇、食物对象
		cleardevice();							// 使用当前背景色清空绘图设备
		PrintGrid();							// 绘制网格函数
		PrintSnake(snake, snakeLength);			// 绘制蛇
		PaintFood(food);						// 绘制食物
		PrintMessages(eatingTimes, failTimes);	// 绘制游戏标题、得分、失败次数

		// 控制蛇的速度
		if (eatingTimes <= 10) {
			Sleep(SNAKE_SPEED);
		}
		else if (eatingTimes <= 20) {
			Sleep(SNAKE_SPEED / speedUp);
		}
		else if (eatingTimes <= 30) {
			Sleep(SNAKE_SPEED / speedUp / speedUp);
		}

		// 检测事件，修改蛇结点坐标
		if (!DetectionEvent(dir))						// 检查事件，是否有键盘输入，有的话修改蛇头的方向或者退出游戏
		{
			goto BREAK;
		}
		node lastTail = SnakeMove(snake, snakeLength, dir);	// 改变蛇头方向后的新坐标数组，并且返回储存了最尾部节点的坐标（注意：这里的snake是数组，可以直接传数组名字）

		// 吃掉食物，增长蛇长度
		if (snake[0].x == food.x && snake[0].y == food.y)	// 蛇头节点和食物节点重合，说明吃到了食物
		{		
			if (snakeLength < SNAKE_MAX_LENGTH)				// 限制蛇的长度，超出就不再增长蛇的长度
			{
				snake[snakeLength] = lastTail;	// 增加蛇的尾巴
				snakeLength++;					// 蛇的长度增加
				eatingTimes++;					// 统计吃到食物数量
				printf("吃掉食物 %d 次!\n", eatingTimes);
			}
			food = CreateFood(snake, snakeLength);			// 再次生成食物
		}

		// 判断游戏是否结束
		if (IsGameOver(snake, snakeLength) == true)			// 蛇头撞到墙壁 or 蛇头吃到蛇身
		{
			printf("游戏失败 %d 次...\n", ++failTimes);		// 打印游戏失败次数
			Sleep(1000);									// 让玩家缓一会，调整状态

			eatingTimes = 0;								// 复位所吃食物数量
			Reset(snake, snakeLength, dir);					// 复位蛇的数据和方向
			food = CreateFood(snake, snakeLength);			// 再次生成食物
		}
	}
	

	// 清理游戏资源
	BREAK: Destruction();

	return 0;
}