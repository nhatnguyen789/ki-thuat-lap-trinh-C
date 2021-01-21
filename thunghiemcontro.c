#include<stdio.h>
void main()
{
	int arrb[10],i;
	for(i=0;i<10;i++){
		printf("input arr[%d]=",i);
		scanf("%d",&arrb[i]);}
		int *ctrb,*ptrb;
		ctrb=arrb;
		ptrb=&arrb[2];
		printf("ctrb=%d \n",ctrb);
		printf("ptrb=%d \n",*ptrb);          
		printf("*ctrb++=%d \n",*ptrb++);     //gan gia tri truoc roi sau dong printf se tang len mot gia tri 
		printf("%d \n",*ptrb);                  // in ra gia tri cua ptrb
		printf("*++ctrb=%d\n",*++ctrb);      // tang dia chi cua a len mot don vi, roi print ra 
		printf("++*ctrb=%d\n",++*ctrb);       // tang noi dung cua a len mot don vi 
		printf("*ptrb++=*ctrb++=%d\n",*ptrb++=*ctrb++); //dong vo nghia,chi coppy noi dung a qua b
		printf("*(ctrb)++=%d\n",*(ctrb)++);   // in ra noi dung a ra truoc, roi tang dia chi len 1 don vi
		printf("%d\n",*ctrb);
		printf("(*ctrb)++=%d\n",(*ctrb)++);    // in ra noi dung truoc, roi tang noi dung len 
		printf("%d\n",*ctrb);
		printf("%d",&arrb[0]);
}		
