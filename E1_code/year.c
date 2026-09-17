#include<stdio.h>
int is_leap_year(int year)
{
	if(year%4==0&&year%100!=0)
	{
		printf("is leap year!\n");
	}
	else if(year%400==0)
	{
		printf("is leap year\n");
	}
	else
	{
		printf("not leap year\n");
	}
	return 0;
}

int main(void)
{
	int a;
	scanf("%d",&a);
	is_leap_year(a);
	return 0;
}