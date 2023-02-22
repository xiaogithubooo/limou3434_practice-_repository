#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	FILE* fp = fopen("C:\\Users\\DELL\\Desktop\\text.txt", "w+");
	fprintf(fp, "%s %s %s %d", "abcd", "efgh", "ijkl", 2022);
	fclose(fp);
	return 0;
}