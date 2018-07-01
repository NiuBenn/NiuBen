#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s[100];
	int len, start, end;
	int flag = 0;
	scanf("%s", s);
	len = strlen(s);
	
	for (start = 0, end = len - 1; start <= end; ++start, --end)
	{
		if (s[start] != s[end])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf("是回文");
	}
	else if (flag == 1)
	{
		printf("不是回文");
	}



	system("pause");
	return 0;
}