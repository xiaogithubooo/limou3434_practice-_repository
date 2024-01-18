#include "snake.hpp"

//�����ʼ��
void InterfaceInit()
{
	//Ĭ���߼�����ԭ�����������ԭ���ص�
	srand((unsigned)time(NULL));							//����α�����

	initgraph(WINDOW_LENGTH, WINDOW_WIDTH, EX_SHOWCONSOLE);	//����һ������
	setbkcolor(WINDOW_COLOUR);								//������ɫ����
	cleardevice();											//ˢ�±�����ɫ

	settextcolor(TEXT_COLOUR);								//����������ɫ
	settextstyle(32, 14, _T(TEXE_STYLE));					//����������ʽ
}

//�߳�ʼ��
void SnakeInit(int& snakeLength, direction& dir)
{
	snakeLength = SNAKE_LENGTH;//��ʼ�ߵĳ���
	dir = eRight;//��ʼ��ͷ����Ϊ��
}

//ʳ���ʼ��
void FoodInit(node* snake, int& snakeLength, node& food)
{
	food = CreateFood(snake, snakeLength);
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

		if (i == 0)
			setfillcolor(SNAKE_HEAD_COLOUR);

		fillrectangle(left, top, right, bottom);

		setfillcolor(SNAKE_BODY_COLOUR);
	}
	setfillcolor(WHITE);
}

//����¼�
bool DetectionEvent(direction& d)
{
	if (_kbhit() != 0)//������̨���ڵİ����Ƿ񱻰��£����·��ط���ֵ
	{
		char signal = _getch();	//���� a��s��d��w �ĸ�������� signal �У�������
		switch (signal)
		{
		case 'w':
			if (d != eDown)	//���ԭ��ͷ���������²ſ�������
				d = eUp;
			break;
		case 's':
			if (d != eUp)	//���ԭ��ͷ���������ϲſ�������
				d = eDown;
			break;
		case 'a':
			if (d != eRight)//���ԭ��ͷ���������Ҳſ�������
				d = eLeft;
			break;
		case 'd':
			if (d != eLeft)	//���ԭ��ͷ����������ſ�������
				d = eRight;
			break;
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
				if (signal == VK_ESCAPE)
				{
					printf("��Ϸ���˳�����л�������棡\n");
					return false;
				}
			}
			break;
		case VK_ESCAPE:			//���������������������ͣ���˳���
			printf("��Ϸ���˳�����л�������棡\n");
			return false;

			break;
		default:
			printf("�Ƿ�����\n");
			break;
		}
	}
	return true;
}

//����ʳ�������
node CreateFood(node* snake, const int& snakeLength)
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
void PaintFood(const node& food)
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
bool IsGameOver(node* snake, const int& snakeLength)
{
	//�������ڵ������ע�� EasyX ����豸����ϵ
	if (snake[0].x < 0 || snake[0].x * NODE_WIDTH >= WINDOW_LENGTH)//��ͷ�������Ҵ���
	{
		return true;
	}
	if (snake[0].y < 0 || snake[0].y * NODE_WIDTH >= WINDOW_WIDTH)//��ͷ�������´���
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
void Reset(node* snake, int& pLength, direction& dir)
{
	snake[0] = node{ 5, 7 };
	snake[1] = node{ 4, 7 };
	snake[2] = node{ 3, 7 };
	snake[3] = node{ 2, 7 };
	snake[4] = node{ 1, 7 };
	pLength = 5;
	dir = eRight;
}

//������Ϸ��Ϣ
void PrintMessages(const int& eatingTimes, const int& failTimes)
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

//��Դ����
void Destruction()
{
	closegraph();		//�رջ滭����
}