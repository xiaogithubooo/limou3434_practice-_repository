#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <errno.h>
int main()
{
    //���ļ�
    FILE* pf = fopen("C:\\Users\\DELL\\Desktop\\limou_cache_file_1.txt", "r+");
    if (pf == NULL)
    {
        perror("fopenʧ��!\n");
        return 1;
    }

    //д���ļ�
    fputs("hello_limou_welcome_file!", pf);

    //�ر��ļ�
    fclose(pf);
    pf = NULL;
    return 0;
}
#include <stdio.h>
#include <errno.h>
int main()
{
    //���ļ�
    FILE* pf = fopen("C:\\Users\\DELL\\Desktop\\limou_cache_file_1.txt", "r+");
    if (pf == NULL)
    {
        perror("fopenʧ��!\n");
        return 1;
    }

    //д���ļ�
    char arr[150];
    for (int i = 0; i < 10; i++)
    {
        fgets(arr, 150, pf);
        printf("%s\n", arr);
    }

    //�ر��ļ�
    fclose(pf);
    pf = NULL;
    return 0;
}
int main()
{
	char* arr[10] = { 1 };
	return 0;
}
#include <stdio.h>
int main()
{
	typedef struct S
	{
		int a;
		double b;
		char c[10];
	}S;
	S s = { 0 };
	//���ļ�
	FILE* pf = fopen("C:\\Users\\DELL\\Desktop\\limou_cache_file_1.txt", "r+");
	if (pf == NULL)
	{
		perror("fopenʧ��!\n");
		return 1;
	}

	//���ļ�
	fscanf(pf, "%d %lf %s", &(s.a), &(s.b), &(s.c));

	//��ӡ����Ļ��
	printf("%d %lf %s", s.a, s.b, s.c);

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}
#include <stdio.h>
typedef struct S
{
	int a;
	double b;
	char c[10];
}S;
int main()
{
	struct S s = { 200,3.14f,"limou3434" };
	char arr[200] = { 0 };
	sprintf(arr, "%d % f %s", s.a, s.b, s.c);
	printf("%s", arr);
	return 0;
}

//�йس�ʼ����һ������
#include <stdio.h>
int main()
{
	//int* a;
	//*a = 5;//ʧ����
	//printf("%d", *a);

	int b;
	b = 5;
	printf("%d", b);//�ɹ���
	return 0;
}

#include <stdio.h>
typedef struct S
{
	int a;
	double b;
	char c[10];
}S;
int main()
{
	S s1 = { 200,3.14f,"limou3434" };

	//ת��Ϊ�ַ�������
	char arr[200] = { 0 };
	sprintf(arr, "%d %lf %s\n", s1.a, s1.b, s1.c);
	printf("%s", arr);

	//ת��Ϊ��ʽ������
	S s2 = { 0 };
	sscanf(arr, "%d %lf %s", &(s2.a), &(s2.b), s2.c);
	printf("%d %lf %s\n", s2.a, s2.b, s2.c);
	return 0;
}
#include <stdio.h>
typedef struct S
{
	int a;
	double b;
	char arr[10];
}S;
int main()
{
	//��������
	S s1 = { 3, 3.14, "abcde" };
	FILE* pf = fopen("limou_txt", "wb");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	fwrite(&s1, sizeof(S), 1, pf);
	//�ر��ļ�
	fclose(pf);
	pf = NULL;

	//�������
	S s2 = { 0 };
	pf = fopen("limou_txt", "rb");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	fread(&s2, sizeof(S), 1, pf);
	printf("%d %f %s\n", s2.a, s2.b, s2.arr);

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
//}
#include <stdio.h>
int main()
{
	//��������
	FILE* pf = fopen("limou.txt", "r");//�ļ�ָ��ָ��a�ĵ�ַ
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//˳���д
	int ch = fgetc(pf);
	printf("%c", ch);//��ӡa��������ļ�ָ��ָ��b
	ch = fgetc(pf);
	printf("%c", ch);//��ӡb��������ļ�ָ��ָ��c
	ch = fgetc(pf);
	printf("%c", ch);//��ӡc��������ļ�ָ��ָ��d
	ch = fgetc(pf);
	printf("%c", ch);//��ӡd��������ļ�ָ��ָ��e

	//�ı�ƫ������д
	fseek(pf, -3, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c", ch);

	//����˳���д
	ch = fgetc(pf);
	printf("%c\n", ch);//��ӡd��������ļ�ָ��ָ��e

	//����ƫ����
	long int a = ftell(pf);
	printf("%d\n", a);

	//�޸��ļ�ָ��Ϊ��ͷ
	rewind(pf);
	
	//�ٴη���ƫ����
	a = ftell(pf);
	printf("%d\n", a);

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}
#include <stdio.h>
int main()
{
    //��������
    FILE* pf = fopen("limou.txt", "r");//�ļ�ָ��ָ��a�ĵ�ַ
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    //˳���д
    int ch = fgetc(pf);
    printf("%c", ch);//��ӡa��������ļ�ָ��ָ��b
    ch = fgetc(pf);
    printf("%c", ch);//��ӡb��������ļ�ָ��ָ��c
    ch = fgetc(pf);
    printf("%c", ch);//��ӡc��������ļ�ָ��ָ��d
    ch = fgetc(pf);
    printf("%c", ch);//��ӡd��������ļ�ָ��ָ��e

    //�ı�ƫ������д
    fseek(pf, -3, SEEK_CUR);
    ch = fgetc(pf);
    printf("%c", ch);

    //����˳���д
    ch = fgetc(pf);
    printf("%c\n", ch);//��ӡd��������ļ�ָ��ָ��e

    //����ƫ����
    long int a = ftell(pf);
    printf("%d\n", a);

    //�ر��ļ�
    fclose(pf);
    pf = NULL;
    return 0;
}
#include <stdio.h>
int main()
{
    //��������
    FILE* pf = fopen("limou.txt", "r");//�ļ�ָ��ָ��a�ĵ�ַ
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    //˳���д
    int ch = fgetc(pf);
    printf("%c", ch);//��ӡa��������ļ�ָ��ָ��b
    ch = fgetc(pf);
    printf("%c", ch);//��ӡb��������ļ�ָ��ָ��c
    ch = fgetc(pf);
    printf("%c", ch);//��ӡc��������ļ�ָ��ָ��d
    ch = fgetc(pf);
    printf("%c", ch);//��ӡd��������ļ�ָ��ָ��e

    //�ı�ƫ������д
    fseek(pf, -3, SEEK_CUR);
    ch = fgetc(pf);
    printf("%c", ch);

    //�ر��ļ�
    fclose(pf);
    pf = NULL;
    return 0;
}
#include <stdio.h>
int main()
{
	��������
    FILE* pf = fopen("limou.txt", "r");//�ļ�ָ��ָ��a�ĵ�ַ
    if (pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    int ch = 0;
    while ((ch = fgetc(pf)) != EOF)
    {
        printf("%c", ch);
    }
    ͨ��feof�������ж��ǲ��������ļ�ĩβ������
    if (feof(pf))
    {
        printf("���ļ���β\n");
    }
    else if (ferror(pf))
    {
        printf("�ļ���ȡ����\n");
    }
    �ر��ļ�
    fclose(pf);
    pf = NULL;
	return 0;
}