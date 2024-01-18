#define _CRT_SECURE_NO_WARNINGS 1
#include<easyx.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define NODE_WIDTH 40
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//<һ���Զ����װ�ṹ��>
typedef struct//�ٷ�װ����ṹ�壨�ڵ�������XY���꣩
{
	int x;
	int y;
}node;
enum direction//�ڷ�װ����ö����
{
	eUp,//��
	eDown,//��
	eLeft,//��
	eRight//��
};
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//<�����Զ����װ����>
void paintGrid()//<�ٻ�������>
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
node snakeMove(node* snake, int length, int direction)//<���������µ��������麯��>
{//���ߵ�����ṹ������ָ�룬�ߵĽڵ�������ߵ�ǰ������
	node tail = snake[length - 1];//��¼�´�ʱ�ߵ���β���ڵ�����

	for (int i = length - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];//�ú����������ǰ������飬����ÿ��ǰ��Ľڵ㸲�ǵ�����Ľڵ㣨��ͷ��ǰ����β�ں󣩣���ͷ�ڵ�����ٸ��ݷ�������ض�������
	}

	node newHead;//�����µ���ͷ�������
	newHead = snake[0];//��ԭ��ͷ�����괫������ı�����
	//���ݼ������뷽��ı��µ���ͷ���꣨ע��ö��������ã�ö�����ڲ���Ա���������ֱ��д������
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

	snake[0] = newHead;//�����µ�ͷ

	return tail;//��������β���ڵ����꣬����Ե�ʳ���ɾ��β���ڵ�����
}
void paintSnake(node* snake, int n)//<�۳�ʼ�����ߺ���>
{//���ߵ�����ṹ��ָ�룬�ߵĽڵ�������
	int left, top, right, bottom;//ĳһ���߽ڵ�����ϡ���������
	for (int i = 0; i < n; i++)
	{
		left = snake[i].x * NODE_WIDTH;
		top = snake[i].y * NODE_WIDTH;
		right = (snake[i].x + 1) * NODE_WIDTH;
		bottom = (snake[i].y + 1) * NODE_WIDTH;

		solidrectangle(left, top, right, bottom);//���ߵ�һ��С�ڵ㣨Ĭ����ɫΪ��ɫ��
	}
}

void changeDirection(enum direction* pD)//<�ܼ�����뷽����>
{//��ö����ָ�������
	if (_kbhit() != 0)//�鿴�������ǲ��ǿյ�
	{
		char c = _getch();//����a��s��d��w�ĸ��������c��
		switch (c)
		{
		case 'w':
			if (*pD != eDown)//���ԭ��ͷ���������²ſ�������
				*pD = eUp;
			break;
		case 's':
			if (*pD != eUp)//���ԭ��ͷ���������ϲſ�������
				*pD = eDown;
			break;
		case 'a':
			if (*pD != eRight)//���ԭ��ͷ���������Ҳſ�������
				*pD = eLeft;
			break;
		case 'd':
			if (*pD != eLeft)//���ԭ��ͷ����������ſ�������
				*pD = eRight;
			break;
		}
	}
}
node createFood(node* snake, int length)//<������ʳ�������>
{//���ߵĽڵ�����ṹ��ָ�룬�ߵĽڵ�����
	node food;
	while (1)
	{
		food.x = rand() % (800 / NODE_WIDTH);//������ʳ���������꣬����������һ���ķ�Χ��
		food.y = rand() % (600 / NODE_WIDTH);

		int i;
		for (i = 0; i < length; i++)
		{
			if (snake[i].x == food.x && snake[i].y == food.y)//��֤ʳ����߽ڵ����겻�ص�
			{
				break;//������������ͻ��������ѭ��
			}
			
		}
		if (i < length)
		{
			continue;//�������귢����ͻ����������ѭ��������ѭ����û�������ӣ�ʹ��continue���»ص�ѭ����ͷ���ɷ��ϵ�ʳ��ڵ�
		}
		else
		{
			break;
		}
	}
	return food;//����ʳ������꣨ע���ޣ����Ƿ��������������ӣ��Ժ����ѧϰһ�£�
}
void paintFood(node food)//<������ʳ��ڵ㺯��>
{//������ʳ��Ľڵ��������ݣ�
	int left, top, right, bottom;
	left = food.x * NODE_WIDTH;
	top = food.y * NODE_WIDTH;
	right = (food.x + 1) * NODE_WIDTH;
	bottom = (food.y + 1) * NODE_WIDTH;
	setfillcolor(YELLOW);//ʳ�����ɫ
	solidrectangle(left, top, right, bottom);//���ʳ�����
	setfillcolor(WHITE);//�����ɫ�Ļذ�ɫ������������滭��������
}
bool isGameOver(node* snake, int length)//��<��Ϸ�����ж�����>��ע�ⷵ��ֵ�ǲ���ֵ��
{//���߽ڵ�����ṹ��ָ�룬�ߵĳ��ȣ�
	if (snake[0].x < 0 || snake[0].x>800 / NODE_WIDTH)//��ͷ�������Ҵ���
	{
		return true;
	}
	if (snake[0].y < 0 || snake[0].y>600 / NODE_WIDTH)//��ͷ�������´���
	{
		return true;
	}

	for (int i = 1; i < length; i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)//�ж���ͷ�Ƿ�������������ص�
		{
			return true;
		}
	}
	return false;
}
void reset(node* snake, int* pLength, enum direction* d)//�ิλ�ߵ����ݺ���
{//���ߵĽڵ����꣬�߽ڵ㳤��ָ�룬ǰ������ָ�룩
	snake[0] = node{ 5,7 };//��node��Ϊ�˸����������꣨�Ѿ��ǽṹ���ˣ��������ע��һ�¡�����
	snake[1] = node{ 4,7 }; 
	snake[2] = node{ 3,7 };
	snake[3] = node{ 2,7 };
	snake[4] = node{ 1,7 };
	*pLength = 5;
	*d = eRight;
}
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+







