//��ֵ���ص�ʹ��
#include <iostream>
#include <string>
using std::cout;
using std::string;

int main()
{
    string str1, str2, str3, str4; //������� string ����

    //string& operator= (const char* s);
    str1 = "hello"; //��ֵ C �����ַ���
    cout << str1 << '\n';

    //string& operator= (char c);
    str2 = 'x'; //��ֵ�����ַ�
    cout << str2 << '\n';

    //string& operator= (const string& str);
    str3 = str1 + str2; //��ֵ string ����
    cout << str3 << '\n';

    return 0;
}

//#include <iostream>
//#include <string>
//using std::cout;
//using std::string;
//
//void Test1()
//{
//    //string();
//    /* Ĭ�ϵĹ��캯�������ú�ṹ��һ������Ϊ 0 �Ŀ��ַ�����������һ���ĳ�ʼ������ */
//    cout << "-- Test1():default --" << '\n';
//
//    string str;
//    cout << "��С = " << str.size() << '\n';
//    cout << "���� = " << str.capacity() << '\n';
//    cout << str << "\n\n";
//}
//
//void Test2()
//{
//    //string(const char* s); 
//    /* ���ù��캯���󣬻�ʹ�� C �����ַ��������� string ���� str */
//    cout << "-- Test2():from c-string --" << '\n';
//
//    string str("limou3434"); 
//    //std::string str = "limou3434"; //����ʹ�����ַ������� string �� str ����
//    cout << "��С = " << str.size() << '\n';
//    cout << "���� = " << str.capacity() << '\n';
//    cout << str << "\n\n";
//}
//
//void Test3()
//{
//    //string(const string& str);
//    /* �����е� string ������п��� */
//    cout << "-- Test3():copy --" << '\n';
//
//    string src = "Hello";
//    string copy = src; //���﷢���˿������죬Ҳ���Ǹ��� str ����һ���µ� string ����
//    cout << "��С = " << copy.size() << '\n';
//    cout << "���� = " << copy.capacity() << '\n';
//    cout << src << "\n\n";
//}
//
//void Test4()
//{
//    //string(const string& str, size_t pos, size_t len = npos);
//    /* �����е� string ���� str �Ĳ��ֵ��ַ����ַ����д� pos ��ʼ����Ϊ len ���Ӵ����֣�
//    ����������һ���µ� string �������û��ָ�� len ��ֵ������ str �϶̣���һֱ������ str �Ľ�β */
//    cout << "-- Test4():substring --" << '\n';
//
//    string str = "limou3434";
//
//    string sub1(str, 2, 4); //����Դ�ַ����� 2 ��ʼ�ĳ���Ϊ 4 ���Ӵ�
//    cout << sub1 << '\n';
//
//    string sub2(str, 2); //����Դ�ַ��������� 2 ��ʼ����������ַ�
//    cout << sub2 << '\n';
//
//    string sub3(str, 2, 1000); //Դ�ַ���̫С��ʵ��ֻȡ���� 2 ��ʼ���������ַ�
//    cout << sub3 << "\n\n";
//}
//
//void Test5()
//{
//    //string(size_t n, char c);
//    /* �� n ����ͬ�� c �ַ���������ַ����� */
//    cout << "-- Test5():fill --" << '\n';
//
//    string str(5, 'c');
//    cout << str << "\n\n";
//}
//
//void Test6()
//{
//    //template <class InputIterator>
//    //string(InputIterator first, InputIterator last);
//    /* ��Դ string ������ͬ��˳��������Դ string ������
//    ��������ΧΪ [first,last) ���ַ����У�������µ� string ����
//    �������ǻ�û��ѧ�����������������ֱ���ϴ���ۿ���������ʹ�ü���*/
//
//    //ֱ�ӳ�ʼ��һ���ַ���
//    cout << "-- Test6():range --" << '\n';
//    string str1("Hello World");
//    cout << "str1(\"Hello World\") = "
//        << str1 << std::endl;
//
//    //ʹ�õ�������Χ����һ���µ��ַ���
//    string str2(str1.begin() + 1, str1.begin() + 7); //���� begin() ���ǵ�������ʹ�ã������Լ����Ϊ��һ��ָ�룬ָ������� string ������ַ�����ͷλ�ã��������ĳ��־���Ϊ������ʹ��һЩ�����������ָ��һ��ʹ��
//
//    //����Ӵ�
//    cout << "str2(str1.begin() + 1, str1.begin() + 7) = "
//        << str2 << std::endl;
//}
//
//int main()
//{
//    Test1();
//    Test2();
//    Test3();
//    Test4();
//    Test5();
//    Test6();
//    return 0;
//}