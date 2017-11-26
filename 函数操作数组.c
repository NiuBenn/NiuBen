#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void put(int* arr, int  a)
{
	int i = 0;
	for (i = 0; i < a; i++)
	{
		printf("%d ", *(arr + i));
	}
}

void init(int* arr, int a)
{
	int i = 0;
	for (i = 0; i < a; i++)
	{
		*(arr + i) = i;
	}
}

void reverse(int* arr, int a)
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < 3; i++)
	{
		tmp = *(arr + i);
		*(arr + i) = *(arr + (a - 1) - i);
		*(arr + (a - 1) - i) = tmp;
	}
}

void empty(int* arr, int a)
{
	int i = 0;
	for (i = 0; i < a; i++)
	{
		*(arr + i) = 0;
	}
}

int main()
{
	int arr[5] = {0};
	init(arr, 5);
	printf("Array initialization success£º\n");
	put(arr, 5);
	reverse(arr, 5);
	getchar();
	printf("Array element reversed successfully£º\n");
	put(arr, 5);
	empty(arr, 5);
	getchar();
	printf("The array element is empty successfully£º\n");
	put(arr, 5);
	printf("\n");
	system("pause");
	return 0;
}