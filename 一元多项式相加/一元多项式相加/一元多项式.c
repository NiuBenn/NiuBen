#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>   
#include<stdlib.h>   
#define NULL 0 
#define MAX 10
typedef struct term {
	int coef;
	int expn;
}term;//termΪһ�������ͣ���һ���ṹ�壩

void enter(term arr[MAX])
{
	int i = 0;
	for (i = 0; i<MAX; i++)
	{
		printf("������Xָ��Ϊ%d�����ϵ��:", i);
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
	printf("�������һ��һԪ����ʽ�����ݣ�\n");
	enter(arr1);
	printf("������ڶ���һԪ����ʽ�����ݣ�\n");
	enter(arr2);
	add(arr1, arr2, arr3);
	printf("����һԪ����ʽ�Ľ��Ϊ��\n");
	print(arr3);
	system("pause");
	return 0;
}


