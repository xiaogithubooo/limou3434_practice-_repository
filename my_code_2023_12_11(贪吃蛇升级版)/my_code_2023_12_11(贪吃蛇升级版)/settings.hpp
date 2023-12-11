#pragma once
#include <string>
#include <easyx.h>

/*
* �����ߣ�limou3434
* ��Ŀ���ƣ�̰����С��Ϸ
* ����ʱ�䣺2023.12.11
* ʹ�����ԣ��� C++����� C
* �������⣺EasyX ͼ�ο�
* ��Ҫ˵����...
*/

namespace limou
{
	struct Settings
	{
		/*
		* ���ͣ�������������������Ϸ�Ļ������úͲ�����Ĭ������²��ɱ��޸ģ����ǸĶ�Դ��
		*/
		const int _NODE_WIDTH = 50;								//����С
		const int _WINDOW_LENGTH = 800;							//���峤��
		const int _WINDOW_WIDTH = 600;							//������
		const int _SNAKE_LENGTH = 5;							//�߳�ʼ����
		const int _SNAKE_MAX_LENGTH = 30;						//����󳤶�
		const int _SNAKE_SPEED = 500;							//�߳�ʼ�ٶ�

		const COLORREF _WINDOW_COLOUR = RGB(249, 205, 173);		//������ɫ
		const COLORREF _SNAKE_HEAD_COLOUR = RGB(254, 67, 101);	//��ͷ��ɫ
		const COLORREF _SNAKE_BODY_COLOUR = RGB(252, 157, 154);	//������ɫ
		const COLORREF _FOOD_COLOUR = RGB(200, 200, 169);		//ʳ����ɫ
		const COLORREF _TEXT_COLOUR = RGB(0, 0, 0);				//������ɫ

		const std::string _TEXE_STYLE = "Consolas";				//���ַ��
	};
}