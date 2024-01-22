//文件流接口演示
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//描述数据的类
struct Data
{
	int _data1;
	int _data2;
	int _data3;
};

//描述服务器的类
struct Serverinfo
{
	char _address[32]; //地址
	//这里的 _address 不能使用 string 类型，否则二进制写入就回变成写入指向字符串的“指针信息”，而不是“字符串”本身（string 本身的成员有：指向字符串的指针、字符串的大小、存储的容量），
	//在 string 释放后就会导致指向字符串的指针变成“野指针”，因此读取的时候就会变成野指针解引用，这有可能导致程序奔溃（本质上就是浅拷贝问题）
	//(1)在同一个进程下，可能只是浅拷贝问题（输出结果有可能对）
	//(2)但是在两个进程的情况下，就必然会出现野指针解引用（写入的进程将指针指向的资源销毁了）
	//因此二进制读写的时候，最好不要用容器，否则很容易出现类似的问题
	//但是文本输入不会在这方面出问题，因为 string 对象会被提前转化为“字符串”后再写入，不会简单进行浅拷贝

	int _port; //端口
	Data _data; //数据
};

//描述操作的管理器
class ConfigManager
{
	/* 封装各种文件流的操作 */
public:
	ConfigManager(const char* fileName)
		: _fileName(fileName)
	{}

	void WriteBin(const Serverinfo& info)
	{
		ofstream ofs(_fileName, ofstream::out | ofstream::binary); //二进制写入（ofstream::out 可忽略，ofstream::binary 表示二进制操作）
		ofs.write((char*)&info, sizeof(info));
	}

	void ReadBin(Serverinfo& info)
	{
		ifstream ifs(_fileName, ofstream::in | ofstream::binary); //二进制读取（ofstream::in 可忽略，ofstream::binary 表示二进制操作）
		ifs.read((char*)&info, sizeof(info));
	}

	//文本写入/读取时，C 语言需要将数据不断转化为字符串再读写，但是 C++ 通过运算重载自动化了这个过程
	
	void WriteText(const Serverinfo& info)
	{
		ofstream ofs(_fileName); //文本写入，直接使用流操作符即可
		ofs << info._address << " "
			<< info._port << " "
			<< info._data._data1 << " "
			<< info._data._data2 << " "
			<< info._data._data3 << '\n';
	}

	void ReadText(Serverinfo& info)
	{
		ifstream ifs(_fileName); //文本读取，直接使用流操作符即可
		ifs >> info._address
			>> info._port
			>> info._data._data1
			>> info._data._data2
			>> info._data._data3;
	}

private:
	string _fileName;
};

int main()
{
	Serverinfo winfo = {
		"190.0.0.0", 80, {1, 2, 3}
	}; //服务器传递的信息

	//模拟程序 A（二进制读写）
	Serverinfo rinfo1; //读取服务器的信息
	ConfigManager cmb("limouBin"); //信息文件路径
	cmb.WriteBin(winfo); //写入信息
	cmb.ReadBin(rinfo1);
	cout << rinfo1._address << "-" << rinfo1._port << ":"
		<< rinfo1._data._data1 << "-"
		<< rinfo1._data._data2 << "-"
		<< rinfo1._data._data3 << '\n';

	//模拟程序 B（文本读写）
	Serverinfo rinfo2; //读取服务器的信息
	ConfigManager cmt("limouText.txt"); //信息文件路径
	cmt.WriteText(winfo); //写入信息
	cmt.ReadText(rinfo2);
	cout << rinfo2._address << "-" << rinfo2._port << ":"
		<< rinfo2._data._data1 << "-"
		<< rinfo2._data._data2 << "-"
		<< rinfo2._data._data3 << '\n';

	return 0;
}