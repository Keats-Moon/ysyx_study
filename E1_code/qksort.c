#include<stdio.h>

int a[8] = {5,2,4,7,1,3,9,6,};

int partition (int start,int end)
{
	int pivot = a[start]
	int i = start;
    int j = end;
	while (i<j)
	{
		while (i<j && a[j]>=pivot)
		{
			j--;
		}
		if(i<j)
		{
			a[i]=a[j];
		}
		while (i<j && a[i]<=pivot)
		{
			i++;
		}
		if(i<j)
		{
			a[j]=a[i];
		}
	}
	a[i]=pivot;
	return i;
}

void quicksort(int start, int end)
{
	int mid;
	if (end > start) 
	{
		mid = partition(start, end);
		quicksort(start, mid-1);
		quicksort(mid+1, end);
	}
}