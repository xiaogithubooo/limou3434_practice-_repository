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
* 创建者：limou3434
* 项目名称：贪吃蛇小游戏
* 创建时间：2023.12.11
* 使用语言：主 C++，混编 C
* 第三方库：EasyX 图形库
* 概要说明：...
*/

namespace limou
{
	struct Settings
	{
		/*
		* 解释：该类用于设置整个游戏的基础设置和参数，
		* 主要是设置颜色和绘图大小的问题，其他类最主要是进行数据交互
		* 默认情况下不可被修改，除非改动源码（标记：后期看看可不可以在代码中修改）
		*/
		//绘图窗口参数
		const int _NODE_WIDTH = 50;								//格点大小
		const int _WINDOW_LENGTH = _NODE_WIDTH * 16;			//窗体长度（800）
		const int _WINDOW_WIDTH = _NODE_WIDTH * 12;				//窗体宽度（600）
		const COLORREF _WINDOW_COLOUR = RGB(249, 205, 173);		//背景颜色

		//蛇参数
		const int _SNAKE_LENGTH = 5;							//蛇初始长度
		const int _SNAKE_MAX_LENGTH = 30;						//蛇最大长度
		const int _SNAKE_SPEED = 500;							//蛇初始速度
		const COLORREF _SNAKE_HEAD_COLOUR = RGB(254, 67, 101);	//蛇头颜色
		const COLORREF _SNAKE_BODY_COLOUR = RGB(252, 157, 154);	//蛇身颜色
		const vector<Node> _SNAKE_BODY_COORD = ;	//蛇身颜色
		
		//食物参数
		const COLORREF _FOOD_COLOUR = RGB(200, 200, 169);		//食物颜色

		//文字参数
		const COLORREF _TEXT_COLOUR = RGB(0, 0, 0);				//文字颜色
		const std::string _TEXE_STYLE = "Consolas";				//文字风格
	};
}