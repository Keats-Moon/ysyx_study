#include<stdio.h>
int a[4] = {1,2,3,4};
int b[4];
int main(void)
{
	for (int i = 0;i<4;i++)
	{
		b[i]=a[i];
		printf("%d",b[i]);
	}
	return 0;
}