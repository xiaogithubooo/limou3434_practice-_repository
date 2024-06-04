#include <stdio.h>

int main() {
    int num1 = 2;
    int num2 = 7;
    double num3 = 7.0;
    double num4 = 2.; // 这里 C 语言允许使用 "2." 的方式表示 "2.0"
    double result1, result2, result3, result4; // 这里可以不初始化, 但是这不是很好的习惯, 我只是演示给您看这种做法在大部分情况下是没有问题的

    // 操作数都是整数时作除法, 结果依旧为整数类型数据
    result1 = num1 / num2;
    printf("result1 = num1 / num2 结果: %d\n", result1); // 结果为 0

    // 其中一个操作数是浮点数时做除法, 由于 num3 是浮点类型, num1 被转化为浮点类型的 2.0, 结果为浮点类型数据
    result2 = num1 / num3;
    printf("result2 = num1 / num3 结果: %f\n", result2); // 结果为 0.285714

    // 混合除法，第一个操作数是整数，第二个是浮点数
    result4 = num3 / num4;
    printf("result3 = num3 / num4 结果: %f\n", result4); // 结果为 3.500000

    return 0;
}