#include<stdio.h>


int hgi1(int a,int b){
	if(a==b) return a;
	else
	if(a>b)
	return hgi1(a-b,b);
	else
	return hgi1(a,b-a);
}
int hgi2(int a,int b){
	if(a*b==0) return a+b;
	else
	if(a>b)
	return hgi2(a%b,b);
	else
	return hgi2(a,b%a);
}
int hgi3(int n) //goi y n>>10
{
	if(n!=0){
		printf("%d",n%10);
		hgi3(n/10);
		}
}
int hgi4(int manga[],int n){
	int gtr;
	if(n<=1)
	return manga[0];
	gtr=hgi4(manga,n-1);
	if(gtr<manga[n-1])
	gtr=manga[n-1];
	return gtr;
}	
int hgi5(int manga[],int n)
{ int gtr;
  if(n<=1)
  return manga[0];
  gtr=hg5(manga,n-1);
  if(manga[gtr]<manga[n-1])
  gtr=n-1;
  return gtr;
}
void hgi6(int a[],int n){
	if(n==1) return;
	int cs;
	if(cs=chisoNN(a,n))
	hoanvi(a+cs,a);
	hgi6(a+1,n-1);
}
void hgi7(int a[],int n)
{
	if(n==1) return;
	int cs;
	if(cs=chisoLN(a,n))
	hoanvi(a+cs,a+n+1);
	hgi7(a,n-1);
}
int chisoLN(int src[],int n)
{
int i=0;cs=0;
while(++i<=n){
if(src[i]>src[cs]) cs=i;
}
return cs;
void hoanvi(int *a,int *b){
int tam=*a;
*a=*b;
*b=tam;
}	
