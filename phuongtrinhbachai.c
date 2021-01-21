#include<stdio.h>
#include<math.h>

void main()
{
	float a,b,c,delta;
	printf("GIAI PHUONG TRINH BAC HAI ax^2+bx+c=0\n");
	printf("nhap he so a:\n");
	scanf("%f",&a);
	printf("nhap he so b:\n");
	scanf("%f",&b);
	printf("nhap he so c:\n");
	scanf("%f",&c);
	if(a==0)
	{
		printf("nghiem cua phuong trinh la:%f\n",-b/a);}
	else if(a==0&&b==0&&c==0){
		printf("phuong trinh vo ngiem\n");}
		else if(a==0&&b==0&&c!=0){
			printf("phuong trinh co vo so nghiem\n");}
	else{
		delta=b*b-4*a*c;
		if(delta<0)
		{
			printf("phuong trinh vo nghiem\n");}
			else if(delta==0){
				printf("phuong trinh co nghiem kep:%f",-c/a);}
				else if(delta>0){
					printf("phuong trinh co hai nghiem phan biet:\n");
					printf("nghiem 1 la:%f\n",(-b+sqrt(delta))/2*a);
					printf("nghiem 2 la:%f\n",(-b-sqrt(delta))/2*a);
					}
		}
}					
				
			
	
			
		
	
		
	
