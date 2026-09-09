#include<stdio.h>
int count()
{
	int n=1;int num1=0;int num10=0;
	while(n<100)
	{
		if(n/10==9)
		{
			num10++;
		}
		if((n-n/10*10)==9)
		{
			num1++;
		}
		n++;

	}
	printf("%d,%d\n",num1,num10);
	return num1+num10;
}

int main()
{
	int x;
	x=count();
	printf("%d\n",x);
	return 0;
}