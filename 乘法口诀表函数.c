#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int chengfa(int a)
{
	int i = 0;
	int j = 0;
	int m = 0;
	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= i; j++)
		{
			m = i*j;
			printf("%-2d*%-2d=%-3d ", i, j, m);
		}
		printf("\n");
	}

}

int main()
{
	int i, j, m, a;
	printf("place enter a number :");
	scanf("%d", &a);
	chengfa(a);
	system("pause");
	return 0;
}
