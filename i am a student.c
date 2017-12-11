#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

int my_strlen(const char* str)
{
	int len = 0;
	assert(str);
	while (*str++)
	{
		len++;
	}
	return len;
}

void exchange(char* start, char* end)
{
	assert(start);
	assert(end);
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

void str_exchange(char *arr)
{
	int len = my_strlen(arr);
	exchange(arr, arr + len - 1);
	while (*arr)
	{
		char *tmp = arr;
		while ((*arr != ' ') && (*arr != '\0'))
		{
			arr++;
		}
		exchange(tmp, arr - 1);
		if (*arr == ' ')
		{
			arr++;
		}
	}
}

int main()
{
	char arr[] = "student a am i";
	int len = my_strlen(arr);
	str_exchange(arr);
	
	printf("%s", arr);
	system("pause");
	return 0;
}
