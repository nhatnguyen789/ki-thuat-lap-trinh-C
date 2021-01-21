#include <stdio.h>
void main()

{
	float p,t,sl;
	printf("Nhap don gia san pham: ");
	scanf("%f",&p);
	printf("Nhap so luong san pham: ");
	scanf("%f",&sl);
	printf("_______________\n");
	printf("So tien thue la: %f\n",(0.1*sl*p));
	printf("Tong tien phai tra la: %f\n",((0.1*sl*p)+sl*p));
}
// cach 2 tien thue----------------
/*
#include<stdio.h>
void main()
{
	float p,sl,thue,tien;
	printf("input unit price of the product p=");
	scanf("%f",&p);
	printf("input the product number sl=");
	scanf("%f",&sl);
	thue=0.1*sl*p;
	printf("\nthe ouput tax is thue=%f",thue);
	tien=thue+(sl*p);
	printf("\ntotal money is tien=%f",tien);
}	
*/	
	
	
