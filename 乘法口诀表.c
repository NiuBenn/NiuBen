#include<stdio.h>
int main()
{
	int i, j, m;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			m = i*j;
			printf("%d*%d=%d\t", i, j, m);
		}
		printf("\n");
	}
	getchar();
	system("paush");//½â¾övsÉÁÍË
	return 0;
}