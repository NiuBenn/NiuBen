#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 1;
	while (1)
	{
		if (n % 2 == 1 && n % 3 == 2 && n % 5 == 4 && n % 6 == 5 && n % 7 == 0)
		{
			break;
		}
		++n;
	}
	printf("这条阶梯至少有%d阶", n);
	system("pause");
	return 0;
}