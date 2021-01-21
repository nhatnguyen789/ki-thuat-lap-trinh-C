#include<stdio.h>
void main()
{
	float r,c,s;
	printf("nhap ban kinh duong tron:\n");
	scanf("%f",&r);
	printf("----------------------\n");
	printf("chu vi hinh tron la: %f \n",2*3.14*r);
	printf("dien tich hinh tron la: %f \n",3.14*r*r);
}	

//cach 2 chu vi, dien tich hinh tron -------------- 
/*
#include<stdio.h>
void main()
{
	float c,s,r;
	printf("input radius r=");
	scanf("%f",&r);
	c=2*3.14*r;
	printf("\nthe circumference of the circle is c=%f",c);
	s=3.14*r*r;
	printf("\nthe area of the circle is s=%f",s);
}	
*/
