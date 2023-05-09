#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int A = 0;
    scanf("%d", &A);
    int count = 0;
    for (int a = A; a < A + 4; a++)
    {
        for (int b = A; b < A + 4; b++)
        {
            for (int c = A; c < A + 4; c++)
            {
                if (a != b && a != c && b != c)
                {
                    printf("%d%d%d", a, b, c);
                    count++;
                    if (count == 6)
                    {
                        printf("\n");
                        count = 0;
                    }
                    else if (count != 6)
                    {
                        printf(" ");
                    }
                }
            }
        }
    }
    return 0;
}