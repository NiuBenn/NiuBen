#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>   
#include<stdlib.h>   
#define NULL 0 
#define MAX 10
typedef struct term {
	int coef;
	int expn;
}term;//term为一个新类型（是一个结构体）

void enter(term arr[MAX])
{
	int i = 0;
	for (i = 0; i<MAX; i++)
	{
		printf("请输入X指数为%d的项的系数:", i);
		scanf("%d", &(arr[i].coef));
		arr[i].expn = i;
	}
}
void print(term arr[MAX])
{
	int i = 0;
	for (i = 0; i<MAX; i++)
	{
		if (arr[i].coef != 0)
		{
			printf("%dx^%d+", arr[i].coef, arr[i].expn);
		}
	}
}
void add(term arr1[MAX], term arr2[MAX], term arr3[MAX])
{
	int i = 0;
	for (i = 0; i<MAX; i++)
	{
		arr3[i].coef = arr1[i].coef + arr2[i].coef;
		arr3[i].expn = i;
	}
}


int main()
{
	term arr1[MAX] = { 0 };
	term arr2[MAX] = { 0 };
	term arr3[MAX] = { 0 };
	printf("请输入第一个一元多项式的内容：\n");
	enter(arr1);
	printf("请输入第二个一元多项式的内容：\n");
	enter(arr2);
	add(arr1, arr2, arr3);
	printf("两个一元多项式的结果为：\n");
	print(arr3);
	system("pause");
	return 0;
}


