#define _CRT_SECURE_NO_WARNINGS 1
#include<math.h>
#include<stdio.h>
void Prime(int a)
{
	int k = 0;
	int i = 0;
	k = sqrt(a);
	for (i = 2; i <= k; i++)
		if (a%i == 0)
		{
			printf("This number is not a prime number\n");
			break;
		}
	if (i >= k + 1)
	{
		printf("This number is a prime numbe\n");
	}
}
int main()
{
	int a = 0;
	printf("place enter a number :");
	scanf("%d", &a);
	Prime(a);
	system("pause");
	return 0;
}