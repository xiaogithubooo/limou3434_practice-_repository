#include "snake.hpp"



int main()
{
	//1.��ʼ��Ϸ����
	GameInit();

	//2.��ʼ�ߺ�ʳ��
	node snake[100] = { {5,7}, {4,7}, {3,7}, {2,7}, {1,7} };	//��ʼ�ߵ�����
	int snakeLength = SNAKE_LENGTH;								//��ʼ�ߵĳ���
	enum direction dir = eRight;								//��ʼ��ͷ�ķ���Ϊ��
	node food = CreateFood(snake, snakeLength);					//��ʼʳ�������

	//3.ͳ����Ϸ��Ϣ
	int eatingTimes = 0;	//ͳ�ƳԵ���ʳ��
	int num = 0;			//ͳ��ʧ�ܴ���

	//4.������Ϸ�߼�
	printf("̰������Ϸ��Դ��ʼ����\n");
	Process();
	printf("̰������Ϸ�����У������� w��a��s��d ���ƶ���\n");
	while (1)
	{
		//���ƴ��ڡ��ߡ�ʳ�����
		cleardevice();						//ʹ�õ�ǰ����ɫ��ջ�ͼ�豸
		PrintGrid();						//����������
		PrintSnake(snake, snakeLength);		//������
		PaintFood(food);					//����ʳ��

		//��ⷽ���޸��߽������
		Sleep(SNAKE_SPEED);
		ChangeDirection(&dir);		//����Ƿ��м������룬�еĻ��޸���ͷ�ķ���
		node lastTail = SnakeMove(snake, snakeLength, dir);	//�ı���ͷ���������������飬���ҷ��ش�������β���ڵ�����꣨ע�⣺�����snake�����飬����ֱ�Ӵ��������֣�
		
		//�Ե�ʳ������߳���
		if (snake[0].x == food.x && snake[0].y == food.y)//��ͷ�ڵ��ʳ��ڵ��غϣ�˵���Ե���ʳ��
		{
			if (snakeLength < SNAKE_MAX_LENGTH)		//�����ߵĳ��ȣ������Ͳ��������ߵĳ���
			{
				snake[snakeLength] = lastTail;		//�����ߵ�β��
				snakeLength++;						//�ߵĳ�������
				eatingTimes++;						//ͳ�ƳԵ�ʳ������
				printf("�Ե�ʳ�� %d ��!\n", eatingTimes);
			}
			food = CreateFood(snake, snakeLength);	//�ٴ�����ʳ��
		}
		
		//�ж���Ϸ�Ƿ����
		if (IsGameOver(snake, snakeLength) == true)				//��ͷײ��ǽ�� or ��ͷ�Ե�����
		{
			printf("��Ϸʧ�� %d ��...\n\n", ++num);				//��ӡ��Ϸʧ�ܴ���
			Sleep(1000);										//����һ�һ�ᣬ����״̬

			eatingTimes = 0;									//��λ����ʳ������
			Reset(snake, &snakeLength, &dir);					//��λ�ߵ����ݺͷ���
			food = CreateFood(snake, snakeLength);				//�ٴ�����ʳ��
		}
	}

	//5.������Ϸ��Դ
	int ch = getchar();	//��������̨���ڣ����û����Ե�֪���
	closegraph();		//�رջ滭����
	return 0;
}