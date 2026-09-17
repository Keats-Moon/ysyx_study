#include<stdio.h>
int FIB(int n)
{
	if(n==0)
	{
		return 1;
	}
	if(n==1)
	{
		return 1;
	}
	return FIB(n-1)+FIB(n-2);

}

int main()
{
	printf("%d\n",FIB(6));
}