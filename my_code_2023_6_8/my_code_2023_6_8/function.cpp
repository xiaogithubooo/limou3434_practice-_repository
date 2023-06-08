#include "function.h"
int _age = 100;
void Person::Print(void)
{
	printf("%s\n", _name);
	printf("%s\n", _sex);
	printf("%d\n", ::_age);
}