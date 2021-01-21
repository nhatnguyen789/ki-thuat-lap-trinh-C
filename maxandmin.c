#include<stdio.h>
void main()
{
	int a,b;
	int max,min;
	printf("nhap a=\n");
	scanf("%d",&a);
	printf("nhap b=\n");
	scanf("%d",&b);
	printf("-------*************--------\n");
	if(b>a)
	{
		max=b;
		min=a;
	}
	else
	{
		max=a;	min=b;
	}	
	printf("max=%d\n",max);
	printf("min=%d\n",min);
	getch();
}		
