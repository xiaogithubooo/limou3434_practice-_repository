#include <iostream>
#include <string>

int main() 
{
    std::string str;
    
    //ʹ�÷�Χforѭ�������ַ����е�ÿ���ַ�
    std::cout << "��С = " << str.size() << std::endl;
    std::cout << "���� = " << str.capacity() << std::endl;
    //size()��string���ڲ��ĳ�Ա������
    //�������string�����ڲ��洢���ַ�����С��
    //��capacity()�������������С
    //���������������

    return 0;
}

//#include <iostream>
//#include <string>
//int main() 
//{
//    std::string str = "Hello";
//    
//    //ʹ�÷�Χforѭ�������ַ����е�ÿ���ַ�
//    for (auto ch : str) 
//    {
//        std::cout << ch << " ";
//    }
//    return 0;
//}


//#include <iostream>
//#include <string>
//int main()
//{
//	//�������string����
//	std::string str1, str2, str3, str4;
//	
//	str1 = "hello";						//��ֵC�����ַ���(2)
//	std::cout << str1 << std::endl;
//
//	str2 = 'x';							//��ֵ���ַ�(3)
//	std::cout << str2 << std::endl;
//
//	str3 = str1 + str2;					//��ֵstring����(1)
//	std::cout << str3 << std::endl;
//
//	str3 = { 'H', 'E', 'L', 'L', 'O' };	//��ʼ���б�ֵ(4)
//	std::cout << str3 << std::endl;
//
//	str4 = std::move(str3);				//�ƶ�����(5)
//	std::cout << str3 << std::endl;
//	std::cout << str4 << std::endl;
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//
//int main()
//{
//    //ʹ�ù��캯������Դstring����
//    std::string source = "Hello World";
//    
//    //ʹ���ƶ����캯��ת����Դ
//    std::string target(std::move(source));
//    
//    std::cout << "target = " << target << std::endl;//�����target = Hello World
//    std::cout << "source = " << source << std::endl;//�����source = ��source�������ѱ��ƶ���
//    
//    return 0;
//}

//#include <iostream>
//#include <string>
//int main()
//{
//    //ֱ�ӳ�ʼ��һ���ַ���
//    std::string str1("Hello World");
//    std::cout << "str1(\"Hello World\") = "
//        << str1 << std::endl;
//
//    //ʹ�õ�������Χ����һ���µ��ַ���
//    std::string str2(str1.begin(), str1.begin() + 7);
//
//    //�����str2: Hello
//    std::cout << "str2(str1.begin(), str1.begin() + 7) = " 
//        << str2 << std::endl;  
//
//    return 0;
//}

//#include <iostream>
//#include <string>
//int main()
//{
//	const char* arr = "abcd";
//	std::string a(arr, 2);
//	std::cout << a << std::endl;
//	return 0;
//}