#include<stdio.h>
void main()
{
	int arr[8] = {2,3,7,5,1,9,8,4};
	int *a,*b;
	//for(i=0;i<10;i++){
	//	arr[i] = i;
	//	printf("input arr[%d]= %d\n", i, arr[i]);
		//scanf("%d",&arr[i]);
	//}
	a=&arr[0];
	b=&arr[1];
	//a=arr;
	//b=&arr[2];
	printf("a=%d \n",a);
	printf("b=%d \n",*b);
	printf("*b++=%d \n",*b++);               //gan gia tri truoc roi sau dong printf se lay gia tri cua vi tri tiep theo 
	printf("%d\n",*b);                       //in ra noi dung
	printf("*++a=%d\n",*++a);               //tang dia chi cua a len mot don vi, roi print ra gia tri cua dia chi do
	printf("++*a=%d\n",++*a);               // tang noi dung cua a len mot don vi 
	printf("*a=%d\n", *a);               //   in ra gia tri cua a 
	printf("*b=%d\n", *b);              // in ra gia tri cua b
	printf("*b++=*a++=%d\n",*b++=*a++); //dong vo nghia,chi coppy noi dung a qua b,roi sau do cong noi dung cua b len 1 gia tri sau dong printf hien tai
	printf("*a=%d\n", *a);              // sau dong printf tren, van lay gia tri cua a khong cong len 1
	printf("*b=%d\n", *b);              // sau dong in *b++=*a++ tang noi dung cua b len
	printf("*(a)++=%d\n",*(a)++);       // in ra noi dung a ra truoc, roi cong gia tri a len 1 don vi
	printf("%d",*a);                    // in ra noi dung truoc, roi sau dong printf se tang noi dung len 
	printf("\n(*a)++=%d\n",(*a)++);
	printf("\n%d",*a);
	//printf("%d",&arrb[0]);

}		
