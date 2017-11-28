#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0, n = 0, m = 0,sum = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i / 10 == 9)
			n++;//十位出现9的次数
		if ((i - (i / 10) * 10) / 1 == 9)
			m++;//个位出现9的次数
	}
	sum = n + m;
	printf("9出现的次数为%d次\n", sum);//0到100中99按两次计算
	system("pause");
	return 0;
}