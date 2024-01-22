//字符串拼接
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
	stringstream ss;
	//将多个字符串放入 ss 中
	ss << "first" << " " << "string,";
	ss << " second string";
	cout << "strResult is: " << ss.str() << endl;

	//清空 ss
	ss.str("");
	ss << "third string";
	cout << "After clear, strResult is: " << ss.str() << endl;
	return 0;
}