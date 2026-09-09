#include<stdio.h>
/*
int GCD(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	return GCD(b,a%b);
}
*/
int gcd(int a,int b)
{
    while (b!=0) 
	{
        int temp = b;
        b=a%b;
        a=temp;
    }
    return a<0 ? -a : a;
}

int main()
{
	printf("%d\n",GCD(48,18));
	return 0;
}