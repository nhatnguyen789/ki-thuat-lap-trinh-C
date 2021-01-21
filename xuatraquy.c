#include<stdio.h>

void main()
{
	int d,m,y;
	int q;
	printf("nhap vao ngay:\n");
	scanf("%d",&d);
	printf("nhap vao thang:\n");
	scanf("%d",&m);
	printf("nhap vao nam:\n");
	scanf("%d",&y);
	switch(m)
	{
		case 1:if(d>0&&d<=31){printf("quy 1\n");}
		       else{
		       	printf("ngay khong hop le\n");};break;
			   
		case 2:if(y%4==0&&y%100 !=0||y%400==0){
			 if(d>0&&d<=29){
				printf("quy 1 nam nhuan\n");}
				else{
					printf("ngay khong hop le\n");}break;}
				else{
				if(d>0&&d<=28){
					printf("quy 1 nam khong nhuan \n");}
					else{printf("ngay khong hop le\n");
					}
					};break;
		case 3:if(d>0&&d<=31){
			printf("quy 1 \n");}
			else{
				printf("ngay khong hop le\n");
			};break;
		case 4:if(d>0&&d<=30){
			printf("quy 2\n");}
			else{
				printf("ngay khong hop le\n");
			};break;
		case 5:if(d>0&&d<=31){
			printf("quy 2\n");}
			else{
				printf("ngay khong hop le\n");
			};break;
		case 6:if(d>0&&d<=30){
			printf("quy 2\n");}
			else{
				printf("ngay khong hop le\n");
			};break;
		case 7:if(d>0&&d<=31){
			printf("quy 3\n");}
			else{
				printf("ngay khong hop le\n");
			};break;
		case 8:if(d>0&&d<=31){
			printf("quy 3\n");}
			else{
				printf("ngay khong hop le\n");
			};break;
		case 9:if(d>0&&d<=30){
			printf("quy 3\n");}
			else{
				printf("ngay khong hop le\n");
			};break;
		case 10:if(d>0&&d<=31){
			printf("quy 4\n");}
			else{
				printf("ngay khong hop le\n");
			};break;
		case 11:if(d>0&&d<=30){
			printf("quy 4\n");}
			else{
				printf("ngay khong hop le\n");
			};break;
		case 12:if(d>0&&d<=31){
			printf("quy 4\n");}
			else{
				printf("ngay khong hop le\n");
			};break;
		default:
		       if(y<0||m<0||m>12||d<0||d>31){
		printf("khong hop le:\n");};break;
		}
}
			
