#pragma once
#define N 3//˳�����������ʱ����Ĵ�С
typedef int DataType;

typedef struct SeqList
{
	DataType* _a;
	size_t _size;	// ��Ч���ݸ��� 
	size_t _capacity;	// ���� 
}SeqList;

void SeqPrint(SeqList* pSeq);//��ӡ˳���
void SeqInit(SeqList* pSeq);//��ʼ��˳���
void SeqDestory(SeqList* pSeq);//ɾ��˳���
int CheckCapcity(SeqList* pSeq);//���˳��������Ƿ��㹻

void SeqPushBack(SeqList* pSeq, DataType x);//��β����������
void SeqPopBack(SeqList* pSeq);////��β��ɾ������
void SeqPushFront(SeqList* pSeq, DataType x);//��ͷ����������
void SeqPopFront(SeqList* pSeq);////��ͷ��ɾ������

void SeqInsert(SeqList* pSeq, size_t pos, DataType x);//��ָ��λ�ò�������
void SeqErase(SeqList* pSeq, size_t pos);//��ָ��λ��ɾ������

int SeqFind(SeqList* pSeq, DataType x);//Ѱ��ĳ��ָ����ֵ
void SeqAt(SeqList* pSeq, size_t pos, DataType x);//�滻ָ��λ�õ�Ԫ�ص�ֵ

void BubbleSort(SeqList* pSeq);//��˳���Ԫ�ؽ���ð������
void SelectSort(SeqList* pSeq);//��˳���Ԫ�ؽ���ѡ������
int BinarySearch(SeqList* pSeq,DataType x);//ʹ�ö��ֲ��Ҳ���ָ��Ԫ��