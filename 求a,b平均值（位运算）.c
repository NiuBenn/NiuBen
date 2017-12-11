#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int b = 0;
	int average = 0;
	printf("please enter two number:");
	scanf("%d%d", &a, &b);
	//average = (a&b) + ((a^b) >> 1);
	average = ((a+b) >> 1);
	printf("The average of these two numbers is :%d\n", average);
	system("pause");
	return 0;
}