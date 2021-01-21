#include<stdio.h>

float a,b,tong,hieu,tich,thuong;
void main()
{
	printf("nhap vao so a: ");
	scanf("%f",&a);
	printf("nhap vao so b: ");
	scanf("%f",&b);
	while(b==0)
	{
		printf("nhap lai b:\n");
		scanf("%f",&b);
	}	
	tong=a+b;
	hieu=a-b;
	tich=a*b;
	thuong=a/b;
	printf("----------------\n");
    printf("a+b=%f\n a-b=%f\n a*b=%f\n a/b=%f\n",tong,hieu,tich,thuong);
}	

//cach 2---------------------------
/*#include<stdio.h>
float a,b,sum,sub,multi,div;
void main()
{
	printf("intput number a:");
	scanf("%f",&a);
	printf("\ninput number b:");
	scanf("%f",&b);
	printf("\nsum=%f",a+b);
	printf("\nsub=%f",a-b);
	printf("\nmulti=%f",a*b);
	while(b==0){
		printf("\ncontinue input b=");
		scanf("%f",&b);
		}
		printf("\ndiv=%f",a/b);
}		
*/	
