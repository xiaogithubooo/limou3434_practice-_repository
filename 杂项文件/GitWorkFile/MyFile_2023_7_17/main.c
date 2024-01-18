#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char* argv[], char* env[])
{
	printf("begin---------------\n");
	//for(int i = 0; env[i]; i++)
	//{
	//	printf("%s\n", env[i]);
	//}
	//printf("end-----------------\n\n\n");

	//printf("begin---------------\n");
	//extern char** environ;
	//for(int j = 0; environ[j]; j++)
	//{
	//	printf("%s\n", environ[j]);
	//}
	printf("%d\n", getenv("bit"));	
	printf("end-----------------\n");

	return 0;
}
