#pragma once
#include <string>
#include <easyx.h>

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
		* 解释：该类用于设置整个游戏的基础设置和参数，默认情况下不可被修改，除非改动源码
		*/
		const int _NODE_WIDTH = 50;								//格点大小
		const int _WINDOW_LENGTH = 800;							//窗体长度
		const int _WINDOW_WIDTH = 600;							//窗体宽度
		const int _SNAKE_LENGTH = 5;							//蛇初始长度
		const int _SNAKE_MAX_LENGTH = 30;						//蛇最大长度
		const int _SNAKE_SPEED = 500;							//蛇初始速度

		const COLORREF _WINDOW_COLOUR = RGB(249, 205, 173);		//背景颜色
		const COLORREF _SNAKE_HEAD_COLOUR = RGB(254, 67, 101);	//蛇头颜色
		const COLORREF _SNAKE_BODY_COLOUR = RGB(252, 157, 154);	//蛇身颜色
		const COLORREF _FOOD_COLOUR = RGB(200, 200, 169);		//食物颜色
		const COLORREF _TEXT_COLOUR = RGB(0, 0, 0);				//文字颜色

		const std::string _TEXE_STYLE = "Consolas";				//文字风格
	};
}