//inline.cpp内部 
#include "inline.h" 
int Add_Inline(int x, int y)
{
	return x + y; 
}
int Add_No_Inline(int x, int y)
{ 
	return Add_Inline(x, y);
}
