#include<stdio.h>

int chisoNN(int mang[],int nptu);
int *controNN(int mang[],int nptu);
int chepmang(int *,int [],int );
void xuatmang(int [],int );
int *khuptumang(int [],int *,int);
void main()
{
	int i,n,*ct;
	int gtktra=5,nct;
	int daysn[]={2, 5, 1, 6, 7,9,20};
	n=sizeof(daysn)/sizeof(daysn[0]);
	xuatmang(daysn,n);
	i=chisoNN(daysn,n);
	ct=controNN(daysn,n);
	ct=chepmang(ct,ct+1,nct);n--;

	printf("\n so nho nhat %d:?? %d",daysn[i],*ct);
	printf("\n tai dia chi:0x%x ?? 0x%x ",&daysn[i],ct);
	khuptumang(daysn, &n, gtktra); 
}
int chisoNN(int src[], int n)
{
    int i=1;
	int cs=0;	
	while(i<n)
	{
		if(src[i]<src[cs])
		cs=i;
		i++;
	}
	return cs;
}		
int *controNN(int src[], int n) 
{ 
    int i = 1; 
	int cs = 0; 
    while (i<n){  
    if (src[i] < src[cs]) 
	cs = i; 
	i++; 
}  
return &src[cs]; 
}  
void xuatmang(int src[], int n)
{  
    int i=0; 
	printf("\ndaysn = {"); 
	while (i<n) 
	printf("%d,",src[i++]);  
	printf("nothing};\n");
} 
int *chepmang(int *dest,int src[],int n)
{
	int *a=dest;
	i=0;
	while(i++<n)
	*a++=*src++;
	return dest;
}	
int *khuptumang(int src[], int *n, int gtss) 
{  
    int *ctr, nct;
    while (ctr = contross(src,*n,gtss))
    {   
    nct = ((*n)--)-(ctr-src);  
    chepmang(ctr, ctr+1, nct); 
	} 
} 

