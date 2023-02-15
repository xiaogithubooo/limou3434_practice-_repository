#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
#include <string.h>
#include <stdio.h>
int number = 114514;
int main()
{
	function(2, 3);
	return 0;
}
int main()
{
    char a[1000] = { 0 };
    int i = 0;
    for (i = 0; i < 1000; i++)
    {
        a[i] = -1 - i;
    }
    printf("%d", strlen(a));
    return 0;
}
#include <stdio.h>
long fun(int x) 
{
    if (x == 1 || x == 0)
    {
        return 1;
    }
    return x * fun(x - 1);
}
int main() 
{
    int number = 0;
    int scanf_number = scanf("%d", &number);//输入行数

    for (int n = 0; n < number; n++) 
    { //"行数"一一对应"次数"
        for (int k = 0; k <= n; k++)
        { //递归
            printf("%ld ", (fun(n)) / ((fun(k)) * (fun(n - k)))); //得出一个数
        }
        printf("\n");
    }
    return 0;
}
int main()
{
    char a[1000] = { 0 };
    int i = 0;
    for (i = 0; i < 1000; i++)
    {
        a[i] = -1 - i;
    }
    printf("%d", strlen(a));
    return 0;
}
#include <stdio.h>

int checkData(int* p)
{
	int tmp[7] = { 0 }; //标记表，实际是哈希表的思路。一开始每个元素都是0。

	int i;
	for (i = 0; i < 5; i++)
	{
		if (tmp[p[i]]) //如果这个位置的标记已经是1，则代表重复，直接返回0。
		{
			return 0;
		}
		tmp[p[i]] = 1; //如果不是，则给这个位置标记为1。
	}
	return 1; //全部标记完毕也没有出现重复的情况，代表OK。
}

int main()
{
	int p[5]; //0 1 2 3 4分别代表a b c d e

	for (p[0] = 1; p[0] <= 5; p[0]++)
	{
		for (p[1] = 1; p[1] <= 5; p[1]++)
		{
			for (p[2] = 1; p[2] <= 5; p[2]++)
			{
				for (p[3] = 1; p[3] <= 5; p[3]++)
				{
					for (p[4] = 1; p[4] <= 5; p[4]++) //五层循环遍历
					{
						//这里是五个人的描述，由于比较表达式只有0和1两个结果，如果要两个条件有且只有一个为真，则可以用比较表达式的值总和为1的方式直接判定。别忘了还要判定不能并列。
						if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
							(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
							(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
							(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
							(p[4] == 4) + (p[0] == 1) == 1 && //我第四，A第一
							checkData(p) //不能并列
							)
						{
							for (int i = 0; i < 5; i++)
							{
								printf("%d ", p[i]);
							}
							putchar('\n');
						}
					}
				}
			}
		}
	}

	return 0;
}
#include<stdio.h>
int main()
{
	int killer = 0;
	//分别假设凶手是a,b,c,d,看谁是凶手时满足3个人说了真话，一个人说了假话
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
			printf("凶手是：%c", killer);
	}
	return 0;
}