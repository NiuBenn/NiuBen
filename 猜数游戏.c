#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
void welcome()//初始化 欢迎界面
{
	printf("                                 \n");
	printf("        欢迎试玩猜数游戏         \n");
	printf("      测试版 * 版本号 1.1.0      \n");
	printf("      制作人：  Edision Niu      \n");
	printf("*******游戏中如遇BUG请反馈*******\n");
	printf("                                 \n");
	printf("游戏已加载完毕，请按任意键继续......\n");
	getchar();
	system("cls");//清屏
}

void menu()//主菜单
{
	printf("********************************\n");
	printf("** 0.退出游戏 **** 1.开始游戏 **\n");
	printf("********************************\n");
}

void menuone()//游戏模式选择菜单
{
	printf("********************************\n");
	printf("** 1.普通模式 **** 2.挑战模式 **\n");
	printf("** 0.返回上一菜单 **************\n");
	printf("********************************\n");
}

void gameone()//普通模式（游戏）
{
	int num = 0;
	int input = 0;
	int start = 0;
	int end = 0;
	num = rand() % 100 + 1;//产生随机数
	start = GetTickCount();
	while (1)
	{
		printf("请猜数字：\n");
		scanf("%d", &input);
		system("cls");
		if (input == num)
		{
			printf("恭喜你，猜对了！\n");
			end = GetTickCount();
			printf("此次猜数用时%d秒！\n", (end - start) / 1000);
			break;
		}
		else if (input > num)
		{
			printf("猜大了！\n");
		}
		else
		{
			printf("猜小了！\n");
		}
	}
}

void gametwo()//挑战模式（游戏）
{
	int num = 0;
	int input = 0;
	int start = 0;
	int end = 0;
	int tmp = 0;
	int t = 0;
	num = rand() % 100 + 1;//产生随机数
	printf("自己设置挑战时间，请在挑战时间内猜出数字！！\n祝你好运！！\n");
	printf("请输入你要挑战的时间（秒）：");
	scanf("%d", &t);
	start = GetTickCount();
	while (1)
	{
		printf("请猜数字：\n");
		scanf("%d", &input);
		tmp = GetTickCount();
		system("cls");
		if (((tmp - start) / 1000) >= t)//判断是否超时
		{
			printf("猜数超时，挑战失败！\n");
			break;
		}
		if (input == num)
		{
			printf("恭喜你，挑战成功！\n");
			end = GetTickCount();
			printf("此次猜数用时%d秒！\n", (end - start) / 1000);
			break;
		}
		else if (input > num)
		{
			printf("猜大了！\n");
		}
		else
		{
			printf("猜小了！\n");
		}
	}
}

void game()//游戏模式选择
{
	int input = 0;
	do
	{
		menuone();
		printf("请选择：");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			gameone();//普通模式
			break;
		case 2:
			gametwo();//挑战模式
			break;
		case 0:
			break;
		default:
			printf("输入错误！\n");
			break;
		}
	} while (input);
}

int main()
{
	int input = 0;
	welcome();//欢迎界面
	system("color 0A");
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			game();//游戏模式选择
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误！\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}