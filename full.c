#include<stdio.h>

int a[]={1,2,3};
int len=sizeof(a)/sizeof(a[0])-1;

void swap (int *a,int *b)
{
	int m=*a;
	*a=*b;
	*b=m;
}

void permutation (int a[],int judge,int l)
{
	int i;
	if (judge==l+1)
	{
		for (i=0;i<=len;i++)
		{
			printf("%d",a[i]);
		}
		printf ("\n");
	}
	for (i=judge;i<=len;i++)
	{
		swap (&a[judge],&a[i]);
		
		permutation(a,judge+1,len);
		swap (&a[i],&a[judge]);
	}
}

void get_M (int M,int a[])
{
	int b[M],i;
	for (i=0;i<M;i++)
	{
		b[i]=a[i];
	}
	int lenth=sizeof(b)/sizeof(b[0])-1;
	permutation(b,0,lenth);
}

void combination (int a[],int judge,int M)
{
	int temp[10];
	int i;
	if (M==judge)
	{
		for(i=0;i<M;i++)
		{
			printf("%d",temp[i]);
		}
		printf("\n");
		return;
	}
	for (i=judge;i<len;i++)
	{
		temp[judge]=a[i];
		combination (a,judge+1,M);
	}
}

int main(void)
{
	/*permutation(a,0,len);*/
	combination(a,0,2);
	return 0;
}