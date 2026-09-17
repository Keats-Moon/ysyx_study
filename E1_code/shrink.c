#include<stdio.h>
#include<string.h>

char *shrink_space(char *dest, const char *src, size_t n)
{
	int i;
	char *result = dest;
	for (i = 0;i<n;i++)
	{
		if (src[i]==' '||src[i]=='\n'||src[i]=='\t'||src[i]=='\r')
		{
			continue;
		}
			*dest++ = src[i];
	}
	*dest = '\0';
	return result;
}

int main()
{
	char temp[100];
	char test[] = "Hell o  \n, wor\tl d";
	int len = strlen(test);
	printf("%s\n",shrink_space (temp,test,len));
	return 0;
}