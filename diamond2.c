#include<stdio.h>
int diamond(int i,char a)
{
	if(i%2==0)
	{
		printf("wrong!\n");
		return 0;
	}
	int n;int m;
	int mid=i/2+1;

	for(n=1;n<=mid;n++)
	{
		for(m=1;m<=mid-n;m++)
		{
			printf(" ");
		}
		for(m=1;m<=2*n-1;m++)
		{
			printf("%c",a);
		}
		printf("\n");
	}

	for(n=mid-1;n>=1;n--)
	{
		for(m=1;m<=mid-n;m++)
		{
			printf(" ");
		}
		for(m=1;m<=2*n-1;m++)
		{
			printf("%c",a);
		}
		printf("\n");
	}
	return 0;
}

int main(void)
{
	int i;char a;
	scanf("%d %c",&i,&a);
	diamond(i,a);
	return 0;
}