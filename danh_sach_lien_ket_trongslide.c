#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct nut *lket;		//lket la mot danh sach cac node 
struct nut                     //xay dung mot node trong danh sach
{		
	int gtri;				 //du lieu co kieu int
	struct nut *ktiep;	     //truong ktiep la con tro, tro den 1 node tiep theo 
};
lket taoNutDon(int k)         //ham tra ve dia chi phan tu moi tao
{
	lket tam;                 //khai bao bien
	tam=(lket)malloc(sizeof(struct nut));      //cap phat vung nho cho phan tu 
	if (!tam)                                //neu khong phai bien tam
	{
		printf("Cap phat nut Don that bai!");  //thi in ra dong nay
		exit(0);                               //roi tra ve gia tri 0, sau do ket thuc ham luon
	}
	tam->gtri=k;                               //gan du lieu cho node
	tam->ktiep=NULL;
	return tam;
}

lket taoNutDau(lket *dau, lket *cuoi, int k)  //hay con goi la, them 1 node vao dau danh sach
{
	lket tam=taoNutDon(k);           //nut tam duoc tao boi ham taonutdon
	if(!(*dau))                      //neu khong phai la node *dau 
		*dau=*cuoi=tam;            //thi node *dau va node *cuoi bang node tam
	else {                      //nguoc lai do la node *dau 
		tam->ktiep=*dau;      // thi node (*dau)= node tam tro den ktiep, ma ktiep la dia chi cua node dung sau node tam
		*dau=tam;             //vi dau tro den tam, nen *dau =tam
		}
	return tam;
}

lket taoNutCuoi(lket *dau, lket *cuoi, int k) //hay con goi la, them 1 node vao cuoi danh sach
{
	lket tam=taoNutDon(k);                //node tam duoc tao boi ham taonutdon
	if(!*dau)                           //neu khong phai la node *dau
		*dau=*cuoi=tam;                 //thi node *dau va node *cuoi bang voi node tam
	else                               // nguoc lai neu do la node *dau
	{                            
		(*cuoi)->ktiep=tam;       //thi (*cuoi) tro den ktiep bang node tam, ma ktiep la dia chi cua node tiep theo
		*cuoi=tam;            //node cuoi bang node tam 
	}
	return tam;
}

void chenNutSau(lket nutmoc, int k) //ta can them node tam vao sau node nutmoc trong danh sach
{
	lket tam=taoNutDon(k);     //node tam duoc tao boi ham taonutdon
	tam->ktiep=nutmoc->ktiep;  //tam tro den ktiep bang nutmoc tro den ktiep 
	nutmoc->ktiep=tam;         //nutmoc tro den ktiep (hay cho nutmoc tro den tam)
}

void chenNutTruoc(lket dau, lket nutmoc, int k) 
{
	lket tam = taoNutDon(k);    //node tam duoc tao boi ham taonutdon
	lket q;                     //
	q=dau;
	while(q!=NULL&&q->ktiep!= tam)	//dieu kien q khac rong va ktiep khac tam thi se thuc hien vong lap 
	q=q->ktiep;                     //q(hay dau) q bang q tro toi ktiep 
	q->ktiep=tam;                   //q tro den ktiep bang tam
	tam->ktiep=nutmoc;              //tam tro den ktiep bang nutmoc 
}

void xoaNutGiua(lket dau, lket *bo)   
{
	lket q=dau;
	while(q!=NULL&&q->ktiep!=*bo)		
	q=q->ktiep;
	q->ktiep=(*bo)->ktiep;//thay doi vi tri node tro den cua node q bang voi huong tro den cua node can xoa(hay node *bo)
	(*bo)->ktiep=NULL;   //gan cho huong tro den cua node can xoa bang NULL, roi ngat ket noi no
	free(bo);           //sau do xoa node bo
}

void xoaNutDau(lket *dau)   
{
	lket p=*dau;      //khai bao kieu va gan p bang node dau 
	*dau=p->ktiep;    //vi node can xoa o dau danh sach tuc la ngay node *dau. Vi vay chung ta can di chuyen *dau den node ke tiep sau node p
	p->ktiep=NULL;  //sau khi di chuyen *dau sang node ke tiep, chung ta se ngat ket noi giua p va node phia sau
	free(p);      //bay gio p khong con lien ket voi bat ki node nao trong danh sach nua, nen chung ta xoa node nay 
}

void xoaNutCuoi(lket dau, lket *cuoi) 
{
	lket p=dau, q=*cuoi;  //khai bao voi p la node phia truoc node can xoa, con q la node cuoi cung trong danh sach can xoa
	while (p!=NULL&&p->ktiep!=*cuoi) 		
	p=p->ktiep;     //vi node can xoa o sau node p 
	p->ktiep=NULL; //cho ktiep tro den null, va ngat ket noi node q
	*cuoi=p;       //di chuyen cuoi ve node truoc do(hay con goi la node p)
	free(q);  //xoa node q
}

void xuatdanhsach(lket lkd) 
{
	lket tam;
	if(!lkd)
		printf("\nDanh sach rong!");
	else
		for(tam=lkd;tam;tam=tam->ktiep)
		printf("%d\t",tam->gtri);
}
void main()
{
	int k;
	lket dau,cuoi,nutmoc,bo,lkd;
	taoNutDon(k); 
	taoNutDau(&dau, &cuoi, k);
	taoNutCuoi(&dau, &cuoi, k);
	chenNutSau(nutmoc, k);
	chenNutTruoc(dau, nutmoc, k); 
	xoaNutGiua(dau, &bo);
	xoaNutDau(&dau);
	xoaNutCuoi(dau, &cuoi); 
	xuatdanhsach(lkd);
}	
