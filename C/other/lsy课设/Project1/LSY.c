#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum SEX//定义枚举类型sex（性别），作用：增加代码可读性
{
	boy = 1, girl = 0  //男为1，女为0
};

typedef struct student
{
	char num[15];//学号   
	char name[15]; //姓名
	enum SEX sex;//性别
	char class[10];//班级
	int math;  //数学成绩    
	int english; //英语成绩     
	int chinese; //语文成绩
	int average;//平均成绩
}student;

int menu_select() //主菜单选择界面                             
{
	char c = 0;
	do {
		system("cls");
		printf("\t\t ╭═══════■□■□═════╮\n");
		printf("\t\t│         学生信息管理系统         │\n");
		printf("\t\t╰═════■□■□════════╯\n");
		printf("\t\t   ┌─────────────—┐\n");
		printf("\t\t   │ 1. 输入信息    2. 求平均分 │\n");
		printf("\t\t   │                            │\n");
		printf("\t\t   │ 3. 排序        4. 查询     │\n");
		printf("\t\t   │                            │\n");
		printf("\t\t   │ 5. 输出信息    6. 退出系统 │\n");
		printf("\t\t   └─────────────—┘\n");
		printf("\t\t请您选择(1-6):");
		c = getchar();
	} while (c<'1' || c>'6');
	return (c - '0');
}

void average(student arr[MAX])
{
	int i = 0;
	printf("\t\t *^_^* 求平均分 *^_^*\n");
	printf("学号       姓名 性别   班级    平均成绩\n");
	while (i < MAX)
	{
		arr[i].average = (arr[i].math + arr[i].english + arr[i].chinese) / 3;
		printf("%s  %s  %d  %s  %d \n", arr[i].num, arr[i].name, arr[i].sex, arr[i].class, arr[i].average);
		i++;
	}
	printf("请按任意键返回主菜单！");
	system("pause");
}
void input(student arr[MAX])
{
	int i = 0;
	while (i < MAX)
	{
		system("cls");
		printf("\t\t *^_^* 输入信息 *^_^*\n");
		printf("请输入第%d个学生的信息：\n",i+1);
		printf("请输入该学生的学号：");
		scanf("%s", &arr[i].num);
		printf("请输入该学生的姓名：");
		scanf("%s", &arr[i].name);
		printf("请输入该学生的性别：");
		scanf("%d", &arr[i].sex);
		printf("请输入该学生的班级：");
		scanf("%s", &arr[i].class);
		printf("请输入该学生的数学成绩：");
		scanf("%d", &arr[i].math);
		printf("请输入该学生的英语成绩：");
		scanf("%d", &arr[i].english);
		printf("请输入该学生的语文成绩：");
		scanf("%d", &arr[i].chinese);
		i++;
	}
	printf("成绩输入完毕！");
	system("pause");
}

void output(student arr[MAX])//输出信息
{
	int i = 0;
	system("cls");
	printf("学号       姓名 性别   班级   数学    英语    语文  平均成绩\n");
	while (i < MAX)
	{
		printf("%s %s %d  %s   %d   %d   %d   %d\n", arr[i].num, arr[i].name, arr[i].sex, arr[i].class, arr[i].math, arr[i].english, arr[i].chinese, arr[i].average);
		i++;
	}
	system("pause");
}

void sort(student arr[MAX])//排序
{
	int temp1 = 0;
	int i = 0;
	int j = 0;
	system("cls");
	printf("\t\t *^_^*   排序   *^_^*\n");
	printf("\t\t   ┌───────────——──——┐\n");
	printf("\t\t   │ 1. 按学号排序    2. 按平均分排序 │\n");
	printf("\t\t   └─────────———────—┘\n");
	printf("请输入排序的方式：");
	scanf("%d", &temp1);
	while (temp1!= 1 && temp1!= 2)
	{
		printf("输入错误请重新输入您要排序的方式：");
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
	printf("排序结果如下：\n");
	output(arr);
}

void query(student arr[MAX])//查询
{
	int temp = 0;
	int i = 0;
	char s[15];
	system("cls");
	printf("\t\t *^_^*   查询   *^_^*\n");
	printf("\t\n请选择查询方式:\n");
	printf("\t┌──────┐\n");
	printf("\t│1------姓名 │\n");
	printf("\t│2------学号 │\n");
	printf("\t│3------返回 │\n");
	printf("\t└──────┘\n");
	printf("请输入你要查询的方式\n");
	scanf("%d", &temp);
	while (temp != 1 && temp != 2 && temp != 3)
	{
		printf("输入错误请重新查询\n");
		scanf("%d", &temp);
	}
	if (1 == temp)
	{
		printf("输入您要查询的姓名：");
		scanf("%s", s);
		i = 0;
		while (strcmp(arr[i].name, s) != 0 && i < MAX)
		{
			i++;
		}
		if (MAX == i)
		{
			printf("成绩系统中没有此人!\n");
			system("pause");
			return;
		}
		printf("\t学号: %s\n", arr[i].num);
		printf("\t姓名: %s\n", arr[i].name);
		printf("\t性别: %d\n", arr[i].sex);
		printf("\t班级: %s\n", arr[i].class);
		printf("\t数学: %d\n", arr[i].math);
		printf("\t英语: %d\n", arr[i].english);
		printf("\t语文: %d\n", arr[i].chinese);
	}
	if (2 == temp)
	{
		printf("输入您要查询的学号：");
		scanf("%s", s);
		i = 0;
		while (strcmp(arr[i].num, s) != 0 && i < MAX)
		{
			i++;
		}
		if (MAX == i)
		{
			printf("成绩系统中没有此人!\n");
			system("pause");
			return;
		}
		printf("\t学号: %s\n", arr[i].num);
		printf("\t姓名: %s\n", arr[i].name);
		printf("\t性别: %d\n", arr[i].sex);
		printf("\t班级: %s\n", arr[i].class);
		printf("\t数学: %d\n", arr[i].math);
		printf("\t英语: %d\n", arr[i].english);
		printf("\t语文: %d\n", arr[i].chinese);
	}
	printf("查找完毕");
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
			printf("\n\t\t谢谢使用，再见!\n");
			system("pause");
			exit(0);
		}
	}
	system("pause");
	return 0;
}