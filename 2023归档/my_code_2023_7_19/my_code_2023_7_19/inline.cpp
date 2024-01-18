#include "inline.h"
int AddInline(int x, int y)
{
	return x + y;
}
int AddNoInline(int x, int y)
{
	return AddInline(x, y);
}