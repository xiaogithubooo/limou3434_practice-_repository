int jieCheng(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n == 0)
	{
		return 1;
	}
	else if (n < 1)
	{
		return -1;
	}
	else
	{
		return (n * jieCheng(n - 1));
	}
}