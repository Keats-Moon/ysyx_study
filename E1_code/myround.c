#include<stdio.h>
#include<math.h>
double myround(double x)
{
	if(x>=0)
	{
		printf("%.0f",ceil(x));
	}
	else
	{
		printf("%.0f",floor(x));
	}
	return 0;
}

int main(void)
{
	double a;
	scanf("%lf",&a);
	myround(a);
	return 0;
}