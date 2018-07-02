#define _CRT_SECURE_NO_WARNINGS 1//vs编译器下防止scanf函数报警告
#define MAX 50//宏定义MAX为50

#include<stdio.h>
#include<stdlib.h>

enum SEX//定义枚举类型sex（性别），作用：增加代码可读性
{
	GG = 1, MM = 0  //男为1，女为0
};

typedef struct Sport//定义结构体sport用来存放运动员的信息
{
	char num[5];//编号
	char name[20];//姓名
	enum SEX sex;//性别
	int age;//年龄
	int high;//身高
	int weight;//体重
	int sport1;//如果为男生，该项表示长跑成绩，如果为女生表示短跑成绩
	int sport2;//如果为男生，该项表示登山成绩，如果为女生表示跳绳成绩
}Sport;

void my_scanf(Sport arr[MAX], int num)//输入函数 其中num为运动员个数
{
	int i = 0;
	while (i++ < num)//用while循环实现多位训动员信息的输入
	{
		printf("\n请输入第%d位运动员的信息：\n",i);
		printf("请输入运动员的编号：");
		scanf("%s", &arr[i].num);
		printf("请输入运动员的姓名：");
		scanf("%s", &arr[i].name);
		printf("请输入运动员的性别：");
		scanf("%d", &arr[i].sex);
		printf("请输入运动员的年龄：");
		scanf("%d", &arr[i].age);
		printf("请输入运动员的身高：");
		scanf("%d", &arr[i].high);
		printf("请输入运动员的体重：");
		scanf("%d", &arr[i].weight);
		if (1 == arr[i].sex)//如果性别为男
		{
			printf("请输入运动员的长跑成绩：");
			scanf("%d", &arr[i].sport1);
			printf("请输入运动员的登山成绩：");
			scanf("%d", &arr[i].sport2);
		}
		else if (0 == arr[i].sex)//如果性别为女
		{
			printf("请输入运动员的短跑成绩：");
			scanf("%d", &arr[i].sport1);
			printf("请输入运动员的跳绳成绩：");
			scanf("%d", &arr[i].sport2);
		}
	}
}

int my_printf(Sport arr[MAX], int num)//输出函数 其中num为运动员个数
{
	int count = 0;//计数器，永嘉计算男运动员个数，待函数结束时作为返回值返回
	int i = 0;
	printf("编号   姓名   性别   年龄   身高    体重   长跑   登山   短跑   跳绳\n");
	while(i++ < num)//用while循环实现多位训动员信息的输出
	{
		printf("%s   %s     %d     %d     %d     %d     ", arr[i].num, arr[i].name, arr[i].sex, arr[i].age, arr[i].high, arr[i].weight);
		if (1 == arr[i].sex)//如果为男生
		{
			printf("%d     %d     --     --  \n", arr[i].sport1, arr[i].sport2);//男生没有短跑，跳绳所以用  --   --  表示
			count++;//计数器++
		}
		else if (0 == arr[i].sex)//如果为女生
		{
			printf("--     --     %d     %d  \n", arr[i].sport1, arr[i].sport2);//女生没有长跑，登山所以用  --   --  表示
		}
	}
	return count;//返回计数器count的值，也就是男生个数
}

void my_date(Sport arr[MAX], int num, int tmp)//计算平均值 其中参数num为运动员总人数，tmp为男运动员个数
{
	int sum1 = 0;//存放所有运动员长跑的成绩总和
	int sum2 = 0;//存放所有运动员登山的成绩总和
	int sum3 = 0;//存放所有运动员短跑的成绩总和
	int sum4 = 0;//存放所有运动员跳绳的成绩总和
	int i = 0;
	while (i++ < num)//while循环
	{
		if (1 == arr[i].sex)//如果为男
		{
			sum1 = sum1 + arr[i].sport1;
			sum2 = sum2 + arr[i].sport2;
		}
		else if (0 == arr[i].sex)//如果为女
		{
			sum3 = sum3 + arr[i].sport1;
			sum4 = sum4 + arr[i].sport2;
		}
	}
	printf("长跑平均成绩：%d\n", sum1 / tmp);//长跑的成绩总和除男运动员人数
	printf("登山平均成绩：%d\n", sum2 / tmp);//登山的成绩总和除男运动员人数
	printf("短跑平均成绩：%d\n", sum3 / (num - tmp));//短跑的成绩总和除女运动员人数（也就是运动员总数减去男运动员数）
	printf("跳绳平均成绩：%d\n", sum4 / (num - tmp));//跳绳的成绩总和除女运动员人数（也就是运动员总数减去男运动员数）
}

int main()//主函数
{
	int num = 0;//用来存放运动员个数
	int tmp = 0;//用来存放男运动员个数
	Sport arr[MAX];//初始化结构体Sport类型数组arr  (arr为数组名） ，数组大小为MAX。用来存放运动员信息
	printf("请输入你要输入的运动员个数：");
	scanf("%d", &num);//键盘输入运动员个数
	my_scanf(arr,num);//输入函数
	printf("-----------------------------------------------------------\n");
	tmp = my_printf(arr,num);//输出函数返回值为男运动员个数，把它赋给tmp
	printf("-----------------------------------------------------------\n");
	my_date(arr, num, tmp);//计算平均值
	system("pause");//用vs编译器编译时防止编译器运行闪退
	return 0;
}