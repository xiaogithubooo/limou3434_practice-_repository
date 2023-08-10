#include <iostream>
#include <string>
using namespace std;
#define NUMBER 100
void test_1()
{
	string str;
	size_t old = str.capacity();
	cout << "Init:" << old << endl;
	size_t newValue = 0;
	for (size_t i = 0; i < NUMBER; i++)
	{
		str.push_back('x');//推送
		newValue = str.capacity();//记录新值
		if (newValue != old)//新值和旧值对比
		{
			cout << "dilatation = " << newValue << " ";
			old = newValue;
			cout << endl;
		}
	}
	cout << endl;
}
void test_2()
{
	string str("abcd");
	cout << str << endl;
	str.append("x");
	cout << str << endl;
	str.push_back('x');
	cout << str << endl;
	str += 'x';
	cout << str << endl;
	str += "x";
	cout << str << endl;
}
void test_3()
{
	string str1;
	cin >> str1;
	cout << "str1:" << str1 << endl;
	
	string str2;
	getline(cin, str2);
	cout << "str2:" << str2 << endl;

	string str3;
	getline(cin, str3, '$');//遇到$就停止读取，抛弃掉$，不再进入后续的输入
	cout << "str3:" << str3 << endl;

	string str4;
	getline(cin, str4);//遇到$就停止读取，抛弃掉$，不再进入后续的输入
	cout << "str4:" << str4 << endl;
}
void test_4()
{
	string str1 = "abcdef";
	string str2 = "xxxxxx";
	str1.assign(str2);
	cout << str1 << endl;
	cout << str2 << endl;
}
void test_5()
{
	string str = "abcdef";
	cout << str << endl;

	str.erase(str.begin() + 3);
	cout << str << endl;

	str.erase(str.begin(), str.end() - 2);
	cout << str << endl;
	
	str.erase();
	cout << str << endl;
}
void test_6()
{
	string str = "abc def";
	cout << str << endl;

	str.replace(3, 2, "&%#");//将str索引为3起始的长度为2的子串替换成"&%#"
	cout << str << endl;
}
void test_7()
{
	//设计一个算法让下面string对象的空格改为20%
	string str = "abc def";
	string strx;
	cout << str << endl;
	//空间换时间
	for (auto ch : str)
	{
		if (ch != ' ')
		{
			strx += ch;
		}
		else
		{
			strx += "20%";
		}
	}
	str = strx;
	cout << str << endl;
	//这样的效率都会比较高
}
void test_8()
{
	string str1 = "xxx_big_apple_xxx";
	string str2 = "be";
	cout << str1.find_first_of(str2, 0) << endl;//输出4
	cout << str1.find_first_of(str2, 5) << endl;//输出12
}
void test_9()
{
	//1.输入网址url
	string url;//https->://baidu.com->/limou/file/text
	cin >> url;
	
	//2.寻找并且拆解url
	string protocol;//协议
	string domain;//域名
	string resource;//资源
	//2.1.寻找协议
	int index1 = url.find(":");//5
	if (index1 == string::npos)
	{
		cout << "没有协议，退出程序" << endl;
		exit(-1);
	}
	//2.2.寻找域名
	int index2 = url.find("/", index1 + 3);//17
	if (index2 == string::npos)
	{
		index2 = url.size();
	}
	//2.3.赋值三个对象
	protocol = url.substr(0, index1);
	domain = url.substr(index1 + 3, index2 - (index1 + 3));//17-5-3 = 12-3 = 9
	if (index2 != url.size())
	{
		resource = url.substr(index2 + 1);
	}

	//3.输出结果
	cout << "protocol = " << protocol << endl;
	if (domain.size() != 0)
	{
		cout << "domain = " << domain << endl;
	}
	else
	{
		cout << "没有域名" << endl;
	}
	if(resource.size() != 0)
	{ 
		cout << "resource = " << resource << endl;
	}
	else
	{
		cout << "没有资源" << endl;
	}
}
void test_10()
{
	string str1 = "xxx_big_apple_xxx";
	string str2 = "be";
	cout << str1.find_last_of(str2, str1.size() - 1) << endl;//输出12
	cout << str1.find_last_of(str2, 11) << endl;//输出4
}
void test_11()
{
	string str("saldgcaslucdgleakjslaejcsfkajsasducgiasfg");
	size_t index = str.find_first_not_of("abcdef", 0);
	cout << str << endl;
	while (index != string::npos)
	{
		str[index] = '*';
		index = str.find_first_not_of("abcdef", index + 1);
	}
	cout << str << endl;
}
void test_12()
{
	class Solution {
	public:
		bool IsLetter(const char& ch)
		{
			if ((ch >= 'a' && ch <= 'z')
				|| (ch >= 'A' && ch <= 'Z'))
			{
				return true;
			}
			return false;
		}
		string reverseOnlyLetters(string str)
		{
			auto begin = 0;
			auto end = str.size() - 1;
			while (begin < end)
			{
				while (!IsLetter(str[begin]) && begin < end)
				{
					begin++;
				}
				while (!IsLetter(str[end]) && begin < end)
				{
					end--;
				}
				swap(str[begin], str[end]);
				begin++;
				end--;
			}
			return str;
		}
	};
}
void test_13()
{
	//1.输入字符句子
	string str;
	getline(cin, str);//hello nowcode
	//2.逆向寻找
	size_t index = str.rfind(" ");//得到5
	cout << str.size() - index - 1 << endl;//13-5 = 8
}
void test_14()
{
	class Solution
	{
	public:
		bool IsLetterAndNumber(const char& ch)//判断是否为字符或者数字
		{
			return((ch >= 'a' && ch <= 'z')
				|| (ch >= 'A' && ch <= 'Z')
				|| (ch >= '0' && ch <= '9'));
		}
		bool IsOk(char x, char y)//判断是否构成回文的特征
		{
			if (x == y)
			{
				return true;
			}
			if ((x >= 'a' && x <= 'z') && (y >= 'A' && y <= 'Z'))
			{
				if (x - 'a' + 'A' == y)
				{
					return true;
				}
			}
			else if ((y >= 'a' && x <= 'z') && (x >= 'A' && x <= 'Z'))
			{
				if (y - 'a' + 'A' == x)
				{
					return true;
				}
			}
			return false;
		}
		bool isPalindrome(string str)
		{
			//1.取得首尾索引
			//str = "A man, a plan, a canal: Panama"
			int begin = 0;//s[begin] = 'A' 
			int end = str.size() - 1;//str[end] = 'a'

			//2.循环判断回文
			while (begin < end)
			{
				while (begin < end && !IsLetterAndNumber(str[begin]) )
				{
					begin++;
				}
				while (begin < end && !IsLetterAndNumber(str[end]) )
				{
					end--;
				}
				if (!IsOk(str[begin], str[end]))//如果判断出是相同的就返回true
				{
					return false;
				}
				begin++;
				end--;
			}
			return true;
		}
	};
	string str = "0P";
	Solution s;
	cout << s.isPalindrome(str);
}
void test_15()
{
	class Solution
	{
	public:
		void Reversal(string& strReturn)
		{
			int begin = 0;
			int end = strReturn.size() - 1;
			while (begin < end)
			{
				char ch = strReturn[begin];
				strReturn[begin] = strReturn[end];
				strReturn[end] = ch;
				begin++;
				end--;
			}
		}
		string addStrings(string num1, string num2)
		{
			string strReturn;//存储返回的值
			int cache = 0;//进位值

			if (num1.size() < num2.size())
			{
				num1.swap(num2);
			}
			//num1一定是大数，num2一定是小数
			int index1 = num1.size() - 1;
			int index2 = num2.size() - 1;
			while (index1 >= 0 && index2 >= 0)
			{
				int add = (num1[index1] - '0' + num2[index2] - '0') + cache;
				strReturn += (add % 10 + '0');
				cache = add / 10;
				index1--;
				index2--;
			}
			while (index1 >= 0)
			{
				int add = (num1[index1] - '0') + cache;
				strReturn += (add % 10 + '0');
				cache = add / 10;
				index1--;
			}
			if (cache != 0)
			{
				strReturn += (cache + '0');
			}
			Reversal(strReturn);
			return strReturn;
		}
	};
	Solution s;
	string num1 = "1";
	string num2 = "9";
	cout << s.addStrings(num1, num2) << endl;
}
void test_16()
{
	class Solution 
	{
	public:
		string addStrings(string num1, string num2)
		{
			int end1 = num1.size() - 1;
			int end2 = num2.size() - 1;
			int next = 0;//进位
			string strRet;
			while (end1 >= 0 || end2 >= 0 || next != 0)
			{
				int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
				int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
				int ret = val1 + val2 + next;
				next = ret > 9 ? 1 : 0;
				//注意这里是尾插
				strRet += ('0' + (ret % 10));
				--end1;
				--end2;
			}
			reverse(strRet.begin(), strRet.end());
			return strRet;
		}
	};
}
void test_17()
{
	class Solution
	{
	public:
		bool _IsNumber(const string& str)
		{
			int index = 0;
			int size = str.size();
			while (index < size)
			{
				if (!(str[index] >= '0' && str[index] <= '9'))
				{
					return false;
				}
				index++;
			}
			return true;
		}
		int _fun(int number, int i)
		{
			int add = 1;
			while (i--)
			{
				add *= number;
			}
			return add;
		}
		int _StrTpInt(string str)
		{
			//23421
			int index = 0;//str[index]=1, index=4
			int addRet = 0;//addRet=0
			int size = str.size();//size=5
			while (index < size)
			{
				addRet += ((str[index] - '0') * _fun(10, (size - index - 1)));//5-4-1=0
				index++;
			}
			return addRet;
		}
		int StrToInt(string str)
		{
			//+23421
			//-23421
			//23421
			int flag = 1;
			if (str[0] == '+')
			{
				flag = 1;
				string strcop(str.begin() + 1, str.end());
				if (!_IsNumber(strcop))//是数字字符串就返回true
				{
					return 0;
				}
				return flag * _StrTpInt(strcop);
			}
			else if (str[0] == '-')
			{
				flag = -1;
				string strcop(str.begin() + 1, str.end());
				if (!_IsNumber(strcop))//是数字字符串就返回true
				{
					return 0;
				}
				return flag * _StrTpInt(strcop);
			}
			else
			{
				if (!_IsNumber(str))//是数字字符串就返回true
				{
					return 0;
				}
				return _StrTpInt(str);
			}
		}
	};
	Solution s;
	string str("+3645");
	cout << s.StrToInt(str) << endl;
}
void test_18()
{
	class Solution
	{
	public:
		bool isPalindrome(string str)
		{
			string strCopy;
			int index = 0;//源字符str串索引
			while (index < str.size())//遍历str
			{
				if (str[index] >= 'A' && str[index] <= 'Z')//处理大写字母
				{
					strCopy += str[index] - 'A' + 'a';
				}
				else if ((str[index] >= 'a' && str[index] <= 'z')//处理小写字母和数字
					|| (str[index] >= '0' && str[index] <= '9'))
				{
					strCopy += str[index];
				}
				index++;
			}
			//得到只有数字和小写字母的strCopy
			int begin = 0;
			int end = strCopy.size() - 1;
			while (begin < end)
			{
				if (strCopy[begin] != strCopy[end])
				{
					return false;
				}
				begin++;
				end--;
			}
			return true;
		}
	};
	Solution s;
	string str = "race a car";
	s.isPalindrome(str);
}
int main()
{
	//test_1();
	//test_2();
	//test_3();
	//test_4();
	//test_5();
	//test_6();
	//test_7();
	//test_8();
	//test_9();
	//test_10();
	//test_11();
	//test_12();
	//test_14();
	//test_15();
	//test_16();
	//test_17();
	test_18();

	return 0;
}
