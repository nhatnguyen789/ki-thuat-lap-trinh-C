#include<stdio.h>
void main()
{
	int n,i,j,l,k;
	printf("nhap n\n");
	scanf("%d",&n);
	printf("chon loai ma tran tam giac can xuat\n");
	printf("1. ma tran tam giac tren ben trai\n");
	printf("2. ma tran tam giac tren ben phai \n");
	printf("3. ma tran tam giac duoi ben trai\n");
	printf("4. ma tran tam giac duoi ben phai\n");
	scanf("%d",&l);
	for(i=0;i<n;i++)
	{
		if(l==1)
		{
			for(j=i;j<n;j++)
			{
				printf(" *");
				printf("\n");}
		}
		else if(l==2){
			for(j=0;i<n;j++){
				printf(" ");}
				for(k=0;k<n-1;k++){
					printf("* \n");
					}
					}
		else if(l==3){
		    for(j=n-i-1;j<n;j++){
			    printf("*");
				printf("\n");}
					}
		else if(l==4){
		    for(j=0;j<n-i;j++){
			    printf(" ");}
				for(k=0;k<i;k++){
				    printf("*");
					printf("\n");}
					}
	}	
}							
