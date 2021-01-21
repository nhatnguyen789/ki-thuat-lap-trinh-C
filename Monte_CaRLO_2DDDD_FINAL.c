#include <stdio.h>
#include <math.h>  // cho viec tinh cac ham so thong dung
#include <time.h>  //de chuyen doi giua cac ding dang voi nhau ve thi gio va ngay thang 
#include <stdlib.h> //dung de xuc tien nhieu phep toan, bao gom su chuyen doi, cac so gia ngau nhien,cap phat vung nho, kiem soat qua trinh, moi truong, tin hieu,tim kiem va xep thu tu
#define tiny 1e-16  // a cua de bai
#define L 22 //so vong lap

double ham(double x, double y)
{
   	   // return  1/((x-0.5)*(x-0.5)+tiny*tiny) + 1/((y-0.75)*(y-0.75)+ tiny*tiny) ;		//10^-3=>L=10 vong 	  10^-5=>L=10 vong   10^-10=> L=50 vong
		return 1/((x-0.5)*(x-0.5) + (y-0.75)*(y-0.75) + tiny*tiny);		//5.0		10.0
   // return 1/((x-0.75)*(x-0.75)+(y-0.5)*(y-0.5)+tiny*tiny);
}

void hamchiadoandongthoi(double x[], double y[], double a1 , double b1, double a2, double b2, int N)
{
    int i;
    for (i = 0;i <= N;i++)
    {
    	x[i] = a1 + ((b1-a1)/N)*i;
    	y[i] = a2 + ((b2-a2)/N)*i;
	}
}

double hamngaunhien(double a, double b)  //khi tinh trong so de chia lai doan cho truc x, thi hamngaunhien se  dung de lay cac diem tren tung doan tren truc x
{                                       //tuong tu, khi tinh trong so chia lai doan truc y, thi hamngaunhien dung de lay cac diem tren tung doan tren truc y
    return a + (b - a)*rand()/RAND_MAX;
}

int hamngaunhiennguyen(int a, int b) // khi tinh trong so de chia lai doan cho truc x, ham dung de lay hai moc bat ky tren truc y de tinh deltay
{                                    //tuong tu, khi tinh trong so de chia lai doan cho truc y, ham dung de lay hai moc bat ky tren truc x de tinh deltaX
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

void trongso1d(double mang1[], double mang2[], int n)
{
    int i;
    for (i = 0;i <= n;i++)
    {
        printf("\n[%d]\t%lf\t%lf",i,mang1[i],mang2[i]);
    }
}

void trongso2d(double mang1[], double mang2[], double mang3[], int n)
{
    int i;
    for (i = 0;i <= n;i++)
    {
        printf("\n[%d]\t%lf\t%lf\t%lf",i,mang1[i],mang2[i],mang3[i]);
    }
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

void main()
{
//	int L;
//	scanf("%d",&L);
	double a1 = 0; //khai bao can duoi cua x
	double b1 = 1; //khai bao can tren cua x
	double a2 = 0; //khai bao can duoi cua y
	double b2 = 1; //khai bao can tren cua y
	
	int M = 100000; 
	int N = 1000;
	double K = 10000;
	
	int i, j, h; //khai bao cac bien chay
	
	double x[N]; //khai bao mang x
	double y[N]; //khai bao mang y
	
	double alphax[M-1]; //khai bao mang alpha x de chua cac gia tri random cua x
	double alphay[M-1]; //khai bao mang alpha y de chua cac gia tri random cua y
	
	double tcx = 0; //khai bao bien chua gia tri trong can theo x
	double tcy = 0; //khai bao bien chua gia tri trong can theo y
	
	double tongfdeltax[N-1]; //f tong nhan delta x tren tung khoang khi tinh theo x
	double tongfdeltay[N-1]; //f tong nhan delta y tren tung khoang khi tinh theo y

	int rd; //khai bao bien rd de random doan
	double bientam; //khai bao bientam
	
	double p; //khai bao bien p (px hoac py)
	double xmtongfdeltax;
	double xmtongfdeltay;
	
	double mx[N-1]; //khai bao mang trong so x
	double my[N-1];	//khai bao mang trong so y
	double tongm;
	
	int kiemtra = 0,kiemtra1,kiemtra2;
	
	int A = (int)K/N;
	
	double px,py;
       	//BUOC 1: CHIA CAC MANG X VA Y THANH N DOAN 
	hamchiadoandongthoi(x,y,a1,b1,a2,b2,N);
//	trongso1d(x,y,N);
	
//	while ((kiemtra1 < (N-1)) || (kiemtra2 < (N-1)))

	for(h = 0;h <= L;h++)
	{
       	//BUOC 2: Gieo cac diem ngau nhien, roi tinh tong f tren tung khoang khi tinh theo x va khi tinh theo y
	for (i = 0;i <= N-1;i++)
        {
            tcx = 0;
            tcy = 0;
			for(j = (M/N)*i;j <= (M/N)*i+(M/N)-1; j++)
            {
				alphax[j] = hamngaunhien(x[i],x[i + 1]);
				alphay[j] = hamngaunhien(y[i],y[i + 1]);
				rd = hamngaunhiennguyen(0,N-1);							//random doan cho y khi tinh theo x
//				printf("\nrd cho y = %d",rd);
				bientam = hamngaunhien(y[rd],y[rd + 1]);				//random mot diem y tren toan mien tich phan cua y khi tinh theo x
				p = 1/((double)N*(y[rd + 1] - y[rd]));					//py
				tcx = tcx + pow(ham(alphax[j],bientam),2)/pow(p,2);	//trong can khi tinh theo x
				rd = hamngaunhiennguyen(0,N-1);							//random doan cho x khi tinh theo y
//				printf("\nrd cho x = %d",rd);
				bientam = hamngaunhien(x[rd],x[rd + 1]);				//random mot diem x tren toan mien tich phan cua x khi tinh theo y
				p = 1/((double)N*(x[rd + 1] - x[rd]));					//px
				tcy = tcy + pow(ham(bientam,alphay[j]),2)/pow(p,2);	//trong can khi tinh theo y
			}
			tongfdeltax[i] = sqrt(tcx)*(x[i+1] - x[i]);				
			tongfdeltay[i] = sqrt(tcy)*(y[i+1] - y[i]);
		}
	xmtongfdeltax = tong(tongfdeltax,0,N-1);
	xmtongfdeltay = tong(tongfdeltay,0,N-1);
//	trongso1d(tongfdeltax,tongfdeltay,N-1);
	
//	kiemtra = 0; kiemtra1 = 0; kiemtra2 = 0;
	//BUOC 3: Tinh trong so
	for (i = 0;i <= N-1;i++)
	{
		mx[i] = K*(tongfdeltax[i]/xmtongfdeltax);
//		printf("\nmx[%d] = %lf",i,mx[i]);
//		kiemtra1 += sosanhtrongso(mx,i);
		my[i] = K*(tongfdeltay[i]/xmtongfdeltay);
//		printf("\nmy[%d] = %lf",i,my[i]);
//		kiemtra2 += sosanhtrongso(my,i);
	}
	hamxulytrongso(mx,tongm,N-1,K);
	hamxulytrongso(my,tongm,N-1,K);
//	printf("\nMang trong so lan thu %d",h+1);
//	trongso1d(mx,my,N-1);
	
//	kiemtra = kiemtra1 + kiemtra2;
	//BUOC 4:CHIA LAI DOAN
	
//	if	((kiemtra1 < (N-1)) || (kiemtra2 < (N-1)))
//	{
	hamchialaidoan(x,mx,N,A,K);	
	hamchialaidoan(y,my,N,A,K);
//	}
//	printf("\nMang x va y sau khi rebin lan thu %d",h+1);
//	trongso1d(x,y,N);
	} //dong for ket thuc tai day
	
	double I = 0;
	for (i = 0;i <= M-1;i++)
    {
		rd = hamngaunhiennguyen(0,N-1);									//random doan cho x
		alphax[i] = hamngaunhien(x[rd],x[rd+1]); 						//random mot diem x trong doan vua random
		px = 1/((double)N*(x[rd + 1] - x[rd]));							//tinh px
		rd = hamngaunhiennguyen(0,N-1);									//random doan cho y
		alphay[i] = hamngaunhien(y[rd],y[rd+1]);						//random mot diem y trong doan vua random
		py = 1/((double)N*(y[rd + 1] - y[rd]));							//tinh px
		I = I + ham(alphax[i],alphay[i])/(px*py);
	}
	I = (1/(double)M)*I;
	printf("\nket qua la I = %lf",I);

}
