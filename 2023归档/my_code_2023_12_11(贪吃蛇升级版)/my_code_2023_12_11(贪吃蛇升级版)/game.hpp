#pragma once
#include "settings.hpp"

namespace limou
{
	class Game
	{
		/*
		* 解释：该类用于绘制窗口，运行游戏逻辑，检测事件，统计信息，对象交互
		*/
		Game()
		{
			srand((unsigned)time(NULL));	//设置伪随机数

		}
		
		void Run()
		{

		}

	private:
		Snake _snake;
		Food _food;
	};
}