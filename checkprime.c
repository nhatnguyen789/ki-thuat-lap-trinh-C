#include<stdio.h>
#include<math.h>
int i;
char checkprime(int x)               
{
	if(x<2)
	{
		return 0;}
	else{
		for(i=2;i<x;i++){      
		if(x%i==0){                
			return 0;
			}
		}	
		return 1;	
		}
}
void main()
{
    int i,n,count;
    count=0;
	printf("nhap n:\n");    
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	if(checkprime(i))	
	{
	    printf("%d  \t",i);
	    count++;
	}
	}
		printf("\nCo tong cong %d so nguyen to\n",count);			
}				
			
		
