#include <stdio.h>

char *strcpy(char *dest,const char *src)
{
	char *ret = dest;
	while ((*dest++ = *src++))
		;
	printf("!!!!!\n");
	return ret;
}

int main()
{
	char a[10];
	strcpy(a,"hello");
	printf("%s\n",a);
	return 0;
}