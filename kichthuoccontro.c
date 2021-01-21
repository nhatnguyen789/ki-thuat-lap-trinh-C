#include<stdio.h>
void main()
{
	int *x,y;
	float z[4],*t;
	y=5; x=&y;x++;
	
	printf("\n kich thuoc (con tro) x %d",sizeof(x));    //8
	printf("\n kich thuoc (dia chi ) &z(0) %d ",sizeof(&z[0]));  //8
	printf("\n kich thuoc (phan tu) z[0] %d ",sizeof(z[0]));   //4
	printf("\n kich thuoc (ten mang) z %d ",sizeof(z));      //16
	printf("\n gia tri (con tro) x-&y %d",x-&y);    //1
	printf("\n gia tri (con tro) x %p",x);          //1781319664
	printf("\n gia tri (dia chi) &y %d",&y);        //1781319660
	printf("\n gia tri (con tro) x+1 %d ",x+1);     //1781319668
	printf("\n gia tri (con tro) t %p ",t);         //1781319904   ----tuy chuong trinh muon xuat gi thi xuat-------
	printf("\n gia tri (ten mang)= %p",z);          //1781319632
	printf("\n gia tri (dia chi) &z[1] %p",&z[1]);  //1781319636
	printf("\n gia tri (dia chi) &z[2] %p",&z[2]);  //1781319640
}	
	
