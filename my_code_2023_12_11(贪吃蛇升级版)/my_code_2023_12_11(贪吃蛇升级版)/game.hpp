#pragma once
#include "settings.hpp"

namespace limou
{
	class Game
	{
		/*
		* ���ͣ��������ڻ��ƴ��ڣ�������Ϸ�߼�������¼���ͳ����Ϣ�����󽻻�
		*/
		Game()
		{
			srand((unsigned)time(NULL));	//����α�����

		}
		
		void Run()
		{

		}

	private:
		Snake _snake;
		Food _food;
	};
}