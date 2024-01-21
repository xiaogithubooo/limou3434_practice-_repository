#include <iostream>
#include <string>
using namespace std;

int main()
{

	//第一种输入（忽略空格、忽略换行符）
	string str;
	cin >> str;
	cout << "str:" << str << endl;
	cin.get(); //只读取一个字符

	//第二种输入（读取输入，直到遇到换行符，并且抛弃换行符）
	getline(cin, str);
	const char* s = str.c_str();
	cout << "str:" << str << endl;
	cin.get(); //只读取一个字符

	//第三种输入（）
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