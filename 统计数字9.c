#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0, n = 0, m = 0,sum = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i / 10 == 9)
			n++;//ʮλ����9�Ĵ���
		if ((i - (i / 10) * 10) / 1 == 9)
			m++;//��λ����9�Ĵ���
	}
	sum = n + m;
	printf("9���ֵĴ���Ϊ%d��\n", sum);//0��100��99�����μ���
	system("pause");
	return 0;
}