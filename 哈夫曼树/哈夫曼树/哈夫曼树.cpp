#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data_structure.h"

int main()
{
	int n;   //��Ҫ������ַ��ĸ���
	printf("��������Ҫ������ַ��ĸ�����>1����");
	scanf("%d", &n);
	while (n <= 1)
	{
		printf("�ַ������������1�����������룺");
		scanf("%d", &n);
	}

	int i;
	int *wet = (int *)malloc(n * sizeof(int));  //���ÿ���ַ���Ȩֵ
	printf("������������%d���ַ���Ȩֵ�����ͣ���", n);
	for (i = 0; i<n; i++)
	{
		scanf("%d", wet + i);
	}

	HuffmanCode HC;  //����շ�������
	HuffmanTree HT = create_HuffmanTree(wet, n);  //���ɺշ�����
	HuffmanCoding(HT, HC, n);        //��ÿ���ַ��ĺշ�������

	printf("��������˳�򣬸�Ȩֵ��Ӧ�ַ��ĺշ����������£�\n");
	for (i = 0; i<n; i++)
	{
		puts(HC[i]);
	}
	free(wet);
	system("pause");
	return 0;
}