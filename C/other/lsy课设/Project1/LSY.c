#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum SEX//����ö������sex���Ա𣩣����ã����Ӵ���ɶ���
{
	boy = 1, girl = 0  //��Ϊ1��ŮΪ0
};

typedef struct student
{
	char num[15];//ѧ��   
	char name[15]; //����
	enum SEX sex;//�Ա�
	char class[10];//�༶
	int math;  //��ѧ�ɼ�    
	int english; //Ӣ��ɼ�     
	int chinese; //���ĳɼ�
	int average;//ƽ���ɼ�
}student;

int menu_select() //���˵�ѡ�����                             
{
	char c = 0;
	do {
		system("cls");
		printf("\t\t �q�T�T�T�T�T�T�T���������T�T�T�T�T�r\n");
		printf("\t\t��         ѧ����Ϣ����ϵͳ         ��\n");
		printf("\t\t�t�T�T�T�T�T���������T�T�T�T�T�T�T�T�s\n");
		printf("\t\t   ��������������������������������\n");
		printf("\t\t   �� 1. ������Ϣ    2. ��ƽ���� ��\n");
		printf("\t\t   ��                            ��\n");
		printf("\t\t   �� 3. ����        4. ��ѯ     ��\n");
		printf("\t\t   ��                            ��\n");
		printf("\t\t   �� 5. �����Ϣ    6. �˳�ϵͳ ��\n");
		printf("\t\t   ��������������������������������\n");
		printf("\t\t����ѡ��(1-6):");
		c = getchar();
	} while (c<'1' || c>'6');
	return (c - '0');
}

void average(student arr[MAX])
{
	int i = 0;
	printf("\t\t *^_^* ��ƽ���� *^_^*\n");
	printf("ѧ��       ���� �Ա�   �༶    ƽ���ɼ�\n");
	while (i < MAX)
	{
		arr[i].average = (arr[i].math + arr[i].english + arr[i].chinese) / 3;
		printf("%s  %s  %d  %s  %d \n", arr[i].num, arr[i].name, arr[i].sex, arr[i].class, arr[i].average);
		i++;
	}
	printf("�밴������������˵���");
	system("pause");
}
void input(student arr[MAX])
{
	int i = 0;
	while (i < MAX)
	{
		system("cls");
		printf("\t\t *^_^* ������Ϣ *^_^*\n");
		printf("�������%d��ѧ������Ϣ��\n",i+1);
		printf("�������ѧ����ѧ�ţ�");
		scanf("%s", &arr[i].num);
		printf("�������ѧ����������");
		scanf("%s", &arr[i].name);
		printf("�������ѧ�����Ա�");
		scanf("%d", &arr[i].sex);
		printf("�������ѧ���İ༶��");
		scanf("%s", &arr[i].class);
		printf("�������ѧ������ѧ�ɼ���");
		scanf("%d", &arr[i].math);
		printf("�������ѧ����Ӣ��ɼ���");
		scanf("%d", &arr[i].english);
		printf("�������ѧ�������ĳɼ���");
		scanf("%d", &arr[i].chinese);
		i++;
	}
	printf("�ɼ�������ϣ�");
	system("pause");
}

void output(student arr[MAX])//�����Ϣ
{
	int i = 0;
	system("cls");
	printf("ѧ��       ���� �Ա�   �༶   ��ѧ    Ӣ��    ����  ƽ���ɼ�\n");
	while (i < MAX)
	{
		printf("%s %s %d  %s   %d   %d   %d   %d\n", arr[i].num, arr[i].name, arr[i].sex, arr[i].class, arr[i].math, arr[i].english, arr[i].chinese, arr[i].average);
		i++;
	}
	system("pause");
}

void sort(student arr[MAX])//����
{
	int temp1 = 0;
	int i = 0;
	int j = 0;
	system("cls");
	printf("\t\t *^_^*   ����   *^_^*\n");
	printf("\t\t   ��������������������������������������\n");
	printf("\t\t   �� 1. ��ѧ������    2. ��ƽ�������� ��\n");
	printf("\t\t   ��������������������������������������\n");
	printf("����������ķ�ʽ��");
	scanf("%d", &temp1);
	while (temp1!= 1 && temp1!= 2)
	{
		printf("�������������������Ҫ����ķ�ʽ��");
		scanf("%d", &temp1);
	}
	if (1 == temp1)
	{
		for (j = 0; j < MAX-1; j++)
		{
			for (i = 0;  i < MAX-1-j; i++)
				if(strcmp(arr[i].num,arr[i+1].num)>0)
				{
					arr[MAX] = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = arr[MAX];
				}			
		}
	}
	if (2 == temp1)
	{
		for (j = 0; j < MAX - 1; j++)
		{
			for (i = 0; i < MAX - 1 - j; i++)
				if (arr[i].average > arr[i+1].average)
				{
					arr[MAX] = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = arr[MAX];
				}
		}
	}
	printf("���������£�\n");
	output(arr);
}

void query(student arr[MAX])//��ѯ
{
	int temp = 0;
	int i = 0;
	char s[15];
	system("cls");
	printf("\t\t *^_^*   ��ѯ   *^_^*\n");
	printf("\t\n��ѡ���ѯ��ʽ:\n");
	printf("\t����������������\n");
	printf("\t��1------���� ��\n");
	printf("\t��2------ѧ�� ��\n");
	printf("\t��3------���� ��\n");
	printf("\t����������������\n");
	printf("��������Ҫ��ѯ�ķ�ʽ\n");
	scanf("%d", &temp);
	while (temp != 1 && temp != 2 && temp != 3)
	{
		printf("������������²�ѯ\n");
		scanf("%d", &temp);
	}
	if (1 == temp)
	{
		printf("������Ҫ��ѯ��������");
		scanf("%s", s);
		i = 0;
		while (strcmp(arr[i].name, s) != 0 && i < MAX)
		{
			i++;
		}
		if (MAX == i)
		{
			printf("�ɼ�ϵͳ��û�д���!\n");
			system("pause");
			return;
		}
		printf("\tѧ��: %s\n", arr[i].num);
		printf("\t����: %s\n", arr[i].name);
		printf("\t�Ա�: %d\n", arr[i].sex);
		printf("\t�༶: %s\n", arr[i].class);
		printf("\t��ѧ: %d\n", arr[i].math);
		printf("\tӢ��: %d\n", arr[i].english);
		printf("\t����: %d\n", arr[i].chinese);
	}
	if (2 == temp)
	{
		printf("������Ҫ��ѯ��ѧ�ţ�");
		scanf("%s", s);
		i = 0;
		while (strcmp(arr[i].num, s) != 0 && i < MAX)
		{
			i++;
		}
		if (MAX == i)
		{
			printf("�ɼ�ϵͳ��û�д���!\n");
			system("pause");
			return;
		}
		printf("\tѧ��: %s\n", arr[i].num);
		printf("\t����: %s\n", arr[i].name);
		printf("\t�Ա�: %d\n", arr[i].sex);
		printf("\t�༶: %s\n", arr[i].class);
		printf("\t��ѧ: %d\n", arr[i].math);
		printf("\tӢ��: %d\n", arr[i].english);
		printf("\t����: %d\n", arr[i].chinese);
	}
	printf("�������");
	system("pause");
}



int main()
{
	student arr[MAX+1];
	while (1)
	{
		switch (menu_select())
		{
		case 1:
			input(arr);
			break;
		case 2:
			average(arr);
			break;
		case 3:
			sort(arr);
			break;
		case 4:
			query(arr);
			break;
		case 5:
			output(arr);
			break;
		case 6:
			printf("\n\t\tллʹ�ã��ټ�!\n");
			system("pause");
			exit(0);
		}
	}
	system("pause");
	return 0;
}