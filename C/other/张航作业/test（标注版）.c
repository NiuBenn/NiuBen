#define _CRT_SECURE_NO_WARNINGS 1//vs�������·�ֹscanf����������
#define MAX 50//�궨��MAXΪ50

#include<stdio.h>
#include<stdlib.h>

enum SEX//����ö������sex���Ա𣩣����ã����Ӵ���ɶ���
{
	GG = 1, MM = 0  //��Ϊ1��ŮΪ0
};

typedef struct Sport//����ṹ��sport��������˶�Ա����Ϣ
{
	char num[5];//���
	char name[20];//����
	enum SEX sex;//�Ա�
	int age;//����
	int high;//���
	int weight;//����
	int sport1;//���Ϊ�����������ʾ���ܳɼ������ΪŮ����ʾ���ܳɼ�
	int sport2;//���Ϊ�����������ʾ��ɽ�ɼ������ΪŮ����ʾ�����ɼ�
}Sport;

void my_scanf(Sport arr[MAX], int num)//���뺯�� ����numΪ�˶�Ա����
{
	int i = 0;
	while (i++ < num)//��whileѭ��ʵ�ֶ�λѵ��Ա��Ϣ������
	{
		printf("\n�������%dλ�˶�Ա����Ϣ��\n",i);
		printf("�������˶�Ա�ı�ţ�");
		scanf("%s", &arr[i].num);
		printf("�������˶�Ա��������");
		scanf("%s", &arr[i].name);
		printf("�������˶�Ա���Ա�");
		scanf("%d", &arr[i].sex);
		printf("�������˶�Ա�����䣺");
		scanf("%d", &arr[i].age);
		printf("�������˶�Ա����ߣ�");
		scanf("%d", &arr[i].high);
		printf("�������˶�Ա�����أ�");
		scanf("%d", &arr[i].weight);
		if (1 == arr[i].sex)//����Ա�Ϊ��
		{
			printf("�������˶�Ա�ĳ��ܳɼ���");
			scanf("%d", &arr[i].sport1);
			printf("�������˶�Ա�ĵ�ɽ�ɼ���");
			scanf("%d", &arr[i].sport2);
		}
		else if (0 == arr[i].sex)//����Ա�ΪŮ
		{
			printf("�������˶�Ա�Ķ��ܳɼ���");
			scanf("%d", &arr[i].sport1);
			printf("�������˶�Ա�������ɼ���");
			scanf("%d", &arr[i].sport2);
		}
	}
}

int my_printf(Sport arr[MAX], int num)//������� ����numΪ�˶�Ա����
{
	int count = 0;//�����������μ������˶�Ա����������������ʱ��Ϊ����ֵ����
	int i = 0;
	printf("���   ����   �Ա�   ����   ���    ����   ����   ��ɽ   ����   ����\n");
	while(i++ < num)//��whileѭ��ʵ�ֶ�λѵ��Ա��Ϣ�����
	{
		printf("%s   %s     %d     %d     %d     %d     ", arr[i].num, arr[i].name, arr[i].sex, arr[i].age, arr[i].high, arr[i].weight);
		if (1 == arr[i].sex)//���Ϊ����
		{
			printf("%d     %d     --     --  \n", arr[i].sport1, arr[i].sport2);//����û�ж��ܣ�����������  --   --  ��ʾ
			count++;//������++
		}
		else if (0 == arr[i].sex)//���ΪŮ��
		{
			printf("--     --     %d     %d  \n", arr[i].sport1, arr[i].sport2);//Ů��û�г��ܣ���ɽ������  --   --  ��ʾ
		}
	}
	return count;//���ؼ�����count��ֵ��Ҳ������������
}

void my_date(Sport arr[MAX], int num, int tmp)//����ƽ��ֵ ���в���numΪ�˶�Ա��������tmpΪ���˶�Ա����
{
	int sum1 = 0;//��������˶�Ա���ܵĳɼ��ܺ�
	int sum2 = 0;//��������˶�Ա��ɽ�ĳɼ��ܺ�
	int sum3 = 0;//��������˶�Ա���ܵĳɼ��ܺ�
	int sum4 = 0;//��������˶�Ա�����ĳɼ��ܺ�
	int i = 0;
	while (i++ < num)//whileѭ��
	{
		if (1 == arr[i].sex)//���Ϊ��
		{
			sum1 = sum1 + arr[i].sport1;
			sum2 = sum2 + arr[i].sport2;
		}
		else if (0 == arr[i].sex)//���ΪŮ
		{
			sum3 = sum3 + arr[i].sport1;
			sum4 = sum4 + arr[i].sport2;
		}
	}
	printf("����ƽ���ɼ���%d\n", sum1 / tmp);//���ܵĳɼ��ܺͳ����˶�Ա����
	printf("��ɽƽ���ɼ���%d\n", sum2 / tmp);//��ɽ�ĳɼ��ܺͳ����˶�Ա����
	printf("����ƽ���ɼ���%d\n", sum3 / (num - tmp));//���ܵĳɼ��ܺͳ�Ů�˶�Ա������Ҳ�����˶�Ա������ȥ���˶�Ա����
	printf("����ƽ���ɼ���%d\n", sum4 / (num - tmp));//�����ĳɼ��ܺͳ�Ů�˶�Ա������Ҳ�����˶�Ա������ȥ���˶�Ա����
}

int main()//������
{
	int num = 0;//��������˶�Ա����
	int tmp = 0;//����������˶�Ա����
	Sport arr[MAX];//��ʼ���ṹ��Sport��������arr  (arrΪ�������� �������СΪMAX����������˶�Ա��Ϣ
	printf("��������Ҫ������˶�Ա������");
	scanf("%d", &num);//���������˶�Ա����
	my_scanf(arr,num);//���뺯��
	printf("-----------------------------------------------------------\n");
	tmp = my_printf(arr,num);//�����������ֵΪ���˶�Ա��������������tmp
	printf("-----------------------------------------------------------\n");
	my_date(arr, num, tmp);//����ƽ��ֵ
	system("pause");//��vs����������ʱ��ֹ��������������
	return 0;
}