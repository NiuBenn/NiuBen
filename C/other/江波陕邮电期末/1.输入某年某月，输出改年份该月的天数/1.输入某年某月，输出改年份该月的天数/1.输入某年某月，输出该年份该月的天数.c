#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int year, month, day;
	int MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//每月的天数

	printf("请输入年份和月份：");
	scanf("%d%d", &year, &month);
	day = MonthDay[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))//判断是否闰年
	{
		++day;
	}
	printf("该年该月天数为:%d", day);
	system("pause");
	return 0;
}
