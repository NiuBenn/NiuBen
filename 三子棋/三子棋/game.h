#ifndef __GAME_H__
#define __GAME_H__

#define RCW 3
#define COL 3
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>


void welcome();//初始化界面
void menu();//主菜单界面
void menuone();//模式选择菜单界面
void printboard(char board[RCW][COL], int rcw, int col);//打印棋盘
void game();//开始游戏
void game1();//人机对战
void game2();//人人对战
void Manplay1(char board[RCW][COL], int rcw, int col);//玩家一下棋
void Manplay2(char board[RCW][COL], int rcw, int col);//玩家二下棋
void Computerplay(char board[RCW][COL], int rcw, int col);//电脑下棋
char CheckWin(char board[RCW][COL], int row, int col); // 判断输赢

#endif    //__GAME_H__
