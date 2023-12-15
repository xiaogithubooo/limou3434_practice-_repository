#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	int arr[10];
	srand((unsigned)time(0));
	for (auto& it : arr) cout << (it = rand() % 10) << " "; cout << '\n';
	//上面代码交给用户通过 IN 指令输入，被循环输入 10 次
	
//LOOP:

	int m0 = 0;
	//MOV #0H, R0

	int m1 = 0;
	//MOV #0H, R1

	int m2 = 0;
	//MOV #0H, R2

LOOP1:
	if (m0 - 9 < 0)
	//MOV a, R0
	//sub a, #09H
	//jz EXIT1

	{
		m1 = 0;
		//MOV #0H, R1

	LOOP2:
		if (m1 + m0 - 9 < 0)
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

//EXIT1:

	for (const auto& it : arr) cout << it << " ";
	return 0;
}