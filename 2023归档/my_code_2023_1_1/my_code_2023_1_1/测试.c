#define _CRT_SECURE_NO_WARNINGS 1
//int my_judge(char x)
//{
//	int x = 0;//数组遍历的行数
//	int y = 0;//数组遍历的列数
//	char arr[3][3] = { '0' };//创建一个数组
//	for (x = 0; x < 3; x++)//输入数据过程
//	{
//		for (y = 0; y< 3; y++)
//		{
//			scanf("%c", &(arr[x][y]));
//			getchar();
//		}
//	}
//	//判断输赢***************************************************************
//	int i = 0;//循环数
//	for (i = 0; i < 3; i++)//赢在横线上
//	{
//		if (  (arr[i][0] == arr[i][1])  &&  (arr[i][0] == arr[i][2])  &&  (arr[i][0] == x)  )
//		{
//			return 1;
//		}
//	}
//	for (i = 0; i < 3; i++)//赢在竖线上
//	{
//		if (  (arr[0][i] == arr[1][i])  &&  (arr[0][i] == arr[2][i])  &&  (arr[0][i] == x)  )
//		{
//			return 1;
//		}
//	}
//	if (  (arr[0][0]==arr[1][1])  &&(arr[0][0]==arr[2][2])  &&  (arr[0][0]==x)  )//赢在斜线上
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}//赢了返回1，输了返回0