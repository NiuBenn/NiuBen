#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void year(int a)
{
	if ((a % 400) == 0 || ((a % 4 == 0) && (a % 100 != 0)))
	{
		printf("This year is a leap year ");
	}
	else
	{
		printf("This year is not a leap year ");
	}
}

int main()
{
	int a = 0;
	printf("place enter a year :");
	scanf("%d", &a);
	year(a);
	system("pause");
	return 0;
}