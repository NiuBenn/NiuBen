#pragma once
#define N 3//顺序表容量不足时扩充的大小
typedef int DataType;

typedef struct SeqList
{
	DataType* _a;
	size_t _size;	// 有效数据个数 
	size_t _capacity;	// 容量 
}SeqList;

void SeqPrint(SeqList* pSeq);//打印顺序表
void SeqInit(SeqList* pSeq);//初始化顺序表
void SeqDestory(SeqList* pSeq);//删除顺序表
int CheckCapcity(SeqList* pSeq);//检查顺序表容量是否足够

void SeqPushBack(SeqList* pSeq, DataType x);//从尾部插入数据
void SeqPopBack(SeqList* pSeq);////从尾部删除数据
void SeqPushFront(SeqList* pSeq, DataType x);//从头部插入数据
void SeqPopFront(SeqList* pSeq);////从头部删除数据

void SeqInsert(SeqList* pSeq, size_t pos, DataType x);//从指定位置插入数据
void SeqErase(SeqList* pSeq, size_t pos);//从指定位置删除数据

int SeqFind(SeqList* pSeq, DataType x);//寻找某个指定的值
void SeqAt(SeqList* pSeq, size_t pos, DataType x);//替换指定位置的元素的值

void BubbleSort(SeqList* pSeq);//对顺序表元素进行冒泡排序
void SelectSort(SeqList* pSeq);//对顺序表元素进行选择排序
int BinarySearch(SeqList* pSeq,DataType x);//使用二分查找查找指定元素