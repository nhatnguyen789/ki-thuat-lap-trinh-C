#include<stdio.h>
#include<string.h>
char string1[20];
char string2[40]= "last_first_name" //declare and initialize
char string3[100];
char string4[100];

scanf("%s",string); // assum input:Nguyen Van A
=>string1 =="Nguyen"
//input string with scanf: ended by "space key"
fgel(string3,100,stdin); assum input:Nguyen Van A
=>string3 =="Nguyen Van A"
strcpy(string4,"Nguyen Van ANH B"); assign value into string 
=> string4=="Nguyen Van Anh B"
void main()
{
	int i,n,gtktra=7,*ct,nct;
	int daysn[]={2,5,1,6,7,9,20}
	n=sizeof(daysn)/sizeof(daysn[0]);
	disparray(daysn,n);
	while(ct=pointcmp(daysn,n,gtktra)){
		nct=n=(ct-daysn);
	}
}
int *pointcmp(int src[],int n,int gtss)
{
	int *ctr=src;
	for(;ctr != gtss;ctr++)
	if(ctr-src==n-1) return 0;
	return ctr;
}
int *delarryelement(int src[],int *n,int gtss)
{
	int *ctr,nct;
	while(ctr= pointcmp(src,*n,gtss)){
		nct=((*n)--)-(ctr-src);
		cpyarray(ctr,ctr+1,nct);
		}
}		
//viet ham strlen 	
		
	
	

int fputs(const char *ckt,file *namefile)

    
