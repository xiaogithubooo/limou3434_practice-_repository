#include "snake.hpp"

//��ʼ������
void GameInit()
{
	//Ĭ���߼�����ԭ�����������ԭ���ص�
	srand((unsigned)time(NULL));							//����α�����

	initgraph(WINDOW_LENGTH, WINDOW_WIDTH, EX_SHOWCONSOLE);	//����һ������
	setbkcolor(WINDOW_COLOUR);								//������ɫ����
	cleardevice();											//ˢ�±�����ɫ
}

//��������
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

//����������
node SnakeMove(node* snake, int snakeLength, direction dir)
{
	//��¼���ߵ�β���ڵ�����
	node tail = snake[snakeLength - 1];

	//��ÿ��ǰ��Ľڵ㸲�ǵ�����Ľڵ�
	for (int i = snakeLength - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];
	}

	//��ͷ�ڵ���ݷ�������ض�������
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

	//��������β���ڵ����꣬����Ե�ʳ���ɾ��β���ڵ�����
	return tail;
}

//������
void PrintSnake(node* snake, int snakeLength)
{
	//ĳһ���߽ڵ�����ϡ���������
	int left, top;
	int right, bottom;

	//�����߽���ÿһ�����
	for (int i = 0; i < snakeLength; i++)
	{
		//�����ߵ�ĳ���ڵ�
		left = snake[i].x * NODE_WIDTH;
		top = snake[i].y * NODE_WIDTH;

		right = (snake[i].x + 1) * NODE_WIDTH;
		bottom = (snake[i].y + 1) * NODE_WIDTH;

		if(i == 0)	
			setfillcolor(SNAKE_HEAD_COLOUR);

		fillrectangle(left, top, right, bottom);
		
		setfillcolor(SNAKE_BODY_COLOUR);
	}
	setfillcolor(WHITE);
}

//������뷽��
void ChangeDirection(enum direction* pD)
{
	if (_kbhit() != 0)//������̨���ڵİ����Ƿ񱻰��£����·��ط���ֵ
	{
		char signal = _getch();	//���� a��s��d��w �ĸ�������� signal �У�������
		switch (signal)
		{
		case 'w':
			if (*pD != eDown)	//���ԭ��ͷ���������²ſ�������
				*pD = eUp;
			break;
		case 's':
			if (*pD != eUp)		//���ԭ��ͷ���������ϲſ�������
				*pD = eDown;
			break;
		case 'a':
			if (*pD != eRight)	//���ԭ��ͷ���������Ҳſ�������
				*pD = eLeft;
			break;
		case 'd':
			if (*pD != eLeft)	//���ԭ��ͷ����������ſ�������
				*pD = eRight;
			break;
		case VK_ESCAPE:			//���������������������ͣ���˳���
			printf("��Ϸ���˳�����л�������棡 +\n");
			exit(0);
		case VK_SPACE:
			printf("��Ϸ��ͣ...����ո��λ�ָ�...\n");
			while (1)
			{
				signal = _getch();
				if (signal == VK_SPACE)
				{
					printf("��Ϸ��������\n");
					break;
				}
				else if (signal == VK_ESCAPE)
				{
					printf("��Ϸ��ͣ...����ո��λ�ָ�...\n");
					exit(0);
				}
			}
		}
	}
}

//����ʳ�������
node CreateFood(node* snake, int snakeLength)
{
	node food;
	while (1)
	{
		//������ʳ���������꣬����������һ���ķ�Χ��
		//�Ƶ�Ҳ�Ƚϼ򵥣�
		//x * (NODE_WIDTH) < WINDOW_LENGTH �Ƴ� x < WINDOW_LENGTH / NODE_WIDTH
		//y * (NODE_WIDTH) < WINDOW_WIDTH �Ƴ� y < WINDOW_WIDTH / NODE_WIDTH
		food.x = rand() % (WINDOW_LENGTH / NODE_WIDTH);
		food.y = rand() % (WINDOW_WIDTH / NODE_WIDTH);

		//��֤ʳ����߽ڵ����겻�ص�
		int i;
		for (i = 0; i < snakeLength; i++)
		{
			if (snake[i].x == food.x && snake[i].y == food.y)
			{
				break;//������������ͻ��������ѭ��
			}
		}
		if (i < snakeLength)
		{
			continue;//�������귢����ͻ����������ѭ��������ѭ����û�������ӣ�ʹ�� continue ���»ص�ѭ����ͷ���ɷ��ϵ�ʳ��ڵ�
		}
		else
		{
			break;//û�к��߽�������ͻ��ʳ�����꣬׼�����ؽ��
		}
	}

	//����ʳ������꣨ע���ޣ����Ƿ��ؽṹ�壩
	return food;
}

//����ʳ��
void PaintFood(node food)
{
	//ʳ������ϡ���������
	int left, top;
	int right, bottom;

	left = food.x * NODE_WIDTH;
	top = food.y * NODE_WIDTH;

	right = (food.x + 1) * NODE_WIDTH;
	bottom = (food.y + 1) * NODE_WIDTH;

	//����ʳ����ɫ�����һ���ʳ��
	setfillcolor(FOOD_COLOUR);
	solidrectangle(left, top, right, bottom);

	//�����ɫ�Ļذ�ɫ������������滭�������ã�EasyX ��Ĭ��ʹ�ð�ɫ��䣩
	setfillcolor(WHITE);
}

//�����Ϸ��������
bool IsGameOver(node* snake, int snakeLength)
{
	//�������ڵ������ע�� EasyX ����豸����ϵ
	if (snake[0].x < 0 || snake[0].x * NODE_WIDTH > WINDOW_LENGTH)//��ͷ�������Ҵ���
	{
		return true;
	}
	if (snake[0].y < 0 || snake[0].y * NODE_WIDTH > WINDOW_WIDTH)//��ͷ�������´���
	{
		return true;
	}

	//���Լ��Ե��Լ������
	for (int i = 1; i < snakeLength; i++)
	{
		//�ж���ͷ�Ƿ�������������ص�
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
		{
			return true;
		}
	}

	//��������ͷ��ؼ�
	return false;
}

//��λ������
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

//������Ϸ��Ϣ
void PrintMessages(int eatingTimes, int failTimes)
{
	//������������Ĵ��ڷ�Χ
	RECT r = { 0, 0, WINDOW_LENGTH, WINDOW_WIDTH };
	
	//�����Ϸ������
	drawtext(_T("Snake game"), &r, DT_CENTER | DT_SINGLELINE);

	//���� wchar_t ���ַ��������飬���ҽ���Ϸ��Ϣ����ȥ�������
	TCHAR count[100];
	_stprintf(count, _T("���ε÷�:%d\n��������:%d"), eatingTimes, failTimes);//��������Ա� sprintf()��ֻ�����ǴӴ�ӡ��ͨ�� char �ַ���ɴ�ӡ���ַ� wchar_t ����
	drawtext(count, &r, DT_LEFT);
}