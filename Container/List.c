#include "List.h"
#include <stdlib.h>
#include <stdio.h>
struct Node
{
    ElementType Element;
	Position Next;
};
List MakeEmpty(List L)
{
	if (L != NULL)
	{
		DeleteList(L);
	}
	L = malloc(sizeof(struct Node));
	L->Next = NULL;
	return L;
}
int IsEmpty(List L)
{
	return L->Next == NULL;
}
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}
Position Find(ElementType X, List L)
{
	Position p = Header(L); 
	while(p->Next != NULL)
	{
		p = p->Next;// not null
		if (p->Element == X)
		{
			return p;
		}
	}
	return NULL;
}
void Delete(ElementType X, List L)
{
	Position Prev = L;
	Position P = L->Next;
	while(P!=NULL && P->Element!=X)
	{
		Prev = P;
		P = P->Next;
	}
	if (P!=NULL)
	{
		Prev->Next = P->Next;
		free(P);
	}
}
void Insert(ElementType X, List L, Position P)
{
	Position N = malloc(sizeof(struct Node));
    N->Next = P->Next;
	N->Element = X;
	P->Next = N;
}
void DeleteList(List L)
{
	Position tmp = L->Next;
	while(tmp != NULL)
	{
		Position toDelete = tmp;
		tmp = tmp->Next;
		free(toDelete);
	}
	L->Next = NULL;
}
Position Header(List L)
{
	return L;
}
Position First(List L)
{
	if (!L)
	{
		return NULL;
	} else {
	    return L->Next;
	}
}
Position Advance(Position P)
{
	return P->Next;
}
ElementType Retrieve(Position P)
{
	if (P!=NULL)
	{
		return P->Element;
	}
	else
	{
		return 0; // throw exception
	}
}
void PrintList(List L)
{
	Position P = L->Next;
	printf("List:");
	while(P!=NULL)
	{
		printf("%d ", P->Element);
		P = P->Next;
	}
	printf("\n");
}
