#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1���о�scanf�ķ���ֵ
int main()
{
	int a = 0; 
	int b = 0;
	int c = 0;
	c = scanf("%d%d", &a, &b);
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", EOF);
	return 0;
}
//�������ϵġ�C Primer Pius����82ҳ̸����scanf�ķ���ֵ����̸���������
//����������^z^z�ͻ����c=-1�������������EOF����ȡ�����ļ���β����
//������������������ξͻ᷵��2��
//�����������Ϊ�����Σ����硰c��c������0����ʾ��ȡʧ�ܡ�

//2���о���Linux���ļ�Ȩ�ޣ�����ϰ��ǰ��ѧϰ��Linux����

//3�������ڷ��ա�������û�취��������ѧ�ɣ��⼸��ѧ�ú���