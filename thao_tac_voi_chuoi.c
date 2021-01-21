#include <stdio.h>
#include <string.h>
void nhap_chuoi(char chuoi[],int *n);
int dem_so_tu(char s[],int n);
char kiem_tra_ky_tu(char a);
void dem_ky_tu_xuat_hien(char s[],int n);
void khu_khoang_trang(char s[],int n,char d[]);
void main()
{
	#define N 100
	 char chuoi[N];
	 char chuoilien[N];
	 int n,dem;
	 nhap_chuoi(chuoi,&n);
	 dem = dem_so_tu(chuoi,n);
	 printf("\nso tu trong chuoi la: %d",dem);
	 dem_ky_tu_xuat_hien(chuoi,n);
	 khu_khoang_trang(chuoi,n,chuoilien);
	 printf("\nchuoi sau khi khu khoang trang la : %s",chuoilien);
}
void nhap_chuoi(char chuoi[],int *n)
{
	printf("nhap chuoi : ");
	fgets(chuoi,100,stdin);
	*n = strlen(chuoi);
}
char kiem_tra_ky_tu(char a)
{
	if((a >= 65 && a<= 90)||(a >= 97 && a <= 122))
	return 1;
	else
	return 0;
}
int dem_so_tu(char chuoi[],int n)
{
	int i,k;
	int dem = 1;
	k = 0;
	 for (i = 0; i < n; i++)
	 {
	 	if(kiem_tra_ky_tu(chuoi[i]) == 1 && dem == 1)
	 	{
	 	k++;
	 	dem = 0;
	 	}
	 	if(kiem_tra_ky_tu(chuoi[i]) == 0 && dem == 0)
	 	dem = 1;
	}
	 return k;
}
void dem_ky_tu_xuat_hien(char s[],int n)
{
	char w;
	printf("\nnhap ky tu can kiem tra : ");
	scanf("%c",&w);
	int i;
	int k = 0;
	for(i = 0; i < n; i++)
	{
		if(s[i] == w)
		{
			k++;
		}
	}
	printf("\nky tu %c xuat hien %d lan.",w,k);
}
void khu_khoang_trang(char s[],int n,char d[])
{
	int i,k;
	k = 0;
	for(i = 0; i < n; i++)
	{
		if (kiem_tra_ky_tu(s[i]) == 1) 
		{
			d[i-k] = s[i];
		}
		else k++;
	}
	printf("\nso khang trang %d",k);
	d[n] = '\0'; 
	
}

