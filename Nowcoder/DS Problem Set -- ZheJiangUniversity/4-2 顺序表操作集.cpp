#define _CRT_SECURE_NO_WARNINGS
//其中list结构定义如下：
//
//typedef int position;
//typedef struct lnode *list;
//struct lnode {
//	elementtype data[maxsize];
//	position last; /* 保存线性表中最后一个元素的位置 */
//};
//各个操作函数的定义为：
//
//list makeempty()：创建并返回一个空的线性表；
//
//position find(list l, elementtype x)：返回线性表中x的位置。若找不到则返回error；
//
//bool insert(list l, elementtype x, position p)：将x插入在位置p并返回true。若空间已满，则打印“full”并返回false；如果参数p指向非法位置，则打印“illegal position”并返回false；
//
//bool delete(list l, position p)：将位置p的元素删除并返回true。若参数p指向非法位置，则打印“position p empty”（其中p是参数值）并返回false。
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
//typedef enum { false, true } bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty();
Position Find(List L, ElementType X);
bool Insert(List L, ElementType X, Position P);
bool Delete(List L, Position P);

int main()
{
	List L;
	ElementType X;
	Position P;
	int N;

	L = MakeEmpty();
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		if (Insert(L, X, 0) == false)
			printf(" Insertion Error: %d is not in.\n", X);
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		P = Find(L, X);
		if (P == ERROR)
			printf("Finding Error: %d is not in.\n", X);
		else
			printf("%d is at position %d.\n", X, P);
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &P);
		if (Delete(L, P) == false)
			printf(" Deletion Error.\n");
		if (Insert(L, 0, P) == false)
			printf(" Insertion Error: 0 is not in.\n");
	}
	return 0;
}

/* 你的代码将被嵌在这里 */
List MakeEmpty()
{
	//List L = (LNode *)malloc(sizeof(LNode));
	List L = (List)malloc(sizeof(ElementType)*(MAXSIZE)+sizeof(Position));
	L->Last = 0;
	return L;
}

Position Find(List L, ElementType e)
{
	int i =0;
	for (i = 0; i < L->Last; i++)
		if (e == L->Data[i])
			break;
	if (i < L->Last)
		return i;
	else
		return ERROR;
}

bool Insert(List L, ElementType X, Position P)
{
	if (L->Last == MAXSIZE)
	{
		printf("FULL");
		return false;
	}
	else if (P<0 || P>MAXSIZE - 1)
	{
		printf("illegal position");
		return false;
	}
	
	int start = P;
	int end = L->Last - 1;
	for (; end >= start; end--)
		L->Data[end + 1] = L->Data[end];
	L->Data[start] = X;
	L->Last++;
	return true;
}

bool Delete(List L, Position P)
{
	if (P<0 || P>MAXSIZE-1)
	{
		printf("POSITION %d EMPTY", P);
		return false;
	}

	int start = P;
	int end = L->Last - 1;
	for (; start < end; start++)
		L->Data[start] = L->Data[start + 1];
	L->Last--;
	return true;
}
//输入样例：
//
//6
//1 2 3 4 5 6
//3
//6 5 1
//2
//- 1 6
//输出样例：
//
//FULL Insertion Error : 6 is not in.
//Finding Error : 6 is not in.
//5 is at position 0.
//1 is at position 4.
//POSITION - 1 EMPTY Deletion Error.
//FULL Insertion Error : 0 is not in.
//POSITION 6 EMPTY Deletion Error.
//FULL Insertion Error : 0 is not in.List L = (List)malloc(sizeof(ElementType)*(MAXSIZE)+sizeof (Position));