#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data_structure.h"

/*
根据给定的n个权值构造一棵赫夫曼树,wet中存放n个权值
*/
HuffmanTree create_HuffmanTree(int *wet, int n)
{
	//一棵有n个叶子节点的赫夫曼树共有2n-1个节点
	int total = 2 * n - 1;
	HuffmanTree HT = (HuffmanTree)malloc(total * sizeof(HTNode));
	if (!HT)
	{
		printf("HuffmanTree malloc faild!");
		exit(-1);
	}
	int i;

	//HT[0],HT[1]...HT[n-1]中存放需要编码的n个叶子节点
	for (i = 0; i<n; i++)
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].weight = *wet;
		wet++;
	}

	//HT[n],HT[n+1]...HT[2n-2]中存放的是中间构造出的每棵二叉树的根节点
	for (; i<total; i++)
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
		HT[i].weight = 0;
	}

	int min1, min2; //用来保存每一轮选出的两个weight最小且parent为0的节点
					//每一轮比较后选择出min1和min2构成一课二叉树,最后构成一棵赫夫曼树
	for (i = n; i<total; i++)
	{
		select_minium(HT, i, min1, min2);
		HT[min1].parent = i;
		HT[min2].parent = i;
		//这里左孩子和右孩子可以反过来，构成的也是一棵赫夫曼树，只是所得的编码不同
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight = HT[min1].weight + HT[min2].weight;
	}
	return HT;
}

/*
从HT数组的前k个元素中选出weight最小且parent为0的两个，分别将其序号保存在min1和min2中
*/
void select_minium(HuffmanTree HT, int k, int &min1, int &min2)
{
	min1 = min(HT, k);
	min2 = min(HT, k);
}

/*
从HT数组的前k个元素中选出weight最小且parent为0的元素，并将该元素的序号返回
*/
int min(HuffmanTree HT, int k)
{
	int i = 0;
	int min;        //用来存放weight最小且parent为0的元素的序号
	int min_weight; //用来存放weight最小且parent为0的元素的weight值

					//先将第一个parent为0的元素的weight值赋给min_weight,留作以后比较用。
					//注意，这里不能按照一般的做法，先直接将HT[0].weight赋给min_weight，
					//因为如果HT[0].weight的值比较小，那么在第一次构造二叉树时就会被选走，
					//而后续的每一轮选择最小权值构造二叉树的比较还是先用HT[0].weight的值来进行判断，
					//这样又会再次将其选走，从而产生逻辑上的错误。
	while (HT[i].parent != 0)
		i++;
	min_weight = HT[i].weight;
	min = i;

	//选出weight最小且parent为0的元素，并将其序号赋给min
	for (; i<k; i++)
	{
		if (HT[i].weight<min_weight && HT[i].parent == 0)
		{
			min_weight = HT[i].weight;
			min = i;
		}
	}

	//选出weight最小的元素后，将其parent置0，使得下一次比较时将其排除在外。
	HT[min].parent = 1;

	return min;
}

/*
从叶子节点到根节点逆向求赫夫曼树HT中n个叶子节点的赫夫曼编码，并保存在HC中
*/
void HuffmanCoding(HuffmanTree HT, HuffmanCode &HC, int n)
{
	//用来保存指向每个赫夫曼编码串的指针
	HC = (HuffmanCode)malloc(n * sizeof(char *));
	if (!HC)
	{
		printf("HuffmanCode malloc faild!");
		exit(-1);
	}

	//临时空间，用来保存每次求得的赫夫曼编码串
	char *code = (char *)malloc(n * sizeof(char));
	if (!code)
	{
		printf("code malloc faild!");
		exit(-1);
	}

	code[n - 1] = '\0';  //编码结束符，亦是字符数组的结束标志
						 //求每个字符的赫夫曼编码
	int i;
	for (i = 0; i<n; i++)
	{
		int current = i;           //定义当前访问的节点
		int father = HT[i].parent; //当前节点的父节点
		int start = n - 1;           //每次编码的位置，初始为编码结束符的位置
									 //从叶子节点遍历赫夫曼树直到根节点
		while (father != 0)
		{
			if (HT[father].lchild == current)   //如果是左孩子，则编码为0
				code[--start] = '0';
			else                              //如果是右孩子，则编码为1       
				code[--start] = '1';
			current = father;
			father = HT[father].parent;
		}

		//为第i个字符的编码串分配存储空间
		HC[i] = (char *)malloc((n - start) * sizeof(char));
		if (!HC[i])
		{
			printf("HC[i] malloc faild!");
			exit(-1);
		}
		//将编码串从code复制到HC
		strcpy(HC[i], code + start);
	}

	free(code); //释放保存编码串的临时空间
}