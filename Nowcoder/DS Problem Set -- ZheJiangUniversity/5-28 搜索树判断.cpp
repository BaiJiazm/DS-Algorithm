#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;

typedef struct TreeNode {
	TElemType data;
	TreeNode *lchild, *rchild;
}TreeNode, *TreeNodePtr;

void Input(TElemType *inputE,int N)
{
	int i;
	for (i = 0; i < N; i++)
		scanf("%d", inputE + i);
}
void BuildBinarySearchTree(TreeNodePtr &T,TElemType *inputE, int N)
{
	if (N == 0)
	{
		T = NULL;
		return;
	}

	T = (TreeNodePtr)malloc(sizeof(struct TreeNode));
	T->data = inputE[0];

	int i;
	for (i = 1; i < N&&inputE[i] < inputE[0]; i++)
		;
	BuildBinarySearchTree(T->lchild, inputE + 1, i - 1);
	BuildBinarySearchTree(T->rchild, inputE + i, N - i);

	return;
}
void BuildReBinarySearchTree(TreeNodePtr &T, TElemType *inputE, int N)
{
	if (N == 0)
	{
		T = NULL;
		return;
	}

	T = (TreeNodePtr)malloc(sizeof(struct TreeNode));
	T->data = inputE[0];

	int i;
	for (i = 1; i < N&&inputE[i] >= inputE[0]; i++)
		;
	BuildReBinarySearchTree(T->lchild, inputE + 1, i - 1);
	BuildReBinarySearchTree(T->rchild, inputE + i, N - i);

	return;
}
void InorderTraverse(TreeNodePtr T, TElemType * pE,int &pos)
{
	if (T == NULL)
		return;
	InorderTraverse(T->lchild, pE, pos);
	pE[pos++] = T->data;
	InorderTraverse(T->rchild, pE, pos);
	return;
}
void PostOrderTraverse(TreeNodePtr T, TElemType *pE, int &pos)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild, pE, pos);
	PostOrderTraverse(T->rchild, pE, pos);
	pE[pos++] = T->data;
	return;
}
int isMinToMaxRank(TElemType *pE, int N)
{
	TElemType *p = pE;
	TElemType *q = pE + N - 1;
	for (; p < q; p++)
		if (*p>*(p + 1))
			return 0;
	return 1;
}
int isMaxToMinRank(TElemType *pE, int N)
{
	TElemType *p = pE;
	TElemType *q = pE + N - 1;
	for (; p < q; p++)
		if (*p < *(p + 1))
			return 0;
	return 1;
}
void outPut(TElemType *pE, int N)
{
	int i;
	for (i = 0; i < N; i++)
		if (i == 0)
			printf("%d", pE[i]);
		else
			printf(" %d", pE[i]);
}
int main() 
{
	int N;
	int pos = 0;
	scanf("%d", &N);

	TElemType *inputE = (TElemType *)malloc(N*sizeof(TElemType));
	TElemType *pE = (TElemType *)malloc(N*sizeof(TElemType));

	Input(inputE, N);

	TreeNodePtr T = NULL;
	BuildBinarySearchTree(T, inputE, N);
	InorderTraverse(T, pE, pos);
	if (isMinToMaxRank(pE, N))
	{
		printf("YES\n");
		pos = 0;
		PostOrderTraverse(T, pE, pos);
		outPut(pE, N);
		return 0;
	}

	TreeNodePtr TR = NULL;
	pos = 0;
	BuildReBinarySearchTree(TR, inputE, N);
	InorderTraverse(TR, pE, pos);
	if (isMaxToMinRank(pE, N))
	{
		printf("YES\n");
		pos = 0;
		PostOrderTraverse(TR, pE, pos);
		outPut(pE, N);
		return 0;
	}

	printf("NO\n");
	return 0;
}