#include<stdio.h>
#include<math.h>

float ptbacnhat(float a,float b,float *x)
{
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
			printf("phuong trinh co nghiem la x=%f\n",-b/a);
	}
}
void main()
{
	float a,b,x;
	printf("nhap he so a:");
	scanf("%f",&a);
	printf("nhap he so b:");
	scanf("%f",&b);
	ptbacnhat(a,b,&x);
	
	

}	

			float ptbacbon(float a,float b,float c,float *y1,float *y2)   	
{
    float x,y,x1,x2;
	y=x*x;
    printf("phuong trinh tro thanh bac hai:a*y^2+b*y+c=0\n");
    if(a==0){
    	ptbacnhat(b,c,y1);}
    	else{
    		ptbachai(a,b,c,&y1,&y2);
			if(y1>0){
				printf("x12=+/-%f",sqrt(y1));
				else if(y2>0){
					printf("x12=+/-%f",sqrt(y2));
	

