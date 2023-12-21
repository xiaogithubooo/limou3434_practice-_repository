#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

int main()
{
	int arr[10];
	srand((unsigned)time(0));
	for (auto& it : arr) cout << (it = rand() % 10) << " "; cout << '\n';
	//上面代码交给用户通过 IN 指令输入，被循环输入 10 次
	
	int m0 = 0;//MOV R0,#0H
	int m1 = 0;//MOV R1,#0H
	int m2 = 0;//MOV R2,#0H

LOOP1:
	if (m0 - 9 < 0)
	//MOV a,R0
	//SUB a,#09H


	{
		m1 = 0;
		//MOV  R1,#0H

	LOOP2:
		int num = m1 + m0 - 9;9
		int flag = num & 32768;
		if ((flag) == 1)//1??? ????|???? ????|???? ????|???? ????

		{
			if (*(arr + m1) - *(arr + m1 + 1) > 0)
			{
				m2 = *(arr + m1);
				*(arr + m1) = *(arr + m1 + 1);
				*(arr + m1 + 1) = m2;
			}
			m1++;
			goto LOOP2;
		}
		m0++;
		goto LOOP1;
	}
	
	EXIT1:

	for (const auto& it : arr) cout << it << " ";
	return 0;
}