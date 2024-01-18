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
        //1.���� target
        int sum = 0;//�����������
        for (auto e : nums) sum += e;
        int target = sum - x;//��� target

        //2.�����������
        if (target < 0)//target ������С�� 0
            return -1;

        //3.���濪ʼ�ҵ��м������Ϊ target ����
        int left = 0;
        int right = 0;
        int ret = -1;//����֮��������Ϊ -1 ����Ϊ�п��ܳ����Ҳ�������������磺���Ҷ˵����־����� target��
        int add = 0;

        while (right < nums.size())
        {
            //1.������
            add += nums[right];

            //2.�жϳ�����
            while (add > target)
            {
                add -= nums[left];
                left++;
            }

            //3.���½��
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
//        printf("��ã�\n");
//    }
//}
//
////#include <stdio.h>
////int main()
////{
////	//�������ͻ����Ŵ�ӡ�� 0 �� 9 �� 10 ������
////	int i = 0;
////	do
////	{
////		printf("%d\n", i);
////		++i;//i ��������һ�Σ�Ҳ���� i + 1
////	} while (i < 10);//ֻҪ���� i С�� 10 ��ѭ����ӡ
////
////	return 0;
////}
//
////#include <stdio.h>
////int main()
////{
////	//���������ӡ�����޵ġ���ã�����է�������е����ˣ�
////	//��������ֱ�ӹرտ���̨�������Ǹ��ڿ�򴰿ڣ���
////	//�Ϳ��Խ������ѭ�������߰��¿�ݼ� [ctrl + c]
////	while (1)
////	{
////		printf("���\n");
////	}
////	return 0;
////}
//
//
////#include <stdio.h>
////int main()
////{
////	int a = -3;
////	if (a > 1)//������ -3 > 1������������Ĵ���飬�����ӡ�� haha
////	{
////		printf("haha\n");
////	}
////	else//���ڵ�һ�����������㣬�ͻ�ִ������Ĵ���飬��˴�ӡ hehe
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
////	printf("(are you ok??)");//��������ĸ�ʵĴ��ڣ���ӡ������are you ok]
////	printf("(are you ok\?\?)");//������� \? ���ⱻ����������Ϊ����ĸ�ʣ�������ӡ����(are you ok����)
////	
////	//printf("""); //��ӡʧ��
////	printf("\""); //���� \ �Ϳ��Դ�ӡ�������� "
////
////	//���� \ ��ʹ��ASCII��ֵ��
////	printf("%c\n", '\130');   //��� X������ \130 �ǰ˽������֣��� '' ����ת���ַ���˵���䱾���ϻ��Ǹ��ַ�����Ҫ�� '' ����
////	printf("%c\n", '\x63');   //��� c������ \x63 ��ʮ�����Ƶ�����
////
////	//ת���ַ�Ҳ���ַ�������ᱻ������һ���ַ�������� strlen() Ҫ����ע�⣬ת���ַ��ᱻ����һ���ַ�������
////	printf("%d", strlen("abc\tde\"f"));//������Ϊ 8
////	return 0;
////}
//
////#include <stdio.h>
////#include <string.h>
////
////int main()
////{
////	//char* �� char arr[]���ַ����飩������ָ�����һ���ַ���
////	const char* s1 = "abcd";
////	char s2[] = "abcd";
////	char s3[] = { 'a','b','c' };		//����Ǵ洢������ַ������飬ĩβû�� \0
////	char s4[] = { 'a','b','c','\0' };	//������û������
////
////	printf("%s\n", s1);	//���� %s ��ӡ���ַ���
////	printf("%s\n", s2);	//���� %s ��ӡ���ַ���
////
////	printf("%d\n", strlen(s4));   //Ҳ�ǿ� \0 �������ַ����ĳ��ȵģ������ 3�����ַ����ĳ���
////	printf("%d\n", strlen(s3));   //��������Ƿ� 3 ��ֵ���Ǹ����ֵ��ʲôʱ���ҵ� \0 ���������
////
////	char s5[4] = { 'b','i','t' };
////	printf("%d\n", strlen(s5));//���ڷ����� 3 ��Ԫ�أ��� 4 ����ʼ��Ĭ��Ϊ 0���� '\0'���� strlen(arr) �� 3�������ǲ������ֵ
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
////////}//���ӡ������20
//////
//////
////////#include <cstdio>
////////int main()//�ֲ�����������������ʾ
////////{
////////    {
////////        int a = 10;
////////        printf("%d\n", a);
////////    }
////////    //����� a �����ߵ����д���ͱ����٣�������
////////    return 0;
////////}