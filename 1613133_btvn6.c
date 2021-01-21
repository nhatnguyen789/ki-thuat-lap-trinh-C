#include <stdio.h>

struct ngaythangnam
{
	unsigned short ngay;
	unsigned short thang;
	int nam;
};

typedef struct
{
	char *firstname[1000];
	char *middlename[1000];
	struct ngaythangnam DOB;
	float PHYS;
	float PRC;
	float DA;
} SV;

void Nhapsv (SV *sv)
{
	printf("\n Input Fisrtname: ");
	scanf("%s",&sv->firstname);
	printf("Input Middlename: ");
        scanf("%s",&sv->middlename);
	printf("Ngay: ");
	scanf("%d",&sv->DOB.ngay);
	printf("Thang: ");
	scanf("%d",&sv->DOB.thang);
	printf("Nam: ");
	scanf("%d",&sv->DOB.nam);
	printf("Diem mon ly: ");
	scanf("%f",&sv->PHYS);
	printf("Diem Programming C: ");
	scanf("%f",&sv->PRC);
	printf("Diem Digital and Analog: ");
	scanf("%f",&sv->DA);
}

void Xuatsv (SV sv)
{
	printf("\nFirst name: %s",sv.firstname);
	printf("\nMiddle name: %s",sv.middlename);
	printf("\nNgay sinh: %d",sv.DOB.ngay);
	printf("-%d",sv.DOB.thang);
	printf("-%d",sv.DOB.nam);
	printf("\nLy: %g",sv.PHYS);
        printf("\nProgramming C: %g",sv.PRC);
        printf("\nDigital - Analog: %g\n",sv.DA);
}

void Nhapds (SV a[], int n){
	int i;
	for (i=0;i<n;++i){
		printf("-----Nhap thong tin sv thu %d: -----",i + 1);
		Nhapsv(&a[i]);
	}
}

void Xuatds (SV a[],int n){
	int i;
	for(i=0;i<n;++i){
                printf("\n\n\t-----Thong tin sv thu %d:----- ",i+1);
                Xuatsv(a[i]);
      }
}

void Themsv (SV a[],int n){
	printf("-----Nhap them 1 sv:-----");
	Nhapsv(&a[n]);
}

void Xuatfile(SV a[], int n, char fileName[]){
        FILE * fp;
        fp = fopen (fileName,"r");
        fprintf(fp,"%10s%10s%3s%3s%5s%5s%3s%3s\n","First name ", "Middle name ", "Sinh ngay ", "Thang ", "Nam ", "Ly ", "Pro C ", "Digital - Analog ");
        int i;
        for(i = 0;i < n;i++){
                fprintf(fp,"%8s%10s%10d%8d%8d%4g%4g%6g\n", a[i].firstname,a[i].middlename, a[i].DOB.ngay, a[i].DOB.thang, a[i].DOB.nam, a[i].PHYS, a[i].PRC, a[i].DA);
         }
        fclose (fp);
}

void main(){
	int n;
	char fileName[] = "DSSV.txt";
	do{
        	printf("\n***Nhap so luong SV:"); scanf("%d", &n);
    		}
	while(n <= 0);
   	SV a[n];
	Nhapds(a,n);
	//Themsv(a,n);
	Xuatds(a,n+1);
	Xuatfile(a,n+1,fileName);
}
