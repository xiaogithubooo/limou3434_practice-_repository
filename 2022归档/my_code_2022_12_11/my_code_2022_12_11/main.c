#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//1��ѧϰʹ���ļ�����
//int main()
//{
//	//a��Ԥ������д������1
//	int a = 10000;
//	//b�����Դ��ļ���ֻд������д��ʱ�򡱾ͻ��Լ������ļ������ϵ��ļ����������������ֱ���½�һ��
//	FILE* pf = fopen("�����ļ�.txt", "wb");
//	//c���ж��Ƿ���ļ�
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//d��д�ļ���д��������ı���
//	fwrite(&a, 4, 1, pf);//�������a��һ��Ԫ�أ�int���Ĵ�С��дһ�����У�д��pf��
//	//d���ر��ļ��������ÿ��ļ�ָ��pf
//	fclose(pf);
//	pf = NULL;
//	return 0;//e��С�δ洢��10 27 00 00 00��ʮ������00 00 00 27 10ת��Ϊʮ���Ƽ�10000
//}
//r�������ļ�������¡���ȡ������
//w�����л����޶����½��ļ�������
//a�������ļ�������¡�׷�ӡ�����

//2����׼��������÷�
//����-��׼�����豸-stdin
//��Ļ-��׼����豸-stdout
//��һ������Ĭ�ϴ򿪵������豸
//int main()
//{
//	int ch = fgetc(stdin);
//	fputc(ch, stdout);
//	return 0;
//}

//3���ı��ĵ��Ķ�д���Լ���puts�Ļ���˵��
//int main()
//{
//	char buf[1024] = { 0 };
//
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("���ļ�ʧ��");
//		return 0;
//	}
//	//д�ļ�}
//	fputs("hello ", pf);
//	fputs("world?", pf);
//	fclose(pf);
//	pf = NULL;
//
//	pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("���ļ�ʧ��");
//		return 0;
//	}
//	//���ļ�����������������buf
//	fgets(buf, 1024, pf);//�������\n�ͻ��Զ����У�һ���ȡ������puts�����ͻỻ�У����ǲ�һ���ģ�
//	printf("%s", buf);
//
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//4���Ӽ��̶�ȡһ�У��������Ļ
//int main()
//{
//	char buf[1024] = { 0 };
//	fgets(buf, 1024, stdin);//�ӱ�׼��������ȡ
//	fputs(buf, stdout);//�������׼�����
//	//�ȼ������µ�д��
//	gets(buf);
//	puts(buf);
//	return 0;
//}

//5����ʽ�����������
//��1������
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 100,3.14f,"bit" };
//	FILE* pf = fopen("test.txt", "w");//д����ʽ��
//	if (pf == NULL)
//	{
//		printf("���ļ�ʧ��");
//		return 0;
//	}
//	fprintf(pf, " %d %f %s", s.n, s.score, s.arr);//��ʽ������
//	return 0;
//}
//��2�����
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 0 };
//	FILE* pf = fopen("test.txt", "r");//д����ʽ��
//	if (pf == NULL)
//	{
//		printf("���ļ�ʧ��");
//		return 0;
//	}
//	fscanf(pf, "%d %f %s", &(s.n), &(s.score), &(s.arr));//��ʽ������
//	printf("%d %f %s\n", (s.n), (s.score), (s.arr));//��Ȼ��Ҫ��ӡ�ģ�����ֱ�Ӿ��еġ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//6����Ļ�ͼ�����ʹ�ø�ʽ�������
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 0 };
//
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), &(s.arr));
//	fprintf(stdout, "%d %.2f %s", s.n, s.score, s.arr);
//	return 0;
//}

//7���Ա����麯��������
//   scanf/fscanf/sscanf
//  printf/fprintf/sprintf
//��1��scanfhe��printf����ԡ���׼��������/��׼�����_�ĸ�ʽ������/������
//��2��fscanf��fprintf����ԡ����С�������/��׼�����_�ĸ�ʽ������/������
//��3��sscnaf��sprintf�ͱ�scanf��printf�Ĳ�������char*���ѣ�ǰ���ַ����ָ��ظ�ʽ�����߸�ʽ����ַ��������ַ����ж�ȡ��ʽ�����ݣ��Ѹ�ʽ������������ַ�����
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 100,3.14f,"abcdef" };//�������
//	struct S tmp = { 0 };
//	char buf[1024] = { 0 };
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);//�Ѹ�ʽ�����ݱ���ַ����洢��buf��
//	printf("%s\n", buf);
//
//	sscanf(buf,"%d %f %s", &(tmp.n), &(tmp.score), &(tmp.arr));//��buf�ж�ȡ���ַ����ָ��ɸ�ʽ�������ݵ�tmp��
//	printf("%d %f %s\n", tmp.n, tmp.score, tmp.arr);
//	return 0;
//}

//8�������ȡ�ļ�
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//��λ�ļ�ָ��
//	//fgets(pf);//���������һ������1�Ľ��
//	fseek(pf, -2, SEEK_END);//���������һ�䣬��ĩβ��ʼ����ָ��abcdef�е�e��ƫ����Ϊ4����������Ĭ�ϴӿ�ͷ����ƫ����Ϊ0
//	int pos = ftell(pf);//����ƫ�����������ļ�ָ���������ʼλ�õ�ƫ��������������䶼���ӵĻ��������0
//	printf("%d\n", pos);
//	rewind(pf);//�ļ�ָ��ָ���ʼλ��
//	pos = fgetc(pf);
//	printf("%c\n", pos);
//	fclose(pf);//�ر��ļ�
//	pf = NULL;
//	return 0;
//}

//9������ʹ��feof()
//int main()
//{
//	//���Ϊ�ж��ļ�������
//	//���μǣ��ڶ�ȡ�ļ��Ĺ����У�������feof�����ķ���ֱֵ�������ж��ļ��Ƿ����������Ӧ�����ļ���ȡ������ʱ���ж��Ƕ�ȡʧ�ܽ��������������ļ�β������
//	//���ж��ı��ļ���ȡ�Ƿ����ʱ��fgetc�ж��Ƿ�ΪEOF��fgetsΪNULL��
//	//���ж϶������ļ���ȡ�Ƿ����ʱ��fread�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�����
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	int ch = fgetc(pf);
//	printf("%d", ch);//Ӧ�ô�ӡEOF���ļ�������־��������ʵֵΪ-1
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//10������perror��strerror(errno)������
//int main()
//{
//	int c;
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("hehe");//��hehe:�����롱����strerror���ӷ��㣬���һ�����Ҫ��ͷ�ļ���������һ���Ŀɶ��ԣ�֪�����ĸ��ط�����������ֱ�ۺ���
//		return 0;
//	}
//	//���ļ�
//	while ((c = fget(pf)) != EOF)
//	{
//		putchar(c);
//	}
//	if (ferror(pf))//�ж��Ƿ��ȡʧ��
//	{
//		puts("I/O errror when reading");
//	}
//	else if (feof(pf))//�ж�Ϊ�����ļ�����
//	{
//		puts("End of file reached successfully");
//	}
//	fclose(pf);
//	return 0;
//}