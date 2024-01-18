#pragma once
#include "settings.hpp"

namespace limou
{
	struct Node
	{
		/*
		* 解释：该结构用于表示一个点的横纵坐标信息，默认为设备起点
		*/
		int _x = 0;
		int _y = 0;

		Node(int x = 0, int y = 0)
			: _x(x), _y(y)
		{}
	};
}