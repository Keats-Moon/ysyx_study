#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100

int a[N];
void get_random(int upper_bound)
{
	int i;
	srand (time(NULL));
	for (i=0;i<N;i++)
	{
		a[i]=rand() % upper_bound;
	}
}
int get_max(int b[],int size)
{
	int i;
	int max=b[0];
	for(i=1;i<size;i++)
	{
		if(max<b[i])
		{
			max=b[i];
		}
	}
	return max;
}
void out_histogram(int b[],int size)
{
	int i;
	int temp=get_max(b,size);
	while(temp>0)
	{
		for (i=0;i<size;i++)
		{
			if (b[i]>0)
			{
				printf("*   ");
			}
			else
			{
				printf("    ");
			}
		}

		printf("\n");
		temp--;
		for (i=0;i<size;i++)
		{
			b[i]--;
		}
	}
}

int main(void)
{
	int i;
	int b[10]={0};
	get_random(10);
	for (i=0;i<N;i++)
	{
		b[a[i]]++;
	}
	out_histogram(b,10);
}