#include <cstdio>
int& function(int& x)//int& x = i�����x��i�ı���
{
    x++;//���x++�ȼ���i++
    return x;//����x��int& ("function()") = x����˺����������Ա���ֵ
}
int main()
{
    int i = 0;
    int j = 0;
    j = function(i);
    printf("%d\n", j);
    printf("%d\n", function(i) = 10);
    return 0;
}