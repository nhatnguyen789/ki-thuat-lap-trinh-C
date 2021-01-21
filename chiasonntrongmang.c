#include<stdio.h>
int chisoNN(int mang[],int nptu);
int *controNN(int mang[],int nptu);
int *controNN2(int mang[],int nptu);
int *controNN1(int mang[],int nptu);
int *contross(int mang[],int nptu);
void main()
{
	int i,n,*ct;
	int daysn[]={2,5,1,6,7};
	n=sizeof(daysn)/sizeof(daysn[0]);
	i=chisoNN(daysn,n);
	ct=controNN(daysn,n);
	printf("\n so nho nhat %d ?? %d",daysn[i],*ct);
	printf("\n tai dia chi 0x%x ?? 0x%x",&daysn[i],ct);
	ct=controLN(daysn,n);
	printf("\n so lon nhat %d ?? %d ",daysn[i],*ct);
	printf("\n so lon nhat %d ?? %d ",daysn[i],ct);
	ct=controNN2(daysn,n);
	printf("\n so lon nhat %d ?? %d",daysn[i],*ct);
	printf("\n tai dia chi: 0x%x",&daysn[i],ct);
}
int *controNN(int src[],int n)
{
	int i=1,cs=0;
	while(i<n){
		if(src[i]<src[cs])cs=i;
		i++;
		}
		return &src[cs];
}
int chisoNN(int src[],int n)
{
    int i=1,cs=0;
    int ctr,cnn;
	while(++ctr-src<n){
	if(*ctr<*cnn)cs=i;
	i++;
	}
	return cs;
}	
int *controNN1(int src[],int n)
{
	int i=1,cs=0;
	while(i<n){
		if(src[i]<src(cs))cs=i;
		i++;
	}
	return cs;
}		
int *controNN2(int src[],int n)
{
	int i=0,cs=0;
	while(++i<n){
		if(src[i]<src(cs))cs=i;
		//i++;
		}
	return &src[cs];
}		
int *contross(int src[],int n,int gtss)
{
	int *ctr=src;
	for(;*ctr !=gtss;ctr++);
	if(ctr-src==n-1) return 0;
	return ctr;
}	
