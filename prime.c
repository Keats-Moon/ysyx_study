#include<stdio.h>
int is_prime(int n)
{
	int i=2;
	int judge=1;
	if(n==1)
	{
		return 0;
	}
	while(i<n)
	{
		if(n%i==0)
		{
			judge=0;
			i=n;
		}
		else
		{
			i++;
		}
	}
	return judge;
}

int main(void)
{
	int n=1;
	while(n<=100)
	{
		if(is_prime(n))
		{
			printf("%d\n",n);
		}
		n++;
	}
	return 0;
}