#include<stdio.h>

int diamond(int i,char a)
{
	if(i%2==0)
	{
		printf("wrong!\n");
		return 0;
	}
	int n;int m=1;
	int mid=i/2+1;
	for(n=1;n<=i;n++)
	{
		if(m<=mid-n+1||(m>=mid+n-1&&m<=i))
		{
			printf(" ");
			m++;
		}
		else if(m>=mid-n+1&&m<=mid+n-1)
		{
			printf("%c",a);
			m++;
		}
		printf("\n");
	}
	return 0;
}

int main()
{
	int i;char a;
	scanf("%d %c",&i,&a);
	diamond(i,a);
	return 0;
}