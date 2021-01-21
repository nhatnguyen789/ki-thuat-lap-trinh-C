#include<stdio.h>
void main()
{
	float a,b,x;
	printf("GIAI PHUONG TRINH BAC NHAT DANG ax+b=0:\n");
	printf("nhap he so a=");
	scanf("%f",&a);
	printf("nhap he so b=");
	scanf("%f",&b);
	if(a==0)
	{
		if(b==0)
		{
			printf("phuong trinh co vo so nghiem\n");
		}
		else
		{
			printf("phuong trinh vo nghiem\n");
		}
	}
	else
	{
		printf("phuong trinh co nghiem la:%f\n",-b/a);
	}
}		
			
			