//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//ǰ��˵����
//<����ˮƽ20�ȷ֣���ֱ15�ȷݣ���0��ʼ��>
//<���ð�ɫ�ľ��θ��ӱ�ʾ��ʳ��Ϊһ���θ��ӻ�ɫ>
//
//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+







//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
//<����������>
int main()
{
	//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
	//<��������>
	initgraph(800, 600, EX_SHOWCONSOLE);//����һ������
	setbkcolor(RGB(164, 225, 202));//������ɫ����
	cleardevice();//ˢ�±�����ɫ
	//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
	//<Ĭ���߼�����ԭ��Ϊ��������ԭ��>
	//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
	//<��ʼ���ߺ�ʳ��>
	node snake[100] = { {5,7},{4,7},{3,7},{2,7},{1,7} };//��ʼ�ߣ��±�Ϊ0��1��2��3��4����ͷ��5��7����
	int length = 5;//�ߵĳ�ʼ����
	enum direction d = eRight;//Ĭ�ϳ�ʼ����ͷ�ķ���������
	srand((unsigned)time(NULL));
	node food = createFood(snake, length);//��һ������ʳ��ڵ�
	int number = 0;//ͳ�ƳԵ���ʳ��
	int num = 0;//ͳ��ʧ�ܴ���
	//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
	//����ѭ���ж�>
	printf("*̰������Ϸ������*\n");
	while (1)
	{
		cleardevice();//���ȫ������
		paintGrid();//����������
		paintSnake(snake, length);//������ʼ������ߣ��Լ�����������º���ߣ�
		//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
		paintFood(food);//����ʳ��
		//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
		//<ͣ��500����>
		Sleep(500);
		//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
		//<����������>
		changeDirection(&d);//����Ƿ��м������룬�еĻ��޸���ͷ�ķ�������ָ���޸�d��ֵ��
		//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
		//<�����ߵ�����>
		node lastTail = snakeMove(snake, length, d);//�ı���ͷ���������������飬���ҷ��ش�������β���ڵ�����꣨ע�⣺�����snake�����飬����ֱ�Ӵ��������֣�
		//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
		//<�ж����Ƿ�Ե�ʳ��>
		if (snake[0].x == food.x && snake[0].y == food.y)//�����ͷ�ڵ��ʳ��ڵ��غϣ�˵���Ե�ʳ����
		{
			if (length < 100)//�����ߵĳ���
			{
				snake[length] = lastTail;//ʳ����������ͷ
				length++;//�ߵĳ��ȷ���
				number++;//ͳ�ƳԵ�ʳ�������
				printf("<�Ե�ʳ��%d��>\n", number);
			}
			food = createFood(snake, length);//�ٴ�����ʳ��
		}
		//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
		//<�ж���Ϸ����>
		//��1����ͷײ��ǽ��
		//��2����ͷ�Ե�����
		if (isGameOver(snake, length) == true)
		{
			num++;
			printf("|��Ϸʧ��%d��|\n\n", num);
			Sleep(1000);
			number = 0;
			reset(snake, &length, &d);//��λ�ߵ�����
			food = createFood(snake, length);//�ٴ��������ʳ��
		}
	}
	//=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
	int o = getchar();
	closegraph();
	return 0;
}