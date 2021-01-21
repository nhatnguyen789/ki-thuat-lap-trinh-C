#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tagNode
{ int Info; // Luu th�ng tin b?n th�n
struct tagNode *pNext; //Luu d?a ch? c?a Node d?ng sau
}Node;
typedef struct tagList
{ Node *pHead;//Luu d?a ch? Node d?u ti�n trong List
Node *pTail; //Luu d?a ch? c?a Node cu?i c�ng trong List
}LIST; // ki?u danh s�ch li�n k?t don
void CreateList(struct tagList *l)
{
l->pHead=NULL;
l->pTail=NULL;
}
Node* CreateNode( int x) // trong b�i h?c l� int
{ Node *p;
p = (Node *)malloc(sizeof(Node));//C?p ph�t v�ng nh? cho ph?n t?
if ( p==NULL) exit(1);
p ->Info = x; //g�n d?a li?u cho n�t
p->pNext = NULL;
return p;
}
void main()
{
	int x;
	CreateNode(x);
}
