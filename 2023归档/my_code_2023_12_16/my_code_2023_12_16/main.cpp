//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
//using namespace std;
//
//int main()
//{
//	//arr[10]
//	int arr[10];
//	srand((unsigned)time(0));
//	for (auto& it : arr) cout << (it = rand() % 10) << " "; cout << '\n';
//	//上面代码交给用户通过 IN 指令输入，被循环输入 10 次
//	
//	int m0 = 0;//MOV R0,#0H
//	int m1 = 0;//MOV R1,#0H
//	int m2 = 0;//MOV R2,#0H
//	//int m3 = arr;//MOV R3,#60
//
//LOOP1:
//	if (m0 < 9)
//	//MOV A,R0
//	//SUB A,#09H //小于就发生越位，if 成立
//	//JC IF_1_BEGIN
//	
//	//JUM EXIT
//	 
//	//IF_1_BEGIN:
//	{
//		m1 = 0;
//		//MOV  R1,#0H
//
//	LOOP2:
//		if ((m1 + m0) < 9)
//		//MOV A,R1
//		//ADD A,R0
//		//SUB A,#9H
//		//JC IF_2_BEGIN
//
//		//JUM EXIT
//		{
//
//		//IF_2_BEGIN:
//			if (*(arr + m1) > *(arr + m1 + 1))
//			{
//				//MOV 
//				m2 = *(arr + m1);
//				*(arr + m1) = *(arr + m1 + 1);
//				*(arr + m1 + 1) = m2;
//			}
//			m1++;
//			goto LOOP2;
//		}
//		m0++;
//		goto LOOP1;
//	}
//	
//	EXIT1:
//
//	for (const auto& it : arr) cout << it << " ";
//	return 0;
//}
//
////EXIT:
//
//
