#pragma once
#include "settings.hpp"

namespace limou
{
	struct Node
	{
		/*
		* ���ͣ��ýṹ���ڱ�ʾһ����ĺ���������Ϣ��Ĭ��Ϊ�豸���
		*/
		int _x = 0;
		int _y = 0;

		Node(int x = 0, int y = 0)
			: _x(x), _y(y)
		{}
	};
}