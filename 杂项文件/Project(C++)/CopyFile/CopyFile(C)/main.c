#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE* sourse, FILE* dest)
{
	size_t bytes;
	static char temp[BUFSIZE];
	while ((bytes = fread(temp, sizeof(char), BUFSIZE, sourse)) > 0)
	{
		fwrite(temp, sizeof(char), bytes, dest);
	}
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n');
		}
	}
	return ret_val;
}
int main()
{
	FILE* fa, * fs;//faָ��Ŀ���ļ���fsָ��Դ�ļ�
	int files = 0;
	char file_app[SLEN];//Ŀ���ļ���
	char file_src[SLEN];//Դ�ļ���
	int ch;
	puts("Enter append file:");
	s_gets(file_app, SLEN);//����Ŀ���ļ�����
	if ((fa = fopen(file_app, "a+")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", file_app);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)//��ȫ����
	{
		fputs("Can't create output buffer", stderr);
		exit(EXIT_FAILURE);
	}
	puts("Enter sourse file:");
	while (s_gets(file_src, SLEN) && file_src[0] != '\0')
	{
		if (strcmp(file_app, file_src) == 0)
		{
			fputs("Can't append file", stderr);
		}
		else if ((fs = fopen(file_src, "r")) == NULL)
		{
			fprintf(stderr, "Can't open %s\n", file_src);
		}
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Can't create input buffer\n", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)
			{
				fprintf(stderr, "Error in reding file %s \n", file_src);
			}
			if (ferror(fa) != 0)
			{
				fprintf(stderr, "Error in writing file %s \n", file_app);
			}
			fclose(fs);
			files++;//��¼������ļ�����
			printf("File %s append.\n", file_src);
			puts("Next file (emptu line to quit):");
		}
	}
	printf("Done appending. %d files appended.\n", files);
	rewind(fa);//���õ��ļ���ͷ
	printf("%s contents:\n", file_app);
	while ((ch = getc(fa) != EOF))
		putchar(ch);
	puts("\nDone displaying.");
	fclose(fa);

	return 0;
}