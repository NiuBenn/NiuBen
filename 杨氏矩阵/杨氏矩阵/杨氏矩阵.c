#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

#define ROW 3
#define COL 3

int judge(int arr[ROW][COL], int num)
{
	int i = 0;
	int j = COL - 1;
	int temp = arr[i][j];

	while (1)
	{
		if (num == temp)
		{
			return 1;
		}
		else if (temp < num&&j >= 0)
		{

			temp = arr[i][j++];
		}
		else if (temp>num&&i <= (ROW - 1))
		{
			temp = arr[i++][j];
		}
		else
		{
			return 0;
		}
	}
}
int main()
{

	int arr[ROW][COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i = 0, j = 0;
	int num = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%-5d", arr[i][j]);
		}

		printf("\n");
	}
	printf("please enter a number:");
	scanf_s("%d", &num);

	if (judge(arr, num))
	{
		printf("%d is included.\n", num);
	}
	else
	{
		printf("%d is not included.\n", num);
	}
	system("pause");
	return 0;
}


