#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include <stdlib.h> 
int g_value_2; 
int g_value_1 = 10; 
int main() 
{
	printf("code addr: %p\n", main);//������
	printf("\n"); 
	const char *str = "hello word!";
	//ע�⡰hello word!���Ǵ洢�ھ�̬���������ַ����������ģ�
	//��str�����Ŀռ俪����ջ�ϣ�
	//����str���ָ�����������Ǵ��ھ�̬�������ڵġ�hello word!����'h'�ĵ�ַ��
	//�ʴ�ӡstr���Ǵ�ӡ��̬�������ĵ�ַ 
	printf("read only addr: %p\n", str);//��̬��
	printf("\n"); 
	printf("init g_value_1 global addr: %p\n", &g_value_1);//�ѳ�ʼ��ȫ�ֱ�����
	printf("uninit g_value_2 global addr: %p\n", &g_value_2);//δ��ʼ��ȫ�ֱ�����
	printf("\n"); 
	int *p = (int*)malloc(sizeof(int) * 10);
	printf("heap addr: %p\n", p);//����
	printf("\n"); 
	printf("stack addr: %p\n", &str);//ջ��
	printf("stack addr: %p\n", &p); 
	printf("\n"); 
	free(p); 
	return 0; 
}