#include<stdio.h>
void main()
{
	float  a,b;
	printf("nhap vao so a:\n");
	scanf("%f",&a);
	printf("nhap vao so b:\n");
	scanf("%f",&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("a moi: %f\n",a);
    printf("b moi: %f\n",b);
}  
