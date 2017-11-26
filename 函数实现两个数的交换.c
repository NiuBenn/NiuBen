#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void change(int* a, int* b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	int a = 0;
	int b = 0;
	printf("place enter two number :");
	scanf("%d%d", &a, &b);
	change(&a,&b);
	printf("a = %d, b = %d", a, b);
	system("pause");
	return 0;
}