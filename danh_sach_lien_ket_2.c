#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;			//chua du lieu cua node hien tai
	int key;			//chua vi tri cua node
	struct node *next; //chua dia chi node ke tiep ma no tro toi
};
struct node *head = NULL;
struct node *tail = NULL;


char isEmpty()
{
   if (head == NULL)
   return 0;
   else return 1;
}
void printList()
{
   struct node *ptr = head;
   printf("\n[ ");
	
   //bat dau tu phan dau danh sach
   while(ptr != NULL)
	{        
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//chen link tai vi tri dau tien
void insertFirst(int key, int data)
{
   //tao mot link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->key = key;
   link->data = data;
	
   //tro link nay toi first node cu
   link->next = head;
	
   //tro first toi first node moi
   head = link;
}
void main()
{

	int i,n,temp = 0;
	printf("nhap so luong phan tu cua danh sach lien ket: ");
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		printf("nhap phan tu thu %d : ",i+1);
		scanf("%d",&temp);
		insertFirst(i+1, temp);
		temp = 0;
	}
	printList();
}
