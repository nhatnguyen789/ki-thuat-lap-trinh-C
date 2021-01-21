#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tagNode
{ int Info; // Luu thông tin b?n thân
struct tagNode *pNext; //Luu d?a ch? c?a Node d?ng sau
}Node;
typedef struct tagList
{ Node *pHead;//Luu d?a ch? Node d?u tiên trong List
Node *pTail; //Luu d?a ch? c?a Node cu?i cùng trong List
}LIST; // ki?u danh sách liên k?t don
void CreateList(struct tagList *l)
{
l->pHead=NULL;
l->pTail=NULL;
}
Node* CreateNode( int x) // trong bài h?c là int
{ Node *p;
p = (Node *)malloc(sizeof(Node));//C?p phát vùng nh? cho ph?n t?
if ( p==NULL) exit(1);
p ->Info = x; //gán d?a li?u cho nút
p->pNext = NULL;
return p;
}
void main()
{
	int x;
	CreateNode(x);
}
