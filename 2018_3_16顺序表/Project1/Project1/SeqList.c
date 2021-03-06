#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"SeqList.h"

void SeqInit(SeqList* pSeq)//顺序表初始化
{
	assert(pSeq);
	pSeq->_a = NULL;
	pSeq->_size = 0;
	pSeq->_capacity = 0;
}

void SeqPrint(SeqList* pSeq)//打印顺序表
{
	assert(pSeq);
	size_t  i = 0;
	if (pSeq->_size == 0)
	{
		printf("该顺序表为空表！\n");
		return;
	}
	for (i = 0; i < pSeq->_size; i++)
	{
		printf("%d ", pSeq->_a[i]);
	}
	printf("\n");
}

void SeqDestory(SeqList* pSeq)//清空顺序表
{
	pSeq->_capacity = 0;
	pSeq->_size = 0;
	free( pSeq->_a);
}

int CheckCapcity(SeqList* pSeq)//检查顺序表容量是否足够
{
	if (pSeq->_size >= pSeq->_capacity)
	{
		DataType* tmp = NULL;
		int capacity = pSeq->_capacity + N;//每次扩容N个DataType类型大小空间
		tmp = (DataType*)realloc(pSeq->_a, sizeof(DataType)*capacity);
		//if (pSeq->_size == 0)
		//{
		//	tmp = (DataType*)malloc(sizeof(DataType)*capacity);
		//	//tmp = (DataType*)realloc(pSeq->_a, sizeof(DataType)*capacity);
		//}
		//else
		//{
		//	tmp = (DataType*)realloc(pSeq->_a,sizeof(DataType)*capacity);
		//}
		if (tmp != NULL)
		{
			pSeq->_capacity = capacity;
			pSeq->_a = tmp;
			return 1;
		}
		printf("顺序表容量扩充失败！！\n");
		return 0;
	}
	return 1;
}

void SeqPushBack(SeqList* pSeq, DataType x)//从尾部插入
{
	assert(pSeq);
	if (!CheckCapcity(pSeq))
	{
		return;
	}
	pSeq-> _a[pSeq->_size]= x;
	pSeq->_size++;
}
void SeqPopBack(SeqList* pSeq)//从尾部删除
{
	assert(pSeq);
	//pSeq->_a[pSeq->_size] = 0;
	pSeq->_size--;
}

void SeqPushFront(SeqList* pSeq, DataType x)//从头部插入
{
	assert(pSeq);
	if (!CheckCapcity(pSeq))
	{
		return;
	}
	size_t i = pSeq->_size;
	for (; i > 0; i--)
	{
		pSeq->_a[i] = pSeq->_a[i - 1];
	}
	pSeq->_a[0] = x;
	pSeq->_size++;
}

void SeqPopFront(SeqList* pSeq)//从头删除
{
	assert(pSeq);
	size_t  i = 1;
	for (i = 1; i < pSeq->_size; i++)
	{
		pSeq->_a[i - 1] = pSeq->_a[i];
	}
	//pSeq->_a[pSeq->_size] = 0;
	pSeq->_size--;
}

void SeqInsert(SeqList* pSeq, size_t pos, DataType x)//从指定位置插入
{
	assert(pSeq);
	if (!CheckCapcity(pSeq))
	{
		return;
	}
	size_t i = pSeq->_size;
	for (; i >= pos; i--)
	{
		pSeq->_a[i] = pSeq->_a[i - 1];
	}
	pSeq->_a[pos-1] = x;
	pSeq->_size++;
}

void SeqErase(SeqList* pSeq, size_t pos)//从指定位置删除
{
	assert(pSeq);
	size_t i = pos;
	for (; i < pSeq->_size; i++)
	{
		pSeq->_a[i - 1] = pSeq->_a[i];
	}
	//pSeq->_a[pSeq->_size] = 0;
	pSeq->_size--;
}

