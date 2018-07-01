#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num[5], SUM = 0;
	double AVG;
	int i, j, tmp;
	for (i = 0; i < 5; ++i)
	{
		scanf("%d", &num[i]);
		SUM = SUM + num[i];
	}
	AVG = (double)SUM / 5;//SUM是总分，AVG是平均分
	for (i = 0; i < 5; ++i)//冒泡排序
	{
		for (j = 0; j < 5 - i - 1; ++j)
		{
			if (num[j] < num[j + 1])
			{
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}
	printf("总分为：%d 平均分为：%f\n", SUM, AVG);
	printf("排序后的成绩为：");
	for (i = 0; i < 5; ++i)
	{
		printf("%d\t", num[i]);
	}
	system("pause");
	return 0;
}