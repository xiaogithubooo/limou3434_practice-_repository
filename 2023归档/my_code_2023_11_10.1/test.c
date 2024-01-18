#include <stdio.h>
int main()
{
    int a = 1;
    int ret = (a+=a*=a-=a*=3);
    printf("%d\n", ret);
}
