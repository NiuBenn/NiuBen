#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a[] = { 1,3,5,7,9 };
	int b[] = { 2,4,6,8,0 };
	int i = 0;
	for (i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
	{
		int temp = 0;
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	printf("交换后a数组的值为：\n");
	for (i = 0; i < (sizeof(a)/sizeof(a[0])); i++)
	{
		printf("%d ", a[i]);
	}			
	printf("\n交换后b数组的值为：\n");
	for (i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
	{
		printf("%d ", b[i]);
	}
	system("pause");
	return 0;

}