int SeqFind(SeqList* pSeq, DataType x)//寻找某个指定的值
{
	assert(pSeq);
	size_t i = 0;
	for (; i < pSeq->_size; i++)
	{
		if (pSeq->_a[i] == x)
		{
			return i + 1;
		}
	}
	return 0;
}

void SeqAt(SeqList* pSeq, size_t pos, DataType x)//替换指定位置的元素的值
{
	assert(pSeq);
	assert(pos <= pSeq->_size);
	pSeq->_a[pos - 1] = x;
}

void BubbleSort(SeqList* pSeq)//冒泡排序
{
	assert(pSeq);
	size_t i, j;
	for (i = 0; i < pSeq->_size; i++)
	{
		int tmp = 0;
		for (j = 0; j < pSeq->_size - i - 1; j++)
		{
			DataType x;
			if (pSeq->_a[j]>pSeq->_a[j + 1])
			{
				x = pSeq->_a[j];
				pSeq->_a[j] = pSeq->_a[j + 1];
				pSeq->_a[j + 1] = x;
				tmp = 1;
			}
		}
		if (0 == tmp)//经过一次冒泡后没有进行元素的交换则表明当前已经是升序排列，直接return
		{
			return;
		}
	}
}

void SelectSort(SeqList* pSeq)//选择排序
{
	assert(pSeq);
	size_t min = 0;
	size_t max = 0;
	size_t left = 0;
	size_t right = pSeq->_size - 1;
	while (left<right)
	{
		for (size_t i = left; i <= right; i++)
		{
			if (pSeq->_a[min]>pSeq->_a[i])
			{
				min = i;
			}
			if (pSeq->_a[max] < pSeq->_a[i])
			{
				max = i;
			}
		}
		DataType x = pSeq->_a[min];
		pSeq->_a[min] = pSeq->_a[left];
		pSeq->_a[left] = x;
		if (max == left)
		{
			max = min;
		}
		x = pSeq->_a[max];
		pSeq->_a[max] = pSeq->_a[right];
		pSeq->_a[right] = x;//交换可以封装成一个函数，懒，所以没有封装
		left++;
		right--;
	}
}

int BinarySearch(SeqList* pSeq,DataType x)//二分查找
{
	assert(pSeq);
	int left = 0, right = pSeq->_size - 1;
	while (left <= right)
	{
		int mid = ((right - left) / 2) + left;
		if (pSeq->_a[mid] > x)
		{
			right = mid - 1;
		}
		if (pSeq->_a[mid] < x)
		{
			left = mid + 1;
		}
		else 
		{
			return mid + 1;//返回的是要查找的数在表中的位置，如果需要的是下标，直接return mid
		}
	}
	return 0;
}

int main()
{
	SeqList s;
	SeqInit(&s);
	SeqPushBack(&s, 1);
	SeqPushBack(&s, 2);
	SeqPushBack(&s, 3);
	SeqPushBack(&s, 4);
	SeqPushBack(&s, 5);
	SeqPushFront(&s, 6);
	SeqPrint(&s);
	/*SeqPopBack(&s);
	SeqPrint(&s);
	system("pause");
	SeqPushFront(&s, 9);
	SeqPrint(&s);
	system("pause");
	SeqPopFront(&s);
	SeqPrint(&s);*/
	SeqInsert(&s, 3, 9);
	SeqPrint(&s);
	SeqErase(&s, 5);
	SeqPrint(&s);
	printf("你要找的数在该顺序表中的位置是第%d位!\n(0表示该数不在顺序表中！！！)\n", SeqFind(&s, 9));
	SeqAt(&s, 1, 1);
	SeqPrint(&s);
	SelectSort(&s);
	printf("排序后的顺序表为：");
	BubbleSort(&s);
	SeqPrint(&s);
	printf("\n");

	printf("你要找的数在该顺序表中的位置是第%d位!\n(0表示该数不在顺序表中！！！)\n", BinarySearch(&s, 9));

	SeqDestory(&s);
	SeqPrint(&s);

	system("pause");
	return 0;
}