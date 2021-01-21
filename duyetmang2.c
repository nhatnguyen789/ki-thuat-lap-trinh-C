#include <stdio.h>
int chisoNN(int mang[], int nptu);//bien hinh thuc;
int *controNN(int src[], int n);
int *controLN(int src[], int n);
int *controNN2(int src[], int n);
int *controNNN(int src[],int n);
int *contross(int src[],int n,int gtss);
void xuatmang(int [],int );
int *chepmang(int *,int [],int);
int *khuptumang(int [],int *,int);

void main()
{
	int i, n,gtktra=7,nct,*ct,gtss;
	int daysn[]={2,5,1,6,7,9,20};
	n=sizeof(daysn)/sizeof(daysn[0]);
	i= chisoNN(daysn,n);
	ct=controNN(daysn,n);
	xuatmang(daysn,n);
	printf("\nSo nho nhat %d ?? %d",daysn[i],*ct);
	printf("\nTai dia chi: 0x%x",&daysn[i],ct);
	ct=controLN(daysn,n);
	printf("\nSo lon nhat %d ?? %d",daysn[i],*ct);
	printf("\nTai dia chi: 0x%x",&daysn[i],ct);
	ct=controNN2(daysn,n);
	printf("\nSo nho nhat %d ?? %d",daysn[i],*ct);
	printf("\nTai dia chi: 0x%x",&daysn[i],ct);
	ct=controNNN(daysn,n);
	printf("\n so nho nhat %d ?? %d",daysn[i],*ct);
	printf("\n tai dia chi:0x%x ?? 0x%x",&daysn[i],ct);
	ct=contross(daysn,n,gtss);
	printf("\n so lon nhat :%d ?? %d",daysn[i],*ct);
	printf("\n tai dia chi:0x%x",&daysn[i],ct);
	//ct=xuatmang(daysn,n);
	khuptumang(daysn,&n,gtktra);
	xuatmang(daysn,n);
	
		
	
}
int *controNN(int src[],int n){            //ham tra ve dia chi vi su dung *controNN
	int i=1,cs=0;
	while(i<n){
		if(src[i]<src[cs]) cs=i;
		i++;
	}
	return &src[cs];
}
int chisoNN(int src[],int n){      // ham tra ve gia tri kieu nguyen, khong tra ve dia chi, cach xu ly tuong tu voi ham *controNN
	int i=1,cs=0;
	while(i<n){
		if(src[i]<src[cs]) cs=i;
		i++;
	}
	return cs;
}
int *controLN(int src[], int n){    // ham tra ve dia chi co noi dung lon nhat, cach thuc hoat dong giong ham *controNN
	int i=1,cs=0;
	while(i<n){
		if(src[i]>src[cs]) cs=i;
		i++;
	}
	return &src[cs];
}

int *controNN2(int src[], int n){   // thay vi i++ o ngoai thi co the thay ++i( cong i len truoc roi so sanh voi n) vao ben trong vong lap while 
	int i=0,cs=0;
	while(++i<n){                    // dung i++ trong ham while luon, ++i = cong i len truoc roi so sanh voi N,voi i=0 co nghia la i=1 xong dem so sanh voi N
		if(src[i]<src[cs]) cs=i;     // chay toi khi nao i lon hon bang n se dung lai, chay toi khi dieu kien trong while se ket thuc vong lap 
		//i++;                       // ko dung i++
	}
	return &src[cs];
}

int *controNNN(int src[], int n){  
	int *cnn=src, *ctr=cnn;  // vi dang khai bao nen con tro bang luon noi dung va dia chi 
	while (++ctr-src<n){
		if(*ctr<*cnn)cnn=ctr;
	}
	return cnn;
}
int *contross(int src[],int n,int gtss){
	int *ctr=src;
	for(;*ctr!=gtss;ctr++){
		if(ctr-src==n-1)
		return 0;}
		return ctr;
	
}
void xuatmang(int b[],int n)
{
	int i;
	for(i=0;i<n;i++){
		printf("\noutput b[%d]=%d\n",i,b[i]);
	}
}
int *chepmang(int *dest,int src[],int n)
{
	int *dtr = dest, *str=src;
	while(str-src<n)
	*dtr++ =*str++;
	return dest;
}
int *khuptumang(int src[],int *n,int gtss )
{
	int *ctr,nct;
	while(ctr=contross(src,*n,gtss)){
		nct=--(*n)-(ctr-src);
		chepmang(ctr,ctr+1,nct);}
		return src;		
}		
	
