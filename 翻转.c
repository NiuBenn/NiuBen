#define _CRT_SECURE_NO_WARNINGS 1  
#include <stdio.h>    
#include <stdlib.h>    
unsigned int reverse_bit(unsigned int value)
{
	int sum = 0;
	int i = 0;
	int bit = 0;
	for (i = 0; i<32; i++)
	{
		sum = sum << 1;      //����   
		bit = value & 1;     //��λ��   
		sum = sum | bit;     //��λ��   
		value = value >> 1;  //����   
	}
	return sum;
}
int main()
{
	printf("%u\n", reverse_bit(25));
	system("pause");
	return 0;
}