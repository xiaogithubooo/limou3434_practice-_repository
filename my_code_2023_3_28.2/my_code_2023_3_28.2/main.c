#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <errno.h>
int main()
{
	FILE* pf = fopen("C:\\Users\\DELL\\Desktop\\limou_cache_file.txt", "r+");
	if (pf == NULL)
	{
		return 1;
	}
	char a;
	int  b;
	double c;
	fscanf(pf,"%c %d %lf", &a,&b,&c);
	fprintf(stdout, "%c %d %lf", a, b, c);

	fclose(pf);
	return 0;
}