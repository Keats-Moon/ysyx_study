#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MB (1024 * 1024)

char *test;
int i = 0;

int main()
{
	do
	{
		test = malloc(1 * MB);
		if (test != NULL)
		{
			memset(test,0,1 * MB);
			i++;
			if (i % 100 == 0)
			{
				printf("%d MB\n",i);
				fflush(stdout);
			}
		}
	}while(test != NULL);
	printf("%d\n",i);
	return 0;
}
