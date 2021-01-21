#include<stdio.h>
int *ctrmc(int [],int ,int [],int);
void main()
{
	int i,n,nc,*ctr,dayc[]={8,1,7};
	int daysn[]={3,4,7,8,1,7};
	n=sizeof(daysn)/sizeof(daysn[0]);
	nc=sizeof(dayc)/sizeof(dayc[0]);
	for(i=0;i<n;i++)
		printf("\n vi tri [%d]:%p",i,daysn+i);
	if(ctr=ctrmc(daysn,n,dayc,nc)){
		printf("\nvoi noi dung la %d",*ctr);
	}
}	
int *ctrmc(int src[],int n,int mss[],int ns)
{
	int i=0, *a,*b,*c;
	if(mss==NULL)return NULL;
	//n-(a-src)>=ns;
	for(a=src;a-src<=n-ns;a++){
	if(*a==*mss){
		b=mss;c=a;
		while(*b++==*c++);
		if(b-mss>ns)
		return a;
		}
		}
		return NULL;
}
/* mo ta:
input day so nguyen src co n ptu day so nguyen mss co ns ptu chuc nang. tim va tra ve dia chi ma mss xuat hien lan dau trong src, neu khong tim thay tra ve NULL
*/		
	
	
