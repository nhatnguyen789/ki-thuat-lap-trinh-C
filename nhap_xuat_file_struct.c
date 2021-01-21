#include <stdio.h>
#include <string.h>
#define N 30
struct date
{
	unsigned short dd;
	unsigned short mm;
	int yy;	
};
struct sinhvien
{
	char ho_ten_lot[25];
	char ten[7];
	int mssv;
	struct date ngay_sinh;
	int stt; 	
};
void nhap_ttsv(struct sinhvien *sv);
void nhap_dssv(struct sinhvien sv[],int *n);
void xuat_dssv(struct sinhvien sv[],int n);
void f_xuat_dssv(struct sinhvien sv[],int n);
void swap_sv(struct sinhvien *sv1,struct sinhvien *sv2);
void fix_stt(struct sinhvien sv[],int n);
void sap_xep_dssv(struct sinhvien sv[],int n);
void them_ttsv(struct sinhvien sv[],int *n);
void refresh_file();

void main()
{
	struct sinhvien sv[N];
	int n;
	refresh_file();
	
	nhap_dssv(sv,&n);
	xuat_dssv(sv,n);
	f_xuat_dssv(sv,n);
	
	sap_xep_dssv(sv,n);
	xuat_dssv(sv,n);
	f_xuat_dssv(sv,n);
	
	them_ttsv(sv,&n);
	xuat_dssv(sv,n);
	f_xuat_dssv(sv,n);
	
	sap_xep_dssv(sv,n);
	xuat_dssv(sv,n);
	f_xuat_dssv(sv,n);
	
}
void nhap_ttsv(struct sinhvien *sv)
{	
	int l;
	fflush(stdin);
	printf("nhap ho va ten lot sinh vien: \n");
	fgets(sv->ho_ten_lot,25,stdin);
	l = strlen(sv->ho_ten_lot)-1;
	sv->ho_ten_lot[l] = '\0';
	printf("nhap ten sinh vien: \n");
	fgets(sv->ten,7,stdin);
	l = strlen(sv->ten)-1;
	sv->ten[l] = '\0';
	printf("nhap ma so sinh vien: ");scanf("%d",&sv->mssv);
	printf("nhap ngay sinh: \n");
	printf("ngay: ");scanf("%d",&sv->ngay_sinh.dd);
	printf("thang: ");scanf("%d",&sv->ngay_sinh.mm);
	printf("nam: ");scanf("%d",&sv->ngay_sinh.yy);
	sv->stt = 0;

}
void nhap_dssv(struct sinhvien sv[],int *n)
{
	int i;
	printf("moi nhap so luong sinh vien: ");
	scanf("%d",n);
	for (i = 0; i < *n; i++)
	{
		printf("sinh vien thu %d \n",i+1);
		nhap_ttsv(&sv[i]);	
	}
	fix_stt(sv,*n);
}
void xuat_dssv(struct sinhvien sv[],int n)
{	
	int i;
	printf("xuat danh sach sinh vien: \n");
	for (i = 0; i < n; i++)
	{
		printf("so thu tu: %d \n",sv[i].stt);
		printf("ten sinh vien: %s %s \n",sv[i].ho_ten_lot,sv[i].ten);
		printf("ma so sinh vien: %d \n",sv[i].mssv);
		printf("ngay sinh: %d / %d / %d \n",sv[i].ngay_sinh.dd,sv[i].ngay_sinh.mm,sv[i].ngay_sinh.yy);
		
	}
}
void f_xuat_dssv(struct sinhvien sv[],int n)
{
	int i;
	FILE *fsv = fopen("xuat_thong_tin.txt","a");
	if (fsv)
	{
		fprintf(fsv,"xuat danh sach sinh vien: \n");
		for (i = 0; i < n;i++)
		{
			fprintf(fsv,"so thu tu: %d \n",sv[i].stt);
			fprintf(fsv,"ten sinh vien: %s %s \n",sv[i].ho_ten_lot,sv[i].ten);
			fprintf(fsv,"ma so sinh vien: %d \n",sv[i].mssv);
			fprintf(fsv,"ngay sinh: %d / %d / %d \n",sv[i].ngay_sinh.dd,sv[i].ngay_sinh.mm,sv[i].ngay_sinh.yy);
			
		}
		fclose(fsv);
	}      
}
void swap_sv(struct sinhvien *sv1,struct sinhvien *sv2)
{
	struct sinhvien svt;
	svt = *sv1;
	*sv1 = *sv2;
	*sv2 = svt;
}
void fix_stt(struct sinhvien sv[],int n)
{
	
	int i;
	for (i = 0; i < n; i++)
	{
		sv[i].stt = i+1;
	}
}
void sap_xep_dssv(struct sinhvien sv[],int n)
{
	printf("tien hanh sap xep lai danh sach sinh vien theo ten.\n");
	FILE *fsv = fopen("xuat_thong_tin.txt","a");
	if (fsv)
	{
		fprintf(fsv,"tien hanh sap xep lai danh sach sinh vien theo ten.\n");
		fclose(fsv);
	}
	int i,j,k,ss;
	{
		for (i = 0; i < n-1; i++)
		{
			for (j = i+1; j < n; j++)
			{
				ss = strcmp(sv[i].ten,sv[j].ten);
				if (ss > 0)
				{
					swap_sv(&sv[i],&sv[j]);
				}
			}
		}
	}
	fix_stt(sv,n);
}
void them_ttsv(struct sinhvien sv[],int *n)
{
	int them,i;
	int k = 0;
	printf("moi nhap so luong sinh vien can them: ");
	scanf("%d",&them);
	for (i = *n; i < *n+them; i++)
	{
		printf("sinh vien can them thu %d \n",k+1);
		nhap_ttsv(&sv[i]);
		k++;
	}
	*n = *n + them;
	fix_stt(sv,*n);
}
void refresh_file()
{
	FILE *fsv = fopen("xuat_thong_tin.txt","w+");
	if(fsv) close(fsv);
}
