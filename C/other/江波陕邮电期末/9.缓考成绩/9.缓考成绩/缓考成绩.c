#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num[10] = { 90, 88, 76, 75, 70, 69, 68, 61, 55 };//假设成绩为数组内容(已由高到低排序)
	int number, i = 8;
	scanf("%d", &number);//从键盘输入该同学成绩

	while (i >= 0 && number>num[i])    
	{
		num[i + 1] = num[i];//若不是合适位置，有序组元素向后移动   
		--i;
	}
	num[i + 1] = number;
	

	for (i = 0; i < 10; ++i)
	{
		printf("%d  ", num[i]);
	}

	system("pause");
	return 0;
}