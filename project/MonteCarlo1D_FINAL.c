#include <stdio.h>    //cung cap cot loi kha nang nhap trong C
#include <math.h>  // cho viec tinh cac ham so thong dung
#include <time.h> //de chuyen doi giua cac ding dang voi nhau ve thi gio va ngay thang 
#include <stdlib.h> //dung de xuc tien nhieu phep toan, bao gom su chuyen doi, cac so gia ngau nhien,cap phat vung nho, kiem soat qua trinh, moi truong, tin hieu,tim kiem va xep thu tu
#define tiny 1e-16
#define L 2


double gtham(double x)
{
	int a=1/(10*10*10*10*10);
	
	//TEST
   //return x*x+3;			//2.0
	return 1/(x*x+2*x+2);			//2.0
//	return 1/(cos(x)+sin(x)+1);					//2.0

//	return 1/((x-0.5)*(x-0.5)+a*a) +1/((y-0.75)*(y-0.75)+a*a);
//	return 1/((x-0.5)*(x-0.5)+tiny);			//2.0
//	return 1/((x-0.75)*(x-0.75)+tiny) + 1/((x-0.5)*(x-0.5)+ tiny);			//2.0		10.0	
	

}

void xuatmang1d(double mang1[], double mang2[], int n)
{
    int i;
    for (i = 0;i <= n;i++)
    {
        printf("\n[%d]\t%lf\t%lf",i,mang1[i],mang2[i]);
    }
}

void xuatmang(double mang[], int n)
{
    int i;
    for (i = 0;i <= n;i++)
    {
        printf("\n[%d] = %lf",i,mang[i]);
    }
}

void hamchiadoan(double mang[], double a , double b, int n) //mang[] la mang can chia; a = mang[0], b = mang[n] la hai dau can cua mang; n la so doan can chia
{
    int i;
    for (i = 0;i <= n;i++)
    {
    	mang[i] = a + ((b-a)/n)*i;
	}
}

double hamngaunhien(double a, double b)
{
    return a + (b - a)*rand()/RAND_MAX;
}

double tong(double mang[],int a,int b) //tinh tong tu phan tu a den phan tu b cua mang 
{
    double s = 0;
    int k;
    for (k = a;k <= b;k++)
    {
        s += sqrt((mang[k])*(mang[k]));
    }
    return s;
}


void hamchialaidoan(double x[], double m[],int N,int A,int K)
{
	int i,j;
	double tam[K]; //khai bao mang tam
	int mm = 0; //khai bao trong so tam
	
	for (i = 0;i < N;i++)
	{
		for (j = 0;j < (int)m[i];j++)
		{
			tam[mm+j] = x[i]+ j*((x[i+1]-x[i])/m[i]);
		}
		mm += (int)m[i];
//		printf("\nmm = %d",mm);
	}
	for (i = 1;i < N;i++)
	{
		x[i] = tam[A*i];
	}
}

void hamxulytrongso(double m[],double tongm,int n,int K)
{
	int i,j; 
	double Kthieu;
	double phantram[n];
	//lam tron trong so
/*	printf("\nmang m chua xu ly la:");
	xuatmang(m,n);
	printf("\nTong m chua xu ly la %lf",tong(m,0,n));    */
	for(i = 0;i <= n;i++)
	{
		m[i] = floor(m[i]);
	}
	tongm = tong(m,0,n);
	Kthieu = (double)K-tongm;
	for(i = 0;i <= n;i++)
	{
		phantram[i] = m[i]/tongm;
		m[i] += floor(phantram[i]*Kthieu);
	}
	
/*	printf("\nmang m da xu ly lan 1 la:");
	xuatmang(m,n);
	printf("\nTong m chua xu ly lan 1 la %lf",tong(m,0,n));     */
	
	Kthieu = (double)K - tong(m,0,n);
	i = 0;
	while (Kthieu > 0)
	{
		m[i] += 1;
		Kthieu--;
		i++;
	}
/*	printf("\nmang m da xu ly lan 2 la:");
	xuatmang(m,n);
	printf("\nTong m da xu ly lan 2 la %lf",tong(m,0,n));      */
}
/*
int sosanhtrongso(double m[], int j)
{
	int i, dem = 0;
	for(i = 1;i <= j;i++)
	{
		if (sqrt((m[i] - m[i-1])*(m[i] - m[i-1])) <= 2.0)
		{
			dem++;
		}
		else
		{
			break;
		}
	}
	if (dem != j)
	{
		return 0;
	}
	return 1;
}
*/
void main()
{
//	int L;
//	scanf("%d",&L);
	//khai bao de bai
	double a = 0; //khai bao can duoi a
	double b = 1; //khai bao can tren b
//	printf("Nhap can duoi a va can tren b:\n");
//	scanf("%lf",&a);
//	scanf("%lf",&b);

	
	//khai bao cac constant
	int M = 100000; //diem
    int N = 1000; //doan
    double K = 10000;
    
    //khai bao bien chay
    int i, j, k, h,kiemtra = 0;
    
    //khai bao cac mang
    double x[N]; //khai bao mang x 
    double alpha[M-1]; //khai bao mang alpha de chua cac diem gieo ngau nhien
    double f[M-1]; //khai bao mang f chua gia tri f tai cac diem gieo ngau nhien
    double tongf[N-1]; //khai bao mang tongf de chua gia tri tong cua cac f tren tung doan
    double m[N-1]; //khai bao mang trong so
    double tongfdelta[N-1]; //khai bao mang tongf nhan delta x
    
    double xmtongfdelta; //khai bao tong tat ca tongf nhan delta x tren tung doan
    double tongm; //khai bao tong cac trong so

    
    int A = K/N;

    
    //BUOC 1: CHIA N DOAN
    hamchiadoan(x,a,b,N);
    printf("mang x lan chia dau tien");
    //xuatmang(x,N);
  
  
	for(h = 0;h <= L;h++)    
//   	while (kiemtra < N-1)
   {
	//BUOC 2: RANDOM M/N DIEM NGAU NHIEN VAO TUNG DOAN LON, TINH f TAI TUNG DIEM DO, TINH TONG f CUA TUNG DOAN
//  printf("\nMang x");
//	xuatmang(x,N);
	for (i = 0;i <= N-1;i++)
        {
            for(j = (M/N)*i;j <= (M/N)*i+(M/N)-1; j++)
                {
                    alpha[j] = hamngaunhien(x[i],x[i+1]);
                    f[j] = sqrt((gtham(alpha[j]))*(gtham(alpha[j])));
                }
            tongfdelta[i] = tong(f,i*(M/N),i*(M/N)+M/N-1)*(x[i+1] - x[i]);
        }
	printf("\nMang alpha va mang f");
	xuatmang1d(alpha,f,M-1);
	printf("\nMang tongf");
//	xuatmang(tongf,N-1);

//	kiemtra = 0;
	//BUOC 3: TINH TRONG SO
	xmtongfdelta = tong(tongfdelta,0,N-1); //=> xmtongfdelta
//	printf("\nxmtongfdelta = %lf",xmtongfdelta);
//	printf("\nMang trong so khi chua xu ly la: ");
	for (i = 0;i <= N-1;i++)
	{
		m[i] = K*(tongfdelta[i]/xmtongfdelta);
//		printf("\nm[%d] = %lf",i,m[i]);
//		kiemtra += sosanhtrongso(m,i);
	}
//	printf("\ntong cac tongf nhan delta la ");
//	printf("%lf",xmtongfdelta);
//	printf("\nMang tongfdelta la: ");
//	xuatmang(tongfdelta,N-1);
//	printf("\nMang trong so khi chua xu ly la: ");
//	xuatmang(m,N-1);
	
	hamxulytrongso(m,tongm,N-1,K);
//	printf("\nmang m lan thu %d",h+1);
//	xuatmang(m,N-1);
//	printf("\ntongm = %lf",tong(m,0,N-1));
	
	//BUOC 4:CHIA LAI DOAN
//	printf("\nA = %d",A);
//	if(kiemtra < N-1)
//	{
	hamchialaidoan(x,m,N,A,K);	
//	}
//	printf("\nMang x sau khi rebin lan thu %d",h+1);
//	xuatmang(x,N);
	}    //vong lap ket thuc tai day
	  
	for (i = 0;i <= N-1;i++)
	{
            for(j = (M/N)*i;j <= (M/N)*i+(M/N)-1; j++)
                {
                    alpha[j] = hamngaunhien(x[i],x[i+1]);
                    f[j] = sqrt((gtham(alpha[j]))*(gtham(alpha[j])));
                }
            tongfdelta[i] = tong(f,i*(M/N),i*(M/N)+M/N-1)*(x[i+1]-x[i]);
    }
	xmtongfdelta = tong(tongfdelta,0,N-1); //=> xmtongfdelta
	
	double I;
	I = xmtongfdelta*((double)N/(double)M);
	printf("\nket qua la I = %lf",I);                             
}
