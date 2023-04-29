#define _CRT_SECURE_NO_WARNINGS 1
int main()
{
	//int i = 0;
	//const int* p = &i;
	//i = 100;
	//p = 100;
	//*p = 100;

	//int j = 10;
	//int* pj = &j;
	//const int * const * const ppj = &pj;
	//“const int* * ppj”const修饰第一个*，代表：*ppj指向的内容，是不可通过*ppj修改的
	//“int * const * ppj”const修饰第二个*，代表：ppj指向的内容，是不可通过ppj修改的
	//“int * * const ppj”const修饰ppj，代表：ppj本身就是一个const值，是不可以被直接修改的

	int x = 10;
	int* px = &x;
	const int * * ppx = &px;
	**ppx = 100;
	*ppx = 100;
	ppx = 100;

	int y = 10;
	int* py = &y;
	int * const * ppy = &py;
	**ppy = 100;
	*ppy = 100;
	ppy = 100;
	
	int z = 10;
	int* pz = &z;
	int* * const ppz = &pz;
	**ppz = 100;
	*ppz = 100;
	ppz = 100;

	int k = 10;
	int* pk = &k;
	const int * const * const ppk = &pk;
	**ppk = 100;
	*ppk = 100;
	ppk = 100;

	int k = 10;
	int* pk = &k;
	int** ppk = &pk;
	//const int * * * pppk = &ppk;//const修饰第一个*，代表**pppk指向一个const值（指向的类型是int），即不能通过**pppk来改变其指向的内容
	//int * const * * pppk = &ppk;//const修饰第二个*，代表*pppk指向一个const值（指向的类型是int*），即不能通过*pppk来改变其指向的内容
	//int * * const * pppk = &ppk;//const修饰第三个*，代表pppk指向一个const值（指向的类型是int**），即不能通过pppk来改变其指向的内容
	//int * * * const pppk = &ppk;//const修饰pppk，代表pppk本身不能被直接修改（本身的类型是int***），即不能直接修改pppk本身的内容
	//***pppk = 100;
	//**pppk = 100;
	//*pppk = 100;
	//pppk = 100;

	return 0;
}