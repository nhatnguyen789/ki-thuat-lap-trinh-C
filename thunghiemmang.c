#include<stdio.h>
void nhapmang1(int a[],int *n);
void nhapmang2(int a[],int *n);
void nhapmang3(int a[],int *n);
void nhapmang4(int *a,int *n);
void xuatmang(int a[],int n);

void main()
{
	int manga[50],n;
	//nhapmang1(manga,&n);
	//nhapmang2(manga,&n);
	//nhapmang3(manga,&n);
	nhapmang4(manga,&n);
	xuatmang(manga,n);
}
void nhapmang1(int a[],int *n)
{
	int i;
	printf("\nnhap so phan tu n=");
	scanf("%d",n);
	for(i=0;i<*n;i++)
	{
		printf("\nnhap a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void nhapmang2(int a[],int *n)
{
    int i;
	printf("\nnhap mang so phan tu n=");
	scanf("%d",n);
	for(i=0;i<*n;i++)
	{
	printf("\nnhap a[%d]=",i);
	scanf("%d",a+i);
	}
}
void nhapmang3(int a[],int *n)
{   int i; 
    printf("\nnhap so phan tu n=");
    scanf("%d",n);
    for(i=0;i<*n;i++){
    	printf("\nnhao a[%d]=",i);
    	scanf("%d",a++);
    	}
}
void nhapmang4(int *a,int *n)
{
    int i;
	printf("nhap so phan tu=");
	scanf("%d",n);
	for(i=0;i<*n;i++)
	{
	printf("\nnhap a[%d]=",i);
	scanf("%d",&a[i]);
	}
} 	
void xuatmang(int a[],int n)
{
    int i;
	for(i=0;i<n;i++){
	printf("a[%d]=%d\n",i,a[i]);
	}
}	    	
		
	

