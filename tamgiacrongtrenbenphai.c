#include<stdio.h>
void main()
{
	int i,j,n;
	printf("nhap n:\n");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if(i==0||j==n-1||j==i)
				printf("* ");
			else
				printf("  ");
		}	
		printf("\n");
	}
}			
