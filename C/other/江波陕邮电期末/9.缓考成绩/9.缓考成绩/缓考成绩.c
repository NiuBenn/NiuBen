#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num[10] = { 90, 88, 76, 75, 70, 69, 68, 61, 55 };//����ɼ�Ϊ��������(���ɸߵ�������)
	int number, i = 8;
	scanf("%d", &number);//�Ӽ��������ͬѧ�ɼ�

	while (i >= 0 && number>num[i])    
	{
		num[i + 1] = num[i];//�����Ǻ���λ�ã�������Ԫ������ƶ�   
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