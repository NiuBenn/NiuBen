#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a;
	scanf("%d", &a);
	if (a > 95)
	{
		printf("A");
	}
	else if (a >= 85 && a <= 94)
	{
		printf("B");
	}
	else if (a >= 75 && a <= 84)
	{
		printf("C");
	}
	else if (a >= 65 && a <= 74)
	{
		printf("D");
	}
	else if (a < 65)
	{
		printf("E");
	}
	system("pause");
	return 0;
}