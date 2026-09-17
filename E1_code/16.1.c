#include<stdio.h>

int countbit(unsigned int x)
{
	unsigned int a , b;
	int countbit , i;
	a = 0x00000001;
	for (i = 0;i < 32;i++)
	{
		b = ((a<<i)&x);
		if ((b>>i)==1)
		{
			countbit++;
		}
	}
	return countbit;
}

//Brian Kernighan算法//
int count_ones(unsigned int x)
{
    int count = 0;
    while (x) {
        x &= (x - 1);
        count++;
    }
    return count;
}

unsigned int multiply(unsigned int x, unsigned int y)
{
	int i;
	unsigned int multiply;
	for (i = 0;i < 32;i++)
	{
		if (y&(1u<<i))
		{
			multiply = multiply + (x<<i);
		}
	}
	return multiply;
}

int main()
{
	unsigned int x = 0x0000450e;
	unsigned int y = 0x00003200;
	printf("%d\n",countbit(x));
	printf("%x\n",multiply(x,y));
	return 0;
}