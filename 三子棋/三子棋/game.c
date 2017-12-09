#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void welcome()//初始化 欢迎界面
{
	printf("                                 \n");
	printf("       欢迎试玩三子棋游戏        \n");
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
	printf("** 1.人机对战 **** 2.人人对战 **\n");
	printf("** 0.返回上一菜单 **************\n");
	printf("********************************\n");
}

void printboard(char board[RCW][COL], int rcw, int col)//打印棋盘
{
	int i = 0;
	for (i = 0; i < rcw; i++)
	{
		printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
		if (i != 2)
			printf("|---|---|---|\n");
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
			game1();//人机对战
			break;
		case 2:
			game2();//人人对战
			break;
		case 0:
			break;
		default:
			printf("输入错误！\n");
			break;
		}
	} while (input);
}

void game1()//人机对战
{
	char board[RCW][COL] = { 0 };
	memset(board, ' ', RCW*COL * sizeof(board[0][0]));
	int i = 9;
	while (1)
	{
		if (i <= 0)
			break;
		Manplay1(board, RCW, COL);
		i--;
		if (CheckWin(board, RCW, COL) == 'X')
		{
			printf("玩家获胜！\n");
			goto flag3;
		}
		printboard(board, RCW, COL);
		printf("电脑下棋....\n");
		Sleep(1000);
		if (i <= 0)
			break;
		Computerplay(board, RCW, COL);
		i--;
		if (CheckWin(board, RCW, COL) == '0')
		{
			printf("电脑获胜！\n");
			goto flag3;
		}
		printboard(board, RCW, COL);
	}
	printf("平局\n");
flag3:
	printboard(board, RCW, COL);
}

void game2()//人人对战
{
	char board[RCW][COL] = { 0 };
	memset(board, ' ', RCW*COL * sizeof(board[0][0]));
	int i = 9;
	while (1)
	{
		printf("玩家X下棋....\n\n");
		if (i <= 0)
			break;
		Manplay1(board, RCW, COL);
		i--;
		if (CheckWin(board, RCW, COL) == 'X')
		{
			printf("玩家X获胜！\n");
			goto flag4;
		}
		printboard(board, RCW, COL);
		printf("玩家0下棋....\n\n");
		if (i <= 0)
			break;
		Manplay2(board, RCW, COL);
		i--;
		if (CheckWin(board, RCW, COL) == '0')
		{
			printf("玩家0获胜！\n");
			goto flag4;
		}
		printboard(board, RCW, COL);
	}
	printf("平局\n");
flag4:
	printboard(board, RCW, COL);
}


void Manplay1(char board[RCW][COL], int rcw, int col)//玩家1下棋
{
	int x = 0;
	int y = 0;
	printf("请输入你要下的位置：");
flag1:
	scanf("%d%d", &x, &y);
	if (x > rcw || y > col || x < 0 || y < 0 || (board[x - 1][y - 1] != ' '))
	{
		printf("该位置无效，请重新输入：");
		goto flag1;
	}
	board[x - 1][y - 1] = 'X';
}
void Manplay2(char board[RCW][COL], int rcw, int col)//玩家2下棋
{
	int x = 0;
	int y = 0;
	printf("请输入你要下的位置：");
flag3:
	scanf("%d%d", &x, &y);
	if (x > rcw || y > col || x < 0 || y < 0 || (board[x - 1][y - 1] != ' '))
	{
		printf("该位置无效，请重新输入：");
		goto flag3;
	}
	board[x - 1][y - 1] = '0';
}
void Computerplay(char board[RCW][COL], int rcw, int col)//电脑下棋
{

	int x = 0;
	int y = 0;
flag2:
	x = rand() % 3;
	y = rand() % 3;
	if (board[x][y] != ' ')
		goto flag2;
	board[x][y] = '0';
}

char CheckWin(char board[RCW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != ' ')
		return board[1][1];
	return 0;
}