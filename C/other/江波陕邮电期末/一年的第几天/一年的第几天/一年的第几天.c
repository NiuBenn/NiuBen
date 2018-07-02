#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int rn(int year) //是闰年返回1，不是闰年返回0
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	return 0;
}

void ts(int year, int month, int day)
{
	int MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //每月的天数
	int i, days = day;
	for (i = 1; i < month; ++i)
	{
		days = days + MonthDay[i];
	}
	if (rn(year))
	{
		++days;
	}
	printf("%d年%d月%d日是这一年的第%d天\n", year, month, day, days);
}

int main()
{
	int year, month, day;
	printf("请输入年月日：");
	scanf("%d%d%d", &year, &month, &day);
	ts(year, month, day);
	system("pause");
	return 0;
}