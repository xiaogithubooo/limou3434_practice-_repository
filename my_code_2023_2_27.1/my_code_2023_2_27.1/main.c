#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char char_arr[26] = { 0 };//存储从a到z的单个字符
	char ch;
	int max = 0;
	int number = 0;
	while ((ch = getchar()) != '\n')//从输入缓冲区获取单个字符进行处理
	{
		char_arr[ch - 'a']++;
		//如果是ch=='a'，那么'a'-'a'==0，则在char_arr[0]上的0+1，代表找到一个a
		//如果下一个字符ch=='c'，那么'c'-'a'==2，则在char_arr[2]上的0+1，代表找到一个c
		//如果下一个字符ch=='a'，那么'a'-'a'==0，则在char_arr[0]上的1+1，代表又找到一个a，这个时候char_arr[0]存储了一个2，代表目前找到两个a
		//以此类推，char_arr[0]存储的是a出现的个数，char_arr[1]存储的是b出现的个数……
	}

	for (int i = 0; i < 26; i++)
	{
		if (char_arr[i] > max)//找出数组中存放最大的元素，并且把这个数组元素下标找到
		{
			number = i;
			max = char_arr[i];
		}
	}

	printf("%d %c\n", char_arr[number], number + 'a');
	return 0;
}