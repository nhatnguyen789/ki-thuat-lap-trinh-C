#include<stdio.h>


void inputarray(int a[],int *n);
void outputarray(int a[],int n);
void khu_phan_tu(int a[],int n,int  d[],int *m);

void main()
{
	int i,n,m;
	int a[24];
	int b[24];
	inputarray(a,&n);
	outputarray(a,n);
	khu_phan_tu(a,n,b,&m);
	outputarray(b,m);

}

void inputarray(int a[],int *n)
{
	int i;
	printf("please input number of n=");
	scanf("%d",n);
	for(i=0;i<*n;i++){
		printf("\na[%d]=",i);
		scanf("%d",&a[i]);
		}
}
void outputarray(int a[],int n){
	int i,count;
	count=0;
	for(i=0;i<n;i++){
		printf("  a[%d] = %d\n",i,a[i]);
		count++;
		}
		printf("so phan tu trong mang la:%d",count);
}
void khu_phan_tu(int  a[],int n,int b[],int *m)
{
	int i,j,p;
	j= 0;
	printf("\nnhap vao phan tu can khu ");
	scanf("%d",&p);
	for(i = 0; i < n; i++)
	{
		if (a[i]!= p) 
		{
		 b[j]=a[i];
		 j=j+1;
		}
	}
	*m=j;
	
}

