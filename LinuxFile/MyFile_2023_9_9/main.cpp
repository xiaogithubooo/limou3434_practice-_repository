//main.cpp内部 
#include <iostream> 
#include "inline.h"
int main()
{
	//成功调用内联函数Add，对inline.cpp来说定义和声明在一个翻译单元里，
	//内联函数是在一个翻译单元内被展开并且在内部被使用的，所以可以使用 
	std::cout << Add_No_Inline(10, 20) << std::endl;
	return 0;
}
