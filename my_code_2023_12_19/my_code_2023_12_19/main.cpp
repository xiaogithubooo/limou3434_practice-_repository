////���л��ͷ����л�����
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
//    string _name = "name";      //����
//    int _id = 0;                //id
//    Date _date = { 2000,1,1 };  //ʱ��
//    string _msg = "msg";        //������Ϣ
//};
//
//int main()
//{
//    //1.�ṹ��Ϣ���л�Ϊ�ַ���
//    ChatInfo winfo = { "limou", 114514, { 2023, 12, 19 }, "�������ϳ�ʲô��" };
//    ostringstream oss;
//    oss << winfo._name << " "
//        << winfo._id << " " 
//        << winfo._date << " "
//        << winfo._msg;
//
//    string str = oss.str();
//    cout << str << '\n';
//    //ͨ�����磬������ַ������͸�����
//    //һ���ѡ�� Json��xml �ȷ�ʽ���и��õ�֧�֣���������Ϣ�õ��ļ���
//    
//    //2.�ַ��������ɽṹ��Ϣ
//    ChatInfo rInfo;
//    istringstream iss(str);
//    iss >> rInfo._name >> rInfo._id >> rInfo._date >> rInfo._msg;
//    cout << "-------------------------------------------------------" << '\n';
//    cout << "����:" << rInfo._name << "(" << rInfo._id << ") " << '\n';
//    cout << "ʱ��:" << rInfo._date << '\n';
//    cout << "��Ϣ:" << rInfo._name << ":>" << rInfo._msg << endl;
//    cout << "-------------------------------------------------------" << '\n';
//    return 0;
//}
//
////�ַ���ƴ��
////#include <sstream>
////#include <iostream>
////using namespace std;
////
////int main()
////{
////	stringstream sstream;
////	//������ַ������� sstream ��
////	sstream << "first" << " " << "string,";
////	sstream << " second string";
////	cout << "strResult is: " << sstream.str() << endl;
////	
////	//��� sstream
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
////    //��һ�����α���ת��Ϊ�ַ������洢�� string �������
////    int int_a = 114514;
////    s << int_a;
////    s >> str;
////    cout << str << '\n';
////    cout << s.str() << '\n'; //str() ���� stringsteam �й���� string ��Ա
////
////    //���ת��ʱ������ʹ�� clear() ���ϴ�ת��״̬��յ�
////    //stringstreams ��ת����βʱ�������һ��ת���󣩣��Ὣ���ڲ�״̬����Ϊ badbit
////    //�����һ��ת���Ǳ������ clear() ��״̬����Ϊ goodbit �ſ���ת��
////    //���� clear() ���Ὣ stringstreams �ײ��ַ�����յ�
////    //������� stringstream �ײ���� string �������ó� "",
////    //���ת��ʱ���Ὣ���ȫ���ۻ��ڵײ� string ������
////    s.str("");
////    s.clear();
////
////    //��һ���������ת��Ϊ�ַ������洢�� string �������
////    double d = 3.14159;
////    s << d;
////    s >> str;
////    cout << str << '\n';
////    cout << s.str() << '\n'; //str() ���� stringsteam �й���� string ��Ա
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
////	//����ʹ�� string������ͱ��д��ָ���ַ�����ָ����Ϣ�ˣ�
////	//�������ַ��������� string �ͷź�ͻᵼ��ָ����Ұָ�룬
////	//��ȡ��ʱ��ͻ���Ұָ������ã���˶����ƶ�д�Ͳ�Ҫʹ�����ַ�ʽ��
////	//�����ı����벻�����ⷽ������⣬��Ϊ����ת��Ϊ�ַ�����д��
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
////		ofstream ofs(_fileName, ofstream::out | ofstream::binary); //����������
////		ofs.write((char*)&info, sizeof(info));
////	}
////
////	void ReadBin(Serverinfo& info)
////	{
////		ifstream ifs(_fileName, ofstream::in | ofstream::binary); //����������
////		ifs.read((char*)&info, sizeof(info));
////	}
////
////	void WriteText(const Serverinfo& info)
////	{
////		//C ������Ҫ����ת��Ϊ�ַ����ٶ�д������ C++ ͨ�����������Զ������������
////		ofstream ofs(_fileName); //�ı�����
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
////	Serverinfo winfo = { "190.0.0.0", 80, {1, 2, 3} }; //����������Ϣ
////
////	Serverinfo rinfo1; //��ȡ����������Ϣ
////	ConfigManager cmb("limouBin"); //��Ϣ�ļ�·��
////	cmb.WriteBin(winfo); //д����Ϣ
////	cmb.ReadBin(rinfo1);
////	cout << rinfo1._address << "-" << rinfo1._port << ":"
////		<< rinfo1._data._data1 << "-"
////		<< rinfo1._data._data2 << "-"
////		<< rinfo1._data._data3 << '\n';
////
////	
////	Serverinfo rinfo2; //��ȡ����������Ϣ
////	ConfigManager cmt("limouText.txt"); //��Ϣ�ļ�·��
////	cmt.WriteText(winfo); //д����Ϣ
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
//////	while (d) //����û������ _data1 Ϊ 0����ֹͣѭ��
//////	{
//////		cin >> d;
//////		cout << d;
//////	}
//////	return 0;
//////}