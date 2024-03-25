#include <stdio.h>
int main()
{
    int x = 11, y = 10;
    int value = (x - ++y ? 10 : 11 == y ? 'a' : 'z');
    printf("%c", value);
    return 0;
}