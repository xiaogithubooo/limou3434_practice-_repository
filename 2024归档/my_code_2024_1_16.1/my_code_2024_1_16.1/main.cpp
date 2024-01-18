//赋值重载的使用
#include <iostream>
#include <string>
using std::cout;
using std::string;

int main()
{
    string str1, str2, str3, str4; //创建多个 string 对象

    //string& operator= (const char* s);
    str1 = "hello"; //赋值 C 风格的字符串
    cout << str1 << '\n';

    //string& operator= (char c);
    str2 = 'x'; //赋值单个字符
    cout << str2 << '\n';

    //string& operator= (const string& str);
    str3 = str1 + str2; //赋值 string 对象
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
//    /* 默认的构造函数，调用后会构造一个长度为 0 的空字符串（但是有一定的初始容量） */
//    cout << "-- Test1():default --" << '\n';
//
//    string str;
//    cout << "大小 = " << str.size() << '\n';
//    cout << "容量 = " << str.capacity() << '\n';
//    cout << str << "\n\n";
//}
//
//void Test2()
//{
//    //string(const char* s); 
//    /* 调用构造函数后，会使用 C 风格的字符串来构造 string 对象 str */
//    cout << "-- Test2():from c-string --" << '\n';
//
//    string str("limou3434"); 
//    //std::string str = "limou3434"; //或者使用这种方法构造 string 的 str 对象
//    cout << "大小 = " << str.size() << '\n';
//    cout << "容量 = " << str.capacity() << '\n';
//    cout << str << "\n\n";
//}
//
//void Test3()
//{
//    //string(const string& str);
//    /* 对现有的 string 对象进行拷贝 */
//    cout << "-- Test3():copy --" << '\n';
//
//    string src = "Hello";
//    string copy = src; //这里发生了拷贝构造，也就是复制 str 构造一个新的 string 对象。
//    cout << "大小 = " << copy.size() << '\n';
//    cout << "容量 = " << copy.capacity() << '\n';
//    cout << src << "\n\n";
//}
//
//void Test4()
//{
//    //string(const string& str, size_t pos, size_t len = npos);
//    /* 对现有的 string 对象 str 的部分的字符（字符串中从 pos 开始长度为 len 的子串部分）
//    来拷贝构造一个新的 string 对象，如果没有指定 len 的值，或者 str 较短，则一直拷贝到 str 的结尾 */
//    cout << "-- Test4():substring --" << '\n';
//
//    string str = "limou3434";
//
//    string sub1(str, 2, 4); //拷贝源字符串从 2 开始的长度为 4 的子串
//    cout << sub1 << '\n';
//
//    string sub2(str, 2); //拷贝源字符串从索引 2 开始往后的所有字符
//    cout << sub2 << '\n';
//
//    string sub3(str, 2, 1000); //源字符串太小，实际只取得了 2 开始完后的所有字符
//    cout << sub3 << "\n\n";
//}
//
//void Test5()
//{
//    //string(size_t n, char c);
//    /* 用 n 个相同的 c 字符连续填充字符串。 */
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
//    /* 和源 string 对象相同的顺序，来复制源 string 对象中
//    迭代器范围为 [first,last) 的字符序列，构造出新的 string 对象
//    由于我们还没有学过迭代器，因此我们直接上代码观看迭代器的使用即可*/
//
//    //直接初始化一个字符串
//    cout << "-- Test6():range --" << '\n';
//    string str1("Hello World");
//    cout << "str1(\"Hello World\") = "
//        << str1 << std::endl;
//
//    //使用迭代器范围构造一个新的字符串
//    string str2(str1.begin() + 1, str1.begin() + 7); //这里 begin() 就是迭代器的使用，您可以简单理解为有一个指针，指向了这个 string 对象的字符串开头位置，迭代器的出现就是为了能是使得一些对象可以类似指针一样使用
//
//    //输出子串
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