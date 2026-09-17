#include<stdio.h>
#include<math.h>

int gcd(int a,int b)
{
    while (b!=0) 
	{
        int temp = b;
        b=a%b;
        a=temp;
    }
    return a<0 ? -a : a;
}
int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}

struct rational {int m;int n;};

int numerator (struct rational z)
{
	return z.m;
}
int denominator (struct rational z)
{
	return z.n;
}

struct rational make_rational (int m,int n)
{
	struct rational z;
	z.m=m;
	z.n=n;
	return z;
}

struct rational add_rational (struct rational(z1),struct rational(z2))
{ 
	return make_rational(numerator(z1)*denominator(z2)+numerator(z2)*denominator(z1)
	,denominator(z1)*denominator(z2));
}
struct rational sub_rational (struct rational(z1),struct rational(z2))
{
	return make_rational(numerator(z1)*denominator(z2)-numerator(z2)*denominator(z1)
	,denominator(z1)*denominator(z2));
}
struct rational mul_rational (struct rational(z1),struct rational(z2))
{
	return make_rational(numerator(z1)*numerator(z2),denominator(z1)*denominator(z2));
}
struct rational div_rational (struct rational(z1),struct rational(z2))
{
	return make_rational(numerator(z1)/numerator(z2),denominator(z1)/denominator(z2));
}

void print_rational (struct rational z)
{
	if (gcd(z.m,z.n)==1)
	{
		printf("%d/%d\n",z.m,z.n);
	}
	else
	{
		printf("%d/%d\n",z.m/gcd(z.m,z.n),z.n/gcd(z.m,z.n));
	}
}

int main(void)
{
	struct rational a = make_rational(1, 8); /* a=1/8 */
	struct rational b = make_rational(-1, 8); /* b=-1/8 */
	print_rational(add_rational(a, b));
	print_rational(sub_rational(a, b));
	print_rational(mul_rational(a, b));
	print_rational(div_rational(a, b));

	return 0;
}