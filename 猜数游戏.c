#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
void welcome()//��ʼ�� ��ӭ����
{
	printf("                                 \n");
	printf("        ��ӭ���������Ϸ         \n");
	printf("      ���԰� * �汾�� 1.1.0      \n");
	printf("      �����ˣ�  Edision Niu      \n");
	printf("*******��Ϸ������BUG�뷴��*******\n");
	printf("                                 \n");
	printf("��Ϸ�Ѽ�����ϣ��밴���������......\n");
	getchar();
	system("cls");//����
}

void menu()//���˵�
{
	printf("********************************\n");
	printf("** 0.�˳���Ϸ **** 1.��ʼ��Ϸ **\n");
	printf("********************************\n");
}

void menuone()//��Ϸģʽѡ��˵�
{
	printf("********************************\n");
	printf("** 1.��ͨģʽ **** 2.��սģʽ **\n");
	printf("** 0.������һ�˵� **************\n");
	printf("********************************\n");
}

void gameone()//��ͨģʽ����Ϸ��
{
	int num = 0;
	int input = 0;
	int start = 0;
	int end = 0;
	num = rand() % 100 + 1;//���������
	start = GetTickCount();
	while (1)
	{
		printf("������֣�\n");
		scanf("%d", &input);
		system("cls");
		if (input == num)
		{
			printf("��ϲ�㣬�¶��ˣ�\n");
			end = GetTickCount();
			printf("�˴β�����ʱ%d�룡\n", (end - start) / 1000);
			break;
		}
		else if (input > num)
		{
			printf("�´��ˣ�\n");
		}
		else
		{
			printf("��С�ˣ�\n");
		}
	}
}

void gametwo()//��սģʽ����Ϸ��
{
	int num = 0;
	int input = 0;
	int start = 0;
	int end = 0;
	int tmp = 0;
	int t = 0;
	num = rand() % 100 + 1;//���������
	printf("�Լ�������սʱ�䣬������սʱ���ڲ³����֣���\nף����ˣ���\n");
	printf("��������Ҫ��ս��ʱ�䣨�룩��");
	scanf("%d", &t);
	start = GetTickCount();
	while (1)
	{
		printf("������֣�\n");
		scanf("%d", &input);
		tmp = GetTickCount();
		system("cls");
		if (((tmp - start) / 1000) >= t)//�ж��Ƿ�ʱ
		{
			printf("������ʱ����սʧ�ܣ�\n");
			break;
		}
		if (input == num)
		{
			printf("��ϲ�㣬��ս�ɹ���\n");
			end = GetTickCount();
			printf("�˴β�����ʱ%d�룡\n", (end - start) / 1000);
			break;
		}
		else if (input > num)
		{
			printf("�´��ˣ�\n");
		}
		else
		{
			printf("��С�ˣ�\n");
		}
	}
}

void game()//��Ϸģʽѡ��
{
	int input = 0;
	do
	{
		menuone();
		printf("��ѡ��");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			gameone();//��ͨģʽ
			break;
		case 2:
			gametwo();//��սģʽ
			break;
		case 0:
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);
}

int main()
{
	int input = 0;
	welcome();//��ӭ����
	system("color 0A");
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			game();//��Ϸģʽѡ��
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}