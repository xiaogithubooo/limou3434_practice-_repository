#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
int main()
{
	number_arrary  A;
	FunctionInput_arrary(&A);
	FunctionInverseNumber_arrary(&A);
	number_table B;
	FunctionInput_table(&B);
	printf("\n");
	FunctionOutput_table(&B);
	printf("\n");
	FunctionCalculate1_table(&B);
	printf("\n");
}