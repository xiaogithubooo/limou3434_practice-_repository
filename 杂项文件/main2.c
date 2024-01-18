#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
int main()
{
	printf("1.本程序路径：%s\n", __FILE__);
	printf("2.本程序预处理日期：%s\n", __DATE__);
	printf("3.本程序开始运行时间：%s\n", __TIME__);
	printf("\n");
	number_arrary  A;
	FunctionInput_arrary(&A);
	FunctionInverseNumber_arrary(&A);
	FunctionOutput_arrary(&A);
	number_table B;
	FunctionInput_table(&B);
	printf("\n");
	FunctionOutput_table(&B);
	printf("\n");
	FunctionCalculate1_table(&B);
	printf("\n");
	FunctionNatureOperation_table(&B);
	printf("\n");
}