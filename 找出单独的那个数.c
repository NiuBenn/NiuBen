#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
int main()
{
	int arr[7] = { 1,2,3,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int num = arr[0];
	for (i = 1; i < sz; i++)
	{
		num = num^arr[i];
	}
	printf("The number is:%d\n", num);
	system("pause");
	return 0;
}