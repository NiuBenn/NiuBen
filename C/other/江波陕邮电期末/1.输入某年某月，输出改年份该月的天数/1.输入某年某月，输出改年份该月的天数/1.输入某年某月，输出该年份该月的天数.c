#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int year, month, day;
	int MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//ÿ�µ�����

	printf("��������ݺ��·ݣ�");
	scanf("%d%d", &year, &month);
	day = MonthDay[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))//�ж��Ƿ�����
	{
		++day;
	}
	printf("�����������Ϊ:%d", day);
	system("pause");
	return 0;
}
