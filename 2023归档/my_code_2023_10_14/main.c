#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[], char* env[])
{
    if(strcmp(argv[argc - 1], "-order") == 0)
    {
        printf("---------\n");
        for(int i = 0; env[i]; i++)
        {
            printf("%s\n", env[i]);
        }
        printf("---------\n");
    }
	return 0;
}
