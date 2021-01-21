#include<stdio.h>

void main()
{
	float T,L,H,DTB;
	printf("nhap diem mon toan:\n");
	scanf("%f",&T);
	printf("nhap diem mon ly:\n");
	scanf("%f",&L);
	printf("nhap diem mon hoa:\n");
	scanf("%f",&H);
	printf("-------------------------\n");
	
	DTB=(T+L*2+H)/4;
	printf("Diem trung binh la: %f",DTB);
}	
	//cach 2 diem trung binh --------------------
/*
	#include<stdio.h>
void main()
{
	float T,L,H,DTB;
	printf("input math scores T=");
	scanf("%f",&T);
	printf("input physic scores L=");
	scanf("%f",&L);
	printf("input chemistry scores H=");
	scanf("%f",&H);
	DTB=(T+L*2+H)/4;
	printf("ouput average DTB=%f",DTB);
}	
*/
