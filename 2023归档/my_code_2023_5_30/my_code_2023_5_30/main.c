#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
int GetMax(int number, ...)//ע�⣺�ɱ����Ҫ��ʹ�ã�����ǰ��������һ�������ϸ���ȷ����
{
	//ʹ���ĸ�������д���룺va_list��va_start��va_arg��va_end
	//���������Լ��ǲ�̫������ջ֡�ռ���һһ�ҵ�������ʱ������Ӧ�ĵ�ַ���ҽ��н����ã���������Ϊ�˷���ʹ�ã�C�����ṩ�ˡ��������������͡�һ�����ͷ����������Ѱ����ʱ�����Ĳ���
	va_list arg;//1.����һ�����Է��ʿɱ�������ֵı�������ʵ����һ��char*���͵ı���������ζ�Ÿñ������԰���һ���ֽڵķ�ʽ�������� 
	va_start(arg, number);//2.ʹargָ��ɱ��������
	int max = va_arg(arg, int);//3.�������ʹ�С���Ի�ȡ�ɱ�����б��еĲ������ݣ������ȡ���ǵ�һ��int�������ݣ�
	for (int i = 0; i < number - 1; i++)
	{
		int x = va_arg(arg, int);//4.������ȡ��һ������
		if (max < x)
		{
			max = x;
		}
	}
	va_end(arg);//5.argʹ����ϣ���β���������ʾ��ǽ�argָ��NULL������free��ʹ�ã�����arg��ΪҰָ�룩
	return max;
}
int main()
{
	int max = GetMax(5, 1, 2, 3, 4, 5);
	printf("%d", max);
	return 0;
}