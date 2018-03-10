#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	LNode *next;
}LNode, *LinkList;

void buildLinkList(LinkList L)
{
	ElemType e;
	LinkList p = L;
	LinkList q = L;

	while(scanf("%d",&e)&&e!=-1)
	{
		q = (struct LNode*)malloc(sizeof(LNode));
		q->data = e;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}

void MergeLinkList(LinkList L,LinkList L1, LinkList L2)
{
	LinkList pL = L;
	LinkList pL1 = L1->next;
	LinkList pL2 = L2->next;

	ElemType e;
	while (pL1&&pL2)
	{
		if (pL1->data < pL2->data)
		{
			e = pL1->data;
			pL1 = pL1->next;
		}
		else
		{
			e = pL2->data;
			pL2 = pL2->next;
		}

		pL->next = (LinkList)malloc(sizeof(struct LNode));
		pL->next->data = e;
		pL = pL->next;
	}

	while (pL1)
	{
		pL->next = (LinkList)malloc(sizeof(struct LNode));
		pL->next->data = pL1->data;
		pL = pL->next;
		pL1 = pL1->next;
	}
	while (pL2)
	{
		pL->next = (LinkList)malloc(sizeof(struct LNode));
		pL->next->data = pL2->data;
		pL = pL->next;
		pL2 = pL2->next;
	}
	pL->next = NULL;
}

void traverse(LinkList L)
{
	LinkList p = L->next;
	if (p == NULL)
		printf("NULL");

	for (; p; p = p->next)
		if (p->next)
			printf("%d ", p->data);
		else
			printf("%d", p->data);
}
int main()
{
	LinkList L1 = (LinkList)malloc(sizeof(struct LNode));
	LinkList L2 = (LinkList)malloc(sizeof(struct LNode));
	LinkList L = (LinkList)malloc(sizeof(struct LNode));

	buildLinkList(L1);
	buildLinkList(L2);

	MergeLinkList(L, L1, L2);

	traverse(L);

	return 0;
}