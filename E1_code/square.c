#include<stdio.h>

double get_square (double x,int n)
{
	if (n<0)
	{
		printf("wrong!\n");
		return -1;
	}
	
	if (n==0)
	{
		return 1;
	}
	else if (n%2==0)
	{
		return get_square(x*x,n/2);
	}
	else
	{
		return x*get_square(x,n-1);
	}
}

