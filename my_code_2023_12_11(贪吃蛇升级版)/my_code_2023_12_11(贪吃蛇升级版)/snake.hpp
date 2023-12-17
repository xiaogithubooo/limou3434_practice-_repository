#pragma once
#include "settings.hpp"

namespace limou
{
	class Snake
	{
	public:
		Snake(const vector<Node>& snakeCoords = { { 5,7 }, { 4,7 }, { 3,7 }, { 2,7 }, { 1,7 } },
			const Direction& snakeDir = eRight,
			const int& snakeLength = 5)
			: _snakeCoords(snakeCoords)
			, _snakeDir(snakeDir)
			, _snakeLength(snakeLength)
		{}

		void Move()
		{

		}

		void Print()
		{

		}

	private:
		vector<Node> _snakeCoords;	//��������
		Direction _snakeDir;		//�ߵķ���
		int _snakeLength;			//�ߵĳ���
	};
}