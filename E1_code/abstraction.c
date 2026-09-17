#include<stdio.h>
#include<math.h>
struct complex_struct {double x,y;};
double real_part (struct complex_struct z)
{
	return z.x;
}
double img_part (struct complex_struct z)
{
	return z.y;
}
double magnitude_part (struct complex_struct z)
{
	return sqrt(z.x * z.x + z.y * z.y);
}
double angle (struct complex_struct z)
{
	return atan2(z.x , z.y);
}

struct complex_struct from_real_img (double x,double y)
{
	struct complex_struct z;
	z.x=x;
	z.y=y;
	return z;
}
struct complex_struct from_mag_ang (double r,double A)
{
	struct complex_struct z;
	z.x=r*cos(A);
	z.y=r*sin(A);
	return z;
}

struct complex_struct add_complex (struct complex_struct z1,struct complex_struct z2)
{
	return from_real_img(real_part(z1)+real_part(z2),img_part(z1)+img_part(z2));
}
struct complex_struct sub_complex(struct complex_struct z1,struct complex_struct z2)
{
	return from_real_img(real_part(z1)-real_part(z2),img_part(z1)-img_part(z2));
}
struct complex_struct mul_complex(struct complex_struct z1,struct complex_struct z2)
{
	return from_mag_ang(magnitude(z1)*magnitude(z2),angle(z1)+angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1,struct complex_struct z2)
{
	return from_mag_ang(magnitude(z1)/magnitude(z2),angle(z1)-angle(z2));
}


int main (void)
{
	struct complex_struct z1={1,-3};
	if (z1.x==0)
	{
		printf("%.1f",img_part(z1));
	}
	else if (z1.y==0)
	{
		printf("%1f",real_part(z1));
	}
	else
	{
	printf("%.1f%.1f",real_part(z1),img_part(z1));
	}
	return 0;

}