char getGradeLevel(int grade)
{

	char gradeLeve1;
	if ((grade >= 0) && (grade < 60))
	{
		gradeLeve1 = 'E';
	}
	else if ((grade >= 60) && (grade < 70))
	{
		gradeLeve1 = 'D';
	}
	else if ((grade >= 70) && (grade < 80))
	{
		gradeLeve1 = 'C';
	}
	else if ((grade >= 80) && (grade < 90))
	{
		gradeLeve1 = 'B';
	}
	else if ((grade >= 90) && (grade <= 100))
	{
		gradeLeve1 = 'A';
	}
	else
	{
		return '0';
	}
	return gradeLeve1;
}