//string 的成员对象 cin 的输入用法
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	char ch = 0;


	//第一种输入（跳过输入流中的所有空格字符，直到遇到非空格字符为止，开始读取）
	cout << "第一种输入:" << '\n';
	for (int i = 0; i < 5; i++)
	{
		cin >> str;
		cout << "str:" << str << '\n';
		ch = cin.get(); //只读取一个字符，去除换行符（这里可以不用，是因为就算被 str 读取了也会被跳过）
	}
	//ch = cin.get(); //如果上面循环中的 ch = cin.get(); 不用那么这里就应该加上 ch = cin.get(); 否则影响后面输入


	//第二种输入（跳过输入流中的所有 ',' 字符，直到遇到非 ',' 字符为止，开始读取）
	cout << "第二种输入:" << '\n';
	for (int i = 0; i < 5; i++)
	{
		getline(cin, str, ',');
		cout << "str:" << str << '\n';
		if (i == 5)
			break;
		ch = cin.get(); //只读取一个字符，去除换行符
	}


	//第三种输入（一直读取输入，直到遇到换行符，并且直接抛弃换行符，不放回输入缓冲）
	cout << "第三种输入:" << '\n';
	getline(cin, str);
	cout << "str:" << str << '\n';

	return 0;
}

//#include <iostream> //streamsize
//#include <string>
//#include <limits> //numeric_limits
//
//using namespace std;
//
//int main()
//{
//	int number = 0;
//	cin >> number;
//	if (cin.fail()) //判断 cin 的状态，若 cin 为错误状态则返回 true, 正常状态则返回 false
//	{
//		cout << "发生错误" << endl;
//		cin.clear(); //清除cin的错误状态（重要）
//		in.ignore(numeric_limits<streamsize>::max(), '\n');  //忽略缓冲区中的所有字符，直到遇到换行符为止（重要）
//	
//		/* 其中std::numeric_limits 是一个模板类，用于获取各种数值类型（如整数、浮点数等）的特征信息 */
//	}
//	else
//	{
//		cout << "number:" << number << endl;
//	}
//
//	//如果不清除状态，代码后续的 cin 都不会被执行，并且原先的输入数据仍然留在缓冲区中
//	//如果清除状态后，没有清除缓冲区，则原先留在缓冲区的数据会被 cin 继续读取
//	char character = 0;
//	cin >> character;
//	cout << "character:" << character << endl;
//	return 0;
//}