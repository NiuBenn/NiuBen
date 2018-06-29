#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x, y;
	scanf("%d", &x);
	if (x > 0)
	{
		y = 1;
	}
	else if (x == 0)
	{
		y = 0;
	}
	else if (x < 0)
	{
		y = -1;
	}
	printf("%d", y);
	system("pause");
	return 0;
}
