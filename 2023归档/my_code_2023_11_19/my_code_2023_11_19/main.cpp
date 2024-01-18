#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> nums, int x)
    {
        //1.设置 target
        int sum = 0;//整个数组求和
        for (auto e : nums) sum += e;
        int target = sum - x;//求出 target

        //2.处理特殊情况
        if (target < 0)//target 不可能小于 0
            return -1;

        //3.下面开始找到中间区间和为 target 即可
        int left = 0;
        int right = 0;
        int ret = -1;//这里之所以设置为 -1 是因为有可能出现找不到的情况（例如：左右端的数字均大于 target）
        int add = 0;

        while (right < nums.size())
        {
            //1.进窗口
            add += nums[right];

            //2.判断出窗口
            while (add > target)
            {
                add -= nums[left];
                left++;
            }

            //3.更新结果
            if (add == target)
            {
                ret = (int)max(ret, right - left + 1);
            }

            right++;
        }

        if (ret < 0)
            return ret;
        return nums.size() - ret;
    }
};
int main()
{
    Solution s;
    cout << s.minOperations( { 5,6,7,8,9 }, 4) << endl;
    return 0;
}


//#include <stdio.h>
//int main()
//{
//    int i;
//    for (i = 0; i < 10; i++)
//    {
//        printf("你好！\n");
//    }
//}
//
////#include <stdio.h>
////int main()
////{
////	//下面代码就会竖着打印出 0 到 9 的 10 个数字
////	int i = 0;
////	do
////	{
////		printf("%d\n", i);
////		++i;//i 变量自增一次，也就是 i + 1
////	} while (i < 10);//只要变量 i 小于 10 就循环打印
////
////	return 0;
////}
//
////#include <stdio.h>
////int main()
////{
////	//下面代码会打印出无限的“你好！”，乍看起来有点吓人，
////	//但您可以直接关闭控制台（就是那个黑框框窗口），
////	//就可以结束这个循环，或者按下快捷键 [ctrl + c]
////	while (1)
////	{
////		printf("你好\n");
////	}
////	return 0;
////}
//
//
////#include <stdio.h>
////int main()
////{
////	int a = -3;
////	if (a > 1)//不满足 -3 > 1，不进入下面的代码块，不会打印出 haha
////	{
////		printf("haha\n");
////	}
////	else//由于第一个条件不满足，就会执行这里的代码块，因此打印 hehe
////	{
////		printf("hehe\n");
////	}
////	return 0;
////}
//
////#include <stdio.h>
////int main()
////{
////    printf("%d\n", 'c');
////    printf("%d\n", 'A');
////    printf("%d\n", '\n');
////    return 0;
////}
//
////#include <cstdio>
////#include <cstring>
////int main()
////{
////	printf("(are you ok??)");//由于三字母词的存在，打印出：（are you ok]
////	printf("(are you ok\?\?)");//因此利用 \? 避免被编译器错认为三字母词，正常打印出：(are you ok？？)
////	
////	//printf("""); //打印失败
////	printf("\""); //利用 \ 就可以打印出单个的 "
////
////	//利用 \ 来使用ASCII码值表
////	printf("%c\n", '\130');   //输出 X，其中 \130 是八进制数字，用 '' 引出转义字符，说明其本质上还是个字符，需要用 '' 引用
////	printf("%c\n", '\x63');   //输出 c，其中 \x63 是十六进制的数字
////
////	//转义字符也算字符，整体会被看作成一个字符，因此用 strlen() 要格外注意，转义字符会被当作一个字符来看待
////	printf("%d", strlen("abc\tde\"f"));//输出结果为 8
////	return 0;
////}
//
////#include <stdio.h>
////#include <string.h>
////
////int main()
////{
////	//char* 和 char arr[]（字符数组）都可以指向或存放一个字符串
////	const char* s1 = "abcd";
////	char s2[] = "abcd";
////	char s3[] = { 'a','b','c' };		//这个是存储多个单字符的数组，末尾没有 \0
////	char s4[] = { 'a','b','c','\0' };	//这样就没问题了
////
////	printf("%s\n", s1);	//这里 %s 打印出字符串
////	printf("%s\n", s2);	//这里 %s 打印出字符串
////
////	printf("%d\n", strlen(s4));   //也是靠 \0 来计算字符串的长度的，输出了 3，即字符串的长度
////	printf("%d\n", strlen(s3));   //则输出来是非 3 的值，是个随机值，什么时候找到 \0 就输出长度
////
////	char s5[4] = { 'b','i','t' };
////	printf("%d\n", strlen(s5));//由于放入了 3 个元素，第 4 个初始化默认为 0，即 '\0'，故 strlen(arr) 是 3，而不是不是随机值
////}
////
//////#include <stdio.h>
//////int a;
//////int main()
//////{
//////	printf("%d\n", a);
//////	return 0;
//////}
////// 
////////#include <stdio.h>
////////int a = 20;
////////int main()
////////{
////////	printf("%d\n", a);
////////	{
////////		printf("%d\n", a);
////////	}
////////	return 0;
////////}//则打印出两个20
//////
//////
////////#include <cstdio>
////////int main()//局部变量的生命周期演示
////////{
////////    {
////////        int a = 10;
////////        printf("%d\n", a);
////////    }
////////    //上面的 a 变量走到这行代码就被销毁，不存在
////////    return 0;
////////}