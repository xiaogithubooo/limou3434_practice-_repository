#pragma once
#include <string>
#include <vector>
#include <easyx.h>
#include <ctime>
#include <cstdlib>
#include "node.hpp"
#include "direction.hpp"
#include "snake.hpp"
#include "food.hpp"

using std::string;
using std::vector;
using limou::Node;
using limou::Direction;
using limou::Snake;
using limou::Food;

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
		* ���ͣ�������������������Ϸ�Ļ������úͲ�����
		* ��Ҫ��������ɫ�ͻ�ͼ��С�����⣬����������Ҫ�ǽ������ݽ���
		* Ĭ������²��ɱ��޸ģ����ǸĶ�Դ�루��ǣ����ڿ����ɲ������ڴ������޸ģ�
		*/
		//��ͼ���ڲ���
		const int _NODE_WIDTH = 50;								//����С
		const int _WINDOW_LENGTH = _NODE_WIDTH * 16;			//���峤�ȣ�800��
		const int _WINDOW_WIDTH = _NODE_WIDTH * 12;				//�����ȣ�600��
		const COLORREF _WINDOW_COLOUR = RGB(249, 205, 173);		//������ɫ

		//�߲���
		const int _SNAKE_LENGTH = 5;							//�߳�ʼ����
		const int _SNAKE_MAX_LENGTH = 30;						//����󳤶�
		const int _SNAKE_SPEED = 500;							//�߳�ʼ�ٶ�
		const COLORREF _SNAKE_HEAD_COLOUR = RGB(254, 67, 101);	//��ͷ��ɫ
		const COLORREF _SNAKE_BODY_COLOUR = RGB(252, 157, 154);	//������ɫ
		const vector<Node> _SNAKE_BODY_COORD = ;	//������ɫ
		
		//ʳ�����
		const COLORREF _FOOD_COLOUR = RGB(200, 200, 169);		//ʳ����ɫ

		//���ֲ���
		const COLORREF _TEXT_COLOUR = RGB(0, 0, 0);				//������ɫ
		const std::string _TEXE_STYLE = "Consolas";				//���ַ��
	};
}