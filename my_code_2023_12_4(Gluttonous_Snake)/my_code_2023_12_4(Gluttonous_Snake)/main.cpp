#include "snake.hpp"

int main()
{
	//1.��ʼ��Ϸ�������ߺ�ʳ���Ϸ���֡���Ϸ��Ϣ
	GameInit();
	node snake[100] = { {5,7}, {4,7}, {3,7}, {2,7}, {1,7} };	//��ʼ�ߵ�����
	int snakeLength = SNAKE_LENGTH;								//��ʼ�ߵĳ���
	enum direction dir = eRight;								//��ʼ��ͷ����Ϊ��

	node food = CreateFood(snake, snakeLength);					//��ʼʳ�������

	settextcolor(TEXT_COLOUR);									//����������ɫ
	settextstyle(32, 14, _T(TEXE_STYLE));						//����������ʽ

	int eatingTimes = 0;										//ͳ�ƳԵ���ʳ��
	int failTimes = 0;											//ͳ��ʧ�ܴ���

	int speedUp = 2;											//�����õı���

	//2.������Ϸ�߼�
	printf("̰������Ϸ�����У������� w��a��s��d ���ƶ���\n");
	while (1)
	{
		//���ƴ��ڡ��ߡ�ʳ�����
		cleardevice();							//ʹ�õ�ǰ����ɫ��ջ�ͼ�豸
		PrintGrid();							//����������
		PrintSnake(snake, snakeLength);			//������
		PaintFood(food);						//����ʳ��
		PrintMessages(eatingTimes, failTimes);	//������Ϸ���⡢�÷֡�ʧ�ܴ���

		//�����ߵ��ٶ�
		if (eatingTimes <= 10)
		{
			Sleep(SNAKE_SPEED);
		}
		else if (eatingTimes <= 20)
		{
			Sleep(SNAKE_SPEED / speedUp);
		}
		else if (eatingTimes <= 30)
		{
			Sleep(SNAKE_SPEED / speedUp / speedUp);
		}

		//��ⷽ���޸��߽������
		ChangeDirection(&dir);								//����Ƿ��м������룬�еĻ��޸���ͷ�ķ���
		node lastTail = SnakeMove(snake, snakeLength, dir);	//�ı���ͷ���������������飬���ҷ��ش�������β���ڵ�����꣨ע�⣺�����snake�����飬����ֱ�Ӵ��������֣�
		
		//�Ե�ʳ������߳���
		if (snake[0].x == food.x && snake[0].y == food.y)	//��ͷ�ڵ��ʳ��ڵ��غϣ�˵���Ե���ʳ��
		{
			if (snakeLength < SNAKE_MAX_LENGTH)				//�����ߵĳ��ȣ������Ͳ��������ߵĳ���
			{
				snake[snakeLength] = lastTail;		//�����ߵ�β��
				snakeLength++;						//�ߵĳ�������
				eatingTimes++;						//ͳ�ƳԵ�ʳ������
				printf("�Ե�ʳ�� %d ��!\n", eatingTimes);
			}
			food = CreateFood(snake, snakeLength);			//�ٴ�����ʳ��
		}
		
		//�ж���Ϸ�Ƿ����
		if (IsGameOver(snake, snakeLength) == true)			//��ͷײ��ǽ�� or ��ͷ�Ե�����
		{
			printf("��Ϸʧ�� %d ��...\n\n", ++failTimes);	//��ӡ��Ϸʧ�ܴ���
			Sleep(1000);									//����һ�һ�ᣬ����״̬

			eatingTimes = 0;								//��λ����ʳ������
			Reset(snake, &snakeLength, &dir);				//��λ�ߵ����ݺͷ���
			food = CreateFood(snake, snakeLength);			//�ٴ�����ʳ��
		}
	}

	//3.������Ϸ��Դ
	int ch = getchar();	//��������̨���ڣ����û����Ե�֪���
	closegraph();		//�رջ滭����
	return 0;
}