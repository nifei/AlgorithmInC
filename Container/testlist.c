#include "List.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	List l = MakeEmpty(NULL);
	int isEmpty = IsEmpty(l);
	printf("IsEmpty(l)=%d\n", isEmpty);
	Insert(0, l, Header(l));
	Insert(1, l, Header(l));
	Insert(2, l, Header(l));
	Insert(3, l, Header(l));
	isEmpty = IsEmpty(l);
	printf("IsEmpty(l)=%d\n", isEmpty);
	PrintList(l);
	Position P = Find(1, l);
	int isLast = IsLast(P, l);
	printf("1 IsLast(P)=%d\n", isLast);
	Delete(0, l);
	PrintList(l);
	P = Find(1, l);
	isLast = IsLast(P, l);
	printf("1 IsLast(P)=%d\n", isLast);
	P = First(l);
	printf("First(l) = %d\n", Retrieve(P));
	return 0;
}
