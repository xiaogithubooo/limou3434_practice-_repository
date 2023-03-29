#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <errno.h>
int main()
{
	FILE* pf = fopen("C:\\Users\\DELL\\Desktop\\limou_cache_file_1.txt", "r+");
	if (pf == NULL)
	{
		perror("fopen ß∞‹!\n");
		return 1;
	}
	int i = 0;
	for (i = 0; i < 200; i++)
	{
		char ch = fgetc(pf);
		printf("%c", ch);
	}
	fclose(pf);
	pf = NULL;
	return 0;
}