#define _CRT_SECURE_NO_WARNINGS 1
#include "function.h"
int main()
{
	number_table A;
	function_table_n_IO(&A, 5, 1);
	function_table_n_IO(&A, 5, 0);
	function_table_n_IO(&A, 5, 2);
}