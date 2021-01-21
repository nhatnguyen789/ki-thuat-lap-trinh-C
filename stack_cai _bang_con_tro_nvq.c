#include <stdlib.h>
#include <stdio.h>
 
typedef int item; //kieu du lieu
struct Node
{
    item Data; //du lieu
    struct Node *Next; //link
};
struct Stack
{
    struct Node *Top;
};
 
void Init (struct Stack *S); //khoi tao Stack rong
int Isempty(struct Stack S); //kiem tra Stack rong
int Len (struct Stack S); //Do dai Stack
void Push(struct Stack *S, item x); //them phan tu vao Stack
int Peak(struct Stack S); //Lay phan tu o dau Stack nhung khong xoa
int Pop(struct Stack *S); //Loai bo phan tu khoi Stack
void Input (struct Stack *S); //Nhap Stack
void Output(struct Stack S); //Xuat Stack
struct Node *MakeNode( item x); //Tao 1 Node
 
void Init (struct Stack *S) //khoi tao Stack rong
{
    S->Top = NULL;
}
 
int Isempty(struct Stack S) //kiem tra Stack rong
{
    return (S.Top == NULL);
}
 
int Len (struct Stack S)
{
    struct Node *P = S.Top;
    int i=0;
    while (P != NULL) //trong khi chua het Stack thi van duyet
    {
        i++;
        P = P->Next;
    }
    return i;
}
 
struct Node *MakeNode(item x) //tao 1 Node
{
    struct Node *P = (struct Node*) malloc(sizeof(struct Node));
    P->Next = NULL;
    P->Data = x;
    return P;
}
 
void Push(struct Stack *S, item x) //them phan tu vao Stack
{
    struct Node *P = MakeNode(x);
    P->Next = S->Top;
    S->Top = P;
}
 
int Peak(struct Stack S) //Lay phan tu o dau Stack nhung khong xoa
{
    return S.Top->Data;
}
 
int Pop(struct Stack *S) //Loai bo phan tu khoi Stack
{
    if (!(S->Top==NULL))
    {
        item x = S->Top->Data; //luu lai gia tri
        S->Top = S->Top->Next; //Xoa phan tu Top
        return x;
    }
}
 
void Input (struct Stack *S) //nhap danh sach
{
    int i=0; 
    item x;
    do
    {
        i++;
        printf ("Nhap phan tu thu %d : ",i);
        scanf("%d",&x);
        if (x != 0) Push(S,x);
    } while(x != 0); //nhap 0 de ket thuc
}
 
void Output(struct Stack S)
{
    struct Node *P = S.Top;
    while (P != NULL)
    {
        printf("%d   ",P->Data);
        P = P->Next;
    }
    printf("\n");
}
 
int main()
{
    struct Stack S;
    Init(&S);
    Input(&S);
    Output(S);
 
    int lua_chon;
    printf("Moi ban chon phep toan voi DS LKD:");
    printf("\n1: Kiem tra Stack rong");
    printf("\n2: Do dai Stack");
    printf("\n3: Them phan tu vao Stack");
    printf("\n4: Xoa phan tu trong Stack");
    printf("\n5: Xuat Stack");
    printf("\n6: Thoat");
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&lua_chon);
        switch (lua_chon)
        {
            case 1:
            {
                if (Isempty(S)) printf("Stack rong !");
                else printf ("Stack khong rong !");
                break;
            }
            case 2:
            {
                printf("Do dai Stack: %d",Len(S));
                break;
            }
            case 3:
            {
                item x;
                printf ("Nhap phan tu can chen vao DS: ");
                scanf("%d",&x);
                Push(&S,x);
                break;
            }
            case 4:
            {
                Pop(&S);
                break;
            }
            case 5: 
            {
                Output(S);
                break;
            }
            case 6: break;
        }
    }while (lua_chon !=6);
    return 0;
}
