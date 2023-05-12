#include <cstdio>
int& function(int& x)//int& x = i，因此x是i的别名
{
    x++;//这个x++等价于i++
    return x;//返回x，int& ("function()") = x，因此函数甚至可以被赋值
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