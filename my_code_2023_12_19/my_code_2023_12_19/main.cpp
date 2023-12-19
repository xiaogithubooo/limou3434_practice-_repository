////序列化和反序列化数据
//#include <sstream>
//#include <iostream>
//using namespace std;
//
//struct Date
//{
//    int _year = 2023;
//	int _month = 12;
//	int _day = 19;
//};
//istream& operator>>(istream& in, Date& d)
//{
//    return in >> d._year >> d._month >> d._day;
//}
//ostream& operator<<(ostream& out, const Date& d)
//{
//    return out << d._year << " " << d._month << " " << d._day;
//}
//
//struct ChatInfo
//{
//    string _name = "name";      //名字
//    int _id = 0;                //id
//    Date _date = { 2000,1,1 };  //时间
//    string _msg = "msg";        //聊天信息
//};
//
//int main()
//{
//    //1.结构信息序列化为字符串
//    ChatInfo winfo = { "limou", 114514, { 2023, 12, 19 }, "今天晚上吃什么？" };
//    ostringstream oss;
//    oss << winfo._name << " "
//        << winfo._id << " " 
//        << winfo._date << " "
//        << winfo._msg;
//
//    string str = oss.str();
//    cout << str << '\n';
//    //通过网络，将这个字符串发送给对象
//    //一般会选用 Json、xml 等方式进行更好的支持（是描述信息用的文件）
//    
//    //2.字符串解析成结构信息
//    ChatInfo rInfo;
//    istringstream iss(str);
//    iss >> rInfo._name >> rInfo._id >> rInfo._date >> rInfo._msg;
//    cout << "-------------------------------------------------------" << '\n';
//    cout << "姓名:" << rInfo._name << "(" << rInfo._id << ") " << '\n';
//    cout << "时间:" << rInfo._date << '\n';
//    cout << "消息:" << rInfo._name << ":>" << rInfo._msg << endl;
//    cout << "-------------------------------------------------------" << '\n';
//    return 0;
//}
//
////字符串拼接
////#include <sstream>
////#include <iostream>
////using namespace std;
////
////int main()
////{
////	stringstream sstream;
////	//将多个字符串放入 sstream 中
////	sstream << "first" << " " << "string,";
////	sstream << " second string";
////	cout << "strResult is: " << sstream.str() << endl;
////	
////	//清空 sstream
////	sstream.str("");
////	sstream << "third string";
////	cout << "After clear, strResult is: " << sstream.str() << endl;
////	return 0;
////}
//
//
////int main()
////{
////    string str;
////    stringstream s;
////
////    //将一个整形变量转化为字符串，存储到 string 类对象中
////    int int_a = 114514;
////    s << int_a;
////    s >> str;
////    cout << str << '\n';
////    cout << s.str() << '\n'; //str() 返回 stringsteam 中管理的 string 成员
////
////    //多次转换时，必须使用 clear() 将上次转换状态清空掉
////    //stringstreams 在转换结尾时（即最后一个转换后），会将其内部状态设置为 badbit
////    //因此下一次转换是必须调用 clear() 将状态重置为 goodbit 才可以转换
////    //但是 clear() 不会将 stringstreams 底层字符串清空掉
////    //如果不将 stringstream 底层管理 string 对象设置成 "",
////    //多次转换时，会将结果全部累积在底层 string 对象中
////    s.str("");
////    s.clear();
////
////    //将一个浮点变量转化为字符串，存储到 string 类对象中
////    double d = 3.14159;
////    s << d;
////    s >> str;
////    cout << str << '\n';
////    cout << s.str() << '\n'; //str() 返回 stringsteam 中管理的 string 成员
////    
////    return 0;
////}
//
//
////#include <string>
////#include <fstream>
////#include <iostream>
////using namespace std;
////
////struct Data
////{
////	int _data1;
////	int _data2;
////	int _data3;
////};
////
////struct Serverinfo
////{
////	char _address[32]; 
////	//不能使用 string，否则就变成写入指向字符串的指针信息了，
////	//而不是字符串本身，在 string 释放后就会导致指针变成野指针，
////	//读取的时候就会变成野指针解引用，因此二进制读写就不要使用这种方式，
////	//但是文本输入不会在这方面出问题，因为会先转化为字符串再写入
////
////	int _port;
////	Data _data;
////};
////
////class ConfigManager
////{
////public:
////	ConfigManager(const char* fileName)
////		: _fileName(fileName)
////	{}
////
////	void WriteBin(const Serverinfo& info)
////	{
////		ofstream ofs(_fileName, ofstream::out | ofstream::binary); //二进制输入
////		ofs.write((char*)&info, sizeof(info));
////	}
////
////	void ReadBin(Serverinfo& info)
////	{
////		ifstream ifs(_fileName, ofstream::in | ofstream::binary); //二进制输入
////		ifs.read((char*)&info, sizeof(info));
////	}
////
////	void WriteText(const Serverinfo& info)
////	{
////		//C 语言需要不断转化为字符串再读写，但是 C++ 通过运算重载自动化了这个过程
////		ofstream ofs(_fileName); //文本输入
////		ofs << info._address << " "
////			<< info._port << " "
////			<< info._data._data1 << " "
////			<< info._data._data2 << " "
////			<< info._data._data3 << '\n';
////	}
////
////	void ReadText(Serverinfo& info)
////	{
////		ifstream ifs(_fileName);
////		ifs >> info._address
////			>> info._port
////			>> info._data._data1
////			>> info._data._data2
////			>> info._data._data3;
////	}
////
////private:
////	string _fileName;
////};
////
////int main()
////{
////	Serverinfo winfo = { "190.0.0.0", 80, {1, 2, 3} }; //服务器的信息
////
////	Serverinfo rinfo1; //读取服务器的信息
////	ConfigManager cmb("limouBin"); //信息文件路径
////	cmb.WriteBin(winfo); //写入信息
////	cmb.ReadBin(rinfo1);
////	cout << rinfo1._address << "-" << rinfo1._port << ":"
////		<< rinfo1._data._data1 << "-"
////		<< rinfo1._data._data2 << "-"
////		<< rinfo1._data._data3 << '\n';
////
////	
////	Serverinfo rinfo2; //读取服务器的信息
////	ConfigManager cmt("limouText.txt"); //信息文件路径
////	cmt.WriteText(winfo); //写入信息
////	cmt.ReadText(rinfo2);
////	cout << rinfo2._address << "-" << rinfo2._port << ":"
////		<< rinfo2._data._data1 << "-"
////		<< rinfo2._data._data2 << "-"
////		<< rinfo2._data._data3 << '\n';
////
////	return 0;
////}
////
//////#include <iostream>
//////using namespace std;
//////
//////class Data
//////{
//////	friend istream& operator>>(istream& in, Data& d);
//////	friend ostream& operator<<(ostream& out, const Data& d);
//////
//////public:
//////	operator bool() const
//////	{
//////		if (_data1 == 0)
//////			return false;
//////		else
//////			return true;
//////	}
//////
//////private:
//////	int _data1 = 10;
//////	int _data2 = 20;
//////};
//////
//////istream& operator>>(istream& in, Data& d)
//////{
//////	in >> d._data1 >> d._data2;
//////	return in;
//////}
//////
//////ostream& operator<<(ostream& out, const Data& d)
//////{
//////	cout << d._data1 << "-" << d._data2 << '\n';
//////	return out;
//////}
//////
//////int main()
//////{
//////	Data d;
//////	while (d) //如果用户输出了 _data1 为 0，则停止循环
//////	{
//////		cin >> d;
//////		cout << d;
//////	}
//////	return 0;
//////}