#include<stdio.h>
#include<stdarg.h>

int split_num (char buf[] , int num)
{
	int count = 0;
	do
	{
		buf[count] = num%10 + '0';
		num = num/10;
		count++;
	}while(num != 0);
	return count;
}

void split_decimals (char buf[] , double num)
{
	int n;
	if (num<0)
	{
		num = -num;
	}
	for (n = 0;n<=5;n++)
	{
		num = num*10;
		buf[n] = (int)num%10 + '0';
	}
}

void putchar_num (char buf[] , int num)
{
	if (num < 0)
	{
		num = -num;
	}
	int len = split_num(buf , num);

	for (int n = (len-1);n>=0;n--)
	{
		putchar(buf[n]);
	}
}
void myprintf (const char *fmt , ...)
{
	va_list ap;
	char c;

	va_start (ap , fmt);
	
	while (*fmt)
	{
		c = *fmt;
		if (c == '%')
		{
			fmt++;
			int ch = *fmt;
			switch (ch)
			{
				case 'd':
				{
				 	int num = va_arg (ap , int);
					if (num<0)
					{
						putchar ('-');
					}
					char buf[32];
					putchar_num (buf , num);
				 	break;
				}
				case 's':
				{
					char *string = va_arg (ap , char *);
					while (*string)
					{
						putchar(*string);
						string++;
					}
					break;
				}
				case 'f':
				{
					double num = va_arg (ap , double);
					int integer = (int)num;
					double decimal = num - integer;
					char buf1[32] , buf2[32];

					if (num<0)
					{
						putchar ('-');
					}
					//整数部分输出//
					putchar_num (buf1 , integer);
					////
					putchar ('.');
					//小数部分输出//
					split_decimals (buf2 , decimal);
					int n;
					for (n = 0;n<=5;n++)
					{
						putchar (buf2[n]);
					}
					break;
				}
				case '%':
				{
					putchar('%');
					break;
				}
				default:
				{
					break;
				}
			}
		}
		else
		{
			putchar (c);
		}
		fmt++;
	}
	va_end (ap);
}

int main ()
{
	myprintf ("%f",42.132);
	return 0;
}