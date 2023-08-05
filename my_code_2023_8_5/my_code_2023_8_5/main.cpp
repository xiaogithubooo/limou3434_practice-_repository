#include <iostream>
#include <string>

int main() 
{
    std::string str;
    
    //使用范围for循环遍历字符串中的每个字符
    std::cout << "大小 = " << str.size() << std::endl;
    std::cout << "容量 = " << str.capacity() << std::endl;
    //size()是string类内部的成员函数，
    //可以求得string对象内部存储的字符串大小，
    //而capacity()则是求得容量大小
    //后续还会继续讲解

    return 0;
}

//#include <iostream>
//#include <string>
//int main() 
//{
//    std::string str = "Hello";
//    
//    //使用范围for循环遍历字符串中的每个字符
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
//	//创建多个string对象
//	std::string str1, str2, str3, str4;
//	
//	str1 = "hello";						//赋值C风格的字符串(2)
//	std::cout << str1 << std::endl;
//
//	str2 = 'x';							//赋值单字符(3)
//	std::cout << str2 << std::endl;
//
//	str3 = str1 + str2;					//赋值string对象(1)
//	std::cout << str3 << std::endl;
//
//	str3 = { 'H', 'E', 'L', 'L', 'O' };	//初始化列表赋值(4)
//	std::cout << str3 << std::endl;
//
//	str4 = std::move(str3);				//移动构造(5)
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
//    //使用构造函数构造源string对象
//    std::string source = "Hello World";
//    
//    //使用移动构造函数转移资源
//    std::string target(std::move(source));
//    
//    std::cout << "target = " << target << std::endl;//输出：target = Hello World
//    std::cout << "source = " << source << std::endl;//输出：source = （source的内容已被移动）
//    
//    return 0;
//}

//#include <iostream>
//#include <string>
//int main()
//{
//    //直接初始化一个字符串
//    std::string str1("Hello World");
//    std::cout << "str1(\"Hello World\") = "
//        << str1 << std::endl;
//
//    //使用迭代器范围构造一个新的字符串
//    std::string str2(str1.begin(), str1.begin() + 7);
//
//    //输出：str2: Hello
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