#include<stdio.h>
#include<string.h>

//count word
void main()
{
	char string1[10];
	char string2[20];
	char string3[60];
	char string4[80];
	int i,q;
	int k=1;
	scanf("%fs",string1);
	fgets(string1,20,stdin);
	q=strlen(string1);
	scanf("%s",string1);
	scanf("%s",string2);
	scanf("%s",string3);
	scanf("%s",string4);
	
	for(i=0;i<q;i++){
		if(string1[i]==' '){
			k+=1;
		}
	}
	printf("%d",k);
}			
