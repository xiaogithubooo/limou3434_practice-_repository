#include "string.h"
int main()
{
	try
	{
		//limou::test_1();
		//limou::test_2();
		limou::test_3();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
