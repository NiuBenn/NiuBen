#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdio.h>

int main()
{
	int n, i, sum = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		sum = sum + i;
	}
	printf("%d", sum);
	system("pause");
	return 0;
}
