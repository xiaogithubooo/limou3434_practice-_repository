#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
//#include <stdio.h>
//#include <easyx.h>
//1���ʺ���Ļ
//int main()
//{
//    initgraph(800, 600);
//    float h = 0;
//    float dH = 360.0 / 600.0;
//    for (int y = 0; y < 600; y++)
//    {
//        setlinecolor(HSVtoRGB(h, 1, 1));
//        line(0, y, 800, y);
//        h += dH;
//    }
//
//   //getchar();
//    closegraph();
//    return 0;
//}

//2������ʹ��C++��֪ʶ
//ʹ��std�����ռ�
//using namespace std;
//int my_main()
//{
//	cout << "hello word:";
//	string name;
//	cin >> name;
//	cout << '\n';
//	cout << "hello,";
//	cout << name;
//	cout << "��and goodbye!\n ";
//	return 0;
//}

//3��ʵ��һ������Ĵ���
using namespace std;
int main()
{
	//int seq_size = 10;
	int elem_vals[10] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> elem_seq(elem_vals, elem_vals + 10);//������������ʼ��
	cout << "the first " << elem_seq.size()//����elem_seq���vector
		<< " elemnt of the Pell Series:\n\t";
	for (int i = 0; i < elem_seq.size(); i++)
	{
		cout << pell_seq[i] << ' ';
	}
	return 0;
}//û����ɹ���������Ҫ���¿�һ�¡�Essential C++���ĵ�һ��
