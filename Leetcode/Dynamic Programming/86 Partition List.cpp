#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

/**
* Definition for singly-linked list.*/
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode *partition(struct ListNode *head, int x)
{
	/**
	* 思路是将list按X分成两段
	* 小于的连接p
	* 大于的连接q
	* 最后合并p和q即可
	*/
	struct ListNode* p = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode* q = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode* pHead = p;
	struct ListNode* qHead = q;

	p->next = q->next = NULL;

	while (head != NULL)
	{
		if (head->val < x)
		{
			p->next = head;
			p = p->next;
		}
		else
		{
			q->next = head;
			q = q->next;
		}
		head = head->next;
	}
	p->next = qHead->next;
	q->next = NULL;
	return pHead->next;
}
//struct ListNode* partition(struct ListNode* head, int x) {
//	struct ListNode*po = head;
//	struct ListNode *pn = NULL;
//	struct ListNode *pt = NULL;
//
//	for (; po&&po->val != x; po = po->next)
//		;
//	if (po == NULL)
//		return head;
//
//	for (; po->next;)
//	{
//		if (po->next->val < x)
//		{
//			if (pn == NULL)
//			{
//				pn = po->next;
//				pt = po->next;
//			}
//			else
//			{
//				pt->next = po->next;
//				pt = pt->next;
//			}
//			po->next = po->next->next;
//		}
//		else
//			po = po->next;
//	}
//
//	if (pn == NULL)
//		return head;
//
//	if (head->val >= x)
//	{
//		pt->next = head;
//		return pn;
//	}
//	
//	for (po = head; po->next->val < x; po = po->next)
//		;
//
//	pt->next = po->next;
//	po->next = pn;
//
//	return head;
//}

void InitLinkList(ListNode**L)
{
	*L = (ListNode*)malloc(sizeof(struct ListNode));
	(*L)->next = NULL;
}

void BuildLinkList(ListNode **L)
{
	int x;
	struct ListNode *p = *L;

	while (scanf("%d", &x))
	{
		p->next = (ListNode*)malloc(sizeof(struct ListNode));
		p->next->val = x;
		p = p->next;
	}
	p->next = NULL;
}

void TraverseList(ListNode**L)
{
	struct ListNode *p = (*L)->next;
	while (p)
	{
		printf("%d ", p->val);
		p = p->next;
	}
}

int main()
{
	struct ListNode *L = NULL;
	InitLinkList(&L);
	BuildLinkList(&L);

	L->next = partition(L->next, 3);
	TraverseList(&L);

	getchar();
	return 0;
}