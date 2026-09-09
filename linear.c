#include<stdio.h>

int get_min (int arr[],int len)
{
	if (len<=0)
	{
		printf("wrong!");
		return -1;
	}
	
	int min = arr[0];
	int i;

	for (i=1;i<len;i++)
	{
		if (arr[i]<min)
		{
			min = arr[i];
		}
	}
	return min;
}

int partition (int arr[],int start,int end)
{
	int pivot = arr[start];
	int i = start;
	int j = end;
	while (i<j)
	{
		while (i<j && arr[j]>=pivot)
		{
			j--;
		}
		if (i<j)
		{
			arr[i] = arr[j];
		}
		while (i<j && arr[i]<=pivot)
		{
			i++;
		}
		if (i<j)
		{
			arr[j] = arr[i];
		}
	}
	arr[i] = pivot;
	return i;
}

int quicksort_K (int arr[],int start,int end,int k)
{
	if (start==end)
	{
		return arr[start];
	}

	int mid = partition (arr,start,end);
	int n = mid-start+1;
	if (k==n)
	{
		return arr[mid];
	}
	else if (k<n)
	{
		return quicksort_K (arr,start,mid-1,k);
	}
	else //(k>n)
	{
		return quicksort_K (arr,mid+1,end,k-n);
	}
}

int get_Kth_min (int arr[],int len,int k)
{
	if (k<1 || k>len)
	{
		printf ("wrong k !");
	}
	return quicksort_K (arr,0,len-1,k);
}

int main()
{
	int arr[8] = {34,55,12,32,87,45,16,78};
	int len = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	int Kthmin = get_Kth_min (arr,len,k);
	printf("the %dth min number is: %d\n",k,Kthmin);
	return 0;
}