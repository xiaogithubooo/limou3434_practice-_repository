#include <stdio.h>
int main()
{
    FILE* fp = fopen("limou.txt", "a+");
    if(fp == NULL)
    {
        perror("false!\n");
    }
    while(1);
    fclose(fp);
    return 0;
}
