#include<stdio.h>
#include<math.h>

void inputarray(int a[],int *n);
void inputarray1(int b[],int *m);
void outputarray(int a[],int n);
int checkprime(int n);
int print_prime(int a[],int n,int b[],int *m);
void changeplace(int a[],int *t);
void swap(int *x,int *y);
void asc_sort(int a[],int n);
void desc_sort(int a[],int n);
void arraysort(int a[],int n);


void main()
{
	int i,n,m,x,y,t;
	int a[100];
	int b[100];
 	inputarray(a,&n);
	outputarray(a,n);
	changeplace(a,&t);
	print_prime(a,n,b,&m);
	outputarray(b,m);
	//changeplace(a,n);
	arraysort(a,n);
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
	int i;
	for(i=0;i<n;i++){
		printf("  a[%d] = %d\n",i,a[i]);
		}
}
int checkprime(int n)
{
	int i;
    if(n<2){
    	return 0;}
    	for(i=2;i<n;i++){
    		if(n%i==0){
    			return 0;
    			}
    			return 1;}
}  
int print_prime(int a[],int n,int b[],int *m) 
{
    int i,k=0;
	for(i=0;i<n;i++){
	if(checkprime(a[i])){
	b[k]=a[i];
	k++;
	}
	}
	*m=k;
       
}	 			
void changeplace(int a[],int *t)
{
	int i,j,n;
	printf("nhap phan tu can chuyen doi vi tri i=");scanf("%d",&i);
    printf("\nnhap phan tu can chuyen doi vi tri j=");scanf("%d",&j);
	*t=a[i];
	a[i]=a[j];
	a[j]=*t;
	for(i=0;i<n;i++){
	printf("a[%d]=%d\n",i,a[i]);}
}
void swap(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}
void asc_sort(int a[],int n)
{
    int i,j;
	for(i=0;i<n-1;i++){
	for(j=i+1;j<n;j++){
	if(a[i]>a[j]){
	    swap(&a[i],&a[j]);}
	}
	}		
}
void desc_sort(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++){               //di chuyen ranh gioi cua mang da sap xep va chua sap xep
	for(j=i+1;j<n;j++){               //tim phan tu nho nhat trong mang chua sap xep 
	if(a[i]<a[j]){
	    swap(&a[i],&a[j]);}
		}
		}
}
void arraysort(int a[],int n)
{
    int i,choose;
	printf("\nchon cach sap xep mang:\n");
	printf("1.increase \n");
	printf("2.decrease \n");
	scanf("%d",&choose);
	if(choose==1){
	asc_sort(a,n);
	}
	if(choose==2){
	desc_sort(a,n);}
	for(i=0;i<n;i++){
		printf("a[%d]=%d \n",i,a[i]);
		}
}	
			
			

	
	          	
