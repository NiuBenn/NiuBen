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
	AVG = (double)SUM / 5;//SUM���ܷ֣�AVG��ƽ����
	for (i = 0; i < 5; ++i)//ð������
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
	printf("�ܷ�Ϊ��%d ƽ����Ϊ��%f\n", SUM, AVG);
	printf("�����ĳɼ�Ϊ��");
	for (i = 0; i < 5; ++i)
	{
		printf("%d\t", num[i]);
	}
	system("pause");
	return 0;
}