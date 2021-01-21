#include<stdio.h>
#include<stdlib.h>
 
#define N 100 //so phan tu toi da la 100
typedef int item;
/*kieu cac phan tu la item
ma cu the o day item la kieu int */
typedef struct
{
    item Elems[N]; //mang kieu item
    int size; //so phan tu toi da cua mang
}List; //kieu danh sach List
 
void Init(List *L); //ham khoi tao danh sach rong
void Init(List *L); //ham khoi tao danh sach rong
int Isempty (List L); //kiem tra danh sach rong
int Isfull (List L); //kiem tra danh sach day
int Insert_k (List *L, item x, int k); //chen x vao vi tri k
void Input (List *L);//nhap danh sach
void Output (List L);//xuat danh sach
int Search (List L, item x); //tim phan tu x trong danh sach
int Del_k (List *L, item *x, int k);//xoa phan tu tai vi tri k
int Del_x(List *L, item x);//xoa phan tu x trong danh sach
item init_x(); //tao phan tu x.
 
//-----------------------------------
 
void Init(List *L) //ham khoi tao danh sach rong
/*Danh sach L duoc khai bao kieu con tro
de khi ra khoi ham no co the thay doi duoc*/
{
    (*L).size = 0; //size = 0.
}
 
int Isempty (List L)
{
    return (L.size==0);
}
 
int Isfull (List L)
{
    return (L.size==N);
}
 
item init_x() //khoi tao gia tri x
{
    int temp;
    scanf("%d",&temp);
    return temp;
}
 
int Insert_k (List *L, item x, int k)//chen x vao vi tri k
{
    if (Isfull(*L)) //kiem tra danh sach day
    {
        printf("Danh sach day !");
        return 0;
    }
 
    if (k<1 || k>(*L).size+1) //kiem tra dieu kien vi tri chen
    {
        printf("Vi tri chen khong hop le !\n");
        return 0;
    }
    printf ("Nhap thong tin: ");
    x = init_x(); //gan x = ham khoi tao x
    int i;
    //di chuyen cac phan tu ve cuoi danh sach
    for (i = (*L).size; i >= k; i--)
        (*L).Elems[i] = (*L).Elems[i-1];
    (*L).Elems[k-1]=x;//chen x vao vi tri k
    (*L).size++;//tang size len 1 don vi.
    return 1;
}
 
void Input (List *L)
{
    int n;
    printf("Nhap so phan tu cua danh sach: ");
    scanf("%d",&(*L).size);
    int i;
    for (i=0; i<(*L).size; i++)
    {
        printf("Nhap phan tu thu %d : ",i+1);
        (*L).Elems[i] = init_x();
    }
}
 
void Output (List L)
{
    printf("Danh sach: \n");
    int i;
    for (i=0; i<L.size; i++)
        printf("%5d",L.Elems[i]);
    printf("\n");
}
 
int Search (List L, item x)
{
    int i;
    for (i=0; i<L.size; i++)
        if (L.Elems[i] == x)
            return i+1;
    return 0;
}
 
int Del_k (List *L, item *x, int k)
{
    if (Isempty(*L))
    {
        printf("Danh sach rong !");
        return 0;
    }
    if (k<1 || k>(*L).size)
    {
        printf("Vi tri xoa khong hop le !");
        return 0;
    }
    *x=(*L).Elems[k-1]; //luu lai gia tri cua phan tu can xoa
    int i;
    for (i=k-1; i<(*L).size-1; i++) //don cac phan tu ve truoc
    (*L).Elems[i]=(*L).Elems[i+1];
    (*L).size--; //giam size
    return 1;
}
 
int Del_x (List *L, item x)
{
    if (Isempty(*L))
    {
        printf("Danh sach rong !");
        return 0;
    }
 
    int i = Search(*L,x);
    if (!i)
    {
        printf("Danh sach khong co %d",x);
        return 0;
    }
    do
    {
        Del_k(L,&x,i);
        i = Search(*L,x);
    }
    while (i);
    return 1;
}
 
 
int main()
{
    List L;
    Init(&L);
    Input(&L);
    Output(L);
 
    int lua_chon;
    printf("Moi ban chon phep toan voi DS LKD:");
    printf("\n1: Kiem tra DS rong");
    printf("\n2: Do dai DS");
    printf("\n3: Chen phan tu x vao vi tri k trong DS");
    printf("\n4: Tim mot phan tu trong DS");
    printf("\n5: Xoa phan tu tai vi tri k");
    printf("\n6: XOa phan tu x trong DS");
    printf("\n7: Thoat");
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&lua_chon);
    switch (lua_chon)
    {
        case 1:
        {
            if (Isempty(L)) printf("DS rong !");
            else printf ("DS khong rong !");
            break;
        }
        case 2: printf ("Do dai DS la: %d.",L.size);break;
        case 3:
        {
            item x;
            int k;
            printf ("Nhap vi tri can chen: ");
            scanf ("%d",&k);
            if (Insert_k(&L,x,k))
            {
                printf ("DS sau khi chen:\n"); //xuat danh sach sau khi chen
                Output(L);
            }
            break;
        }
        case 4:
        {
            item x;
            printf ("Moi ban nhap vao phan tu can tim: ");
            scanf("%d",&x);
            int k=Search(L,x);
            if (k) printf ("Tim thay %d trong DS tai vi tri thu: %d",x,k);
            else printf ("Khong tim thay %d trong danh sach !",x);
            break;
        }
        case 5:
        {
            int k;
            item x;
            printf ("Nhap vi tri can xoa: ");
            scanf ("%d",&k);
            if (Del_k (&L,&x,k))
            {
                printf ("DS sau khi xoa:\n");
                Output(L);
            }
            break;
        }
        case 6:
        {
            item x;
            printf ("Nhap phan tu can xoa: ");
            scanf ("%d",&x);
            if (Del_x(&L,x))
            {
                printf ("DS sau khi xoa:\n");
                Output(L);
            }
            break;
        }
        case 7: break;
    }
    }while (lua_chon !=7);
    return 0;
}
