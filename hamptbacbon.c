#include<stdio.h>
#include<math.h>
void ptbacnhat(float b,float c,float *x1);
void ptbachai(float a,float b,float c,float *x1,float *x2);
void ptbacbon(float a,float b,float c,float *y1,float *y2);

void main()
{
	float a,b,c,x1,x2,y1,y2;
	printf("giai phuong trinh bac bon:\n");
	printf("nhap he so a:\n");
	scanf("%f",&a);
	printf("nhap he so b:\n");
	scanf("%f",&b);
	printf("nhap he so c:\n");
	scanf("%f",&c);
	ptbacnhat(b,c,&x1);
	//ptbachai(a,b,c,&x1,&x2);
	//ptbacbon(a,b,c,&y1,&y2);
	
}	
void ptbacnhat(float b,float c,float *x)
{
	if(b==0)
	{
		if(c==0)
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
			printf("phuong trinh co nghiem la x=%f\n",-c/b);
	}
}
void ptbachai(float a,float b,float c,float *x1,float *x2)
{
	float delta;
	if(a==0)
	{
		ptbacnhat(b,c,x1);}
	else{
		delta=b*b-4*a*c;
		if(delta<0)
		{
			printf("phuong trinh vo nghiem\n");}
			else if(delta==0){
				printf("phuong trinh co nghiem kep:%f", -c/a);}
*x1 = -c/a;
*x2 = *x1;
				if(delta>0){
					printf("phuong trinh co hai nghiem phan biet:\n");
					printf("nghiem 1 la:%f\n",(-b+sqrt(delta))/(2*a));
					printf("nghiem 2 la:%f\n",(-b-sqrt(delta))/(2*a));
*x1 = ((-b+sqrt(delta))/(2*a));
*x2 = ((-b-sqrt(delta))/(2*a));
					}
		}
}
void ptbacbon(float a,float b,float c,float *y1,float *y2)   	
{
    if(a==0){  
    	ptbacnhat(b,c,y1);}
    	else{
    		ptbachai(a,b,c,y1,y2);
    		if(*y1==*y2){
    			if(*y1>=0){
    				printf("\nphuong trinh co hai nghiem:x=+/-%f",sqrt(*y1));}
    				else{
    					printf("\nphuong trinh vo nghiem\n");
					}
					}
					if(*y1!=*y2){
						if(*y1>=0&&*y2>=0){
							printf("\nphuong trinh co 4 nghiem:x=+/-%f x=+/-%f",sqrt(*y1),sqrt(*y2));}
							else if(*y1>=0&&*y2<=0){
								printf("\nphuong trinh co hai nghiem:x=+/-%f",sqrt(*y1));}
								else if(*y1<=0&&*y2>=0){
									printf("\nphuong trinh co hai nghiem:x=+/-",sqrt(*y2));}
									else{
										printf("\nphuong trinh vo nghiem");
									}
								}
								}
}
