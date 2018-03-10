#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef char TElemType;

typedef struct TreeNode {
	TElemType data;
	TreeNode *lchild, *rchild;
}TreeNode ,*TreeNodePtr;

int N;
int n=0;
TElemType *preData;
TElemType *inData;

void Input()
{
	int i;
	getchar();
	for (i = 0; i < N; i++)
		scanf("%c", preData + i);
	getchar();
	for (i = 0; i < N; i++)
		scanf("%c", inData + i);
}
//int IsLeft(TElemType* tp,TElemType &t1, TElemType &t2)
//{
//	for (int i = 0; tp[i] != t1; i++)
//		if (tp[i] == t1)
//			return 1;
//		else if (tp[i] == t2)
//			return 0;
//	return 0;
//}
//int BuildTree(TreeNodePtr &T)
//{
//	if (n == N)
//		return 0;
//	if (n == 0)
//	{
//		T = (TreeNodePtr)malloc(sizeof(TreeNode));
//		T->data = preData[n++];
//		T->lchild = T->rchild = NULL;
//		BuildTree(T);
//		return 1;
//	}
//	if (IsLeft(inData, preData[n], T->data))
//	{
//		T->lchild = (TreeNodePtr)malloc(sizeof(TreeNode));
//		T->lchild->data = preData[n++];
//		T->lchild->lchild = T->lchild->rchild = NULL;
//		BuildTree(T->lchild);
//		return 1;
//	}
//	
//}
TreeNodePtr BuildTree(TElemType *preData, TElemType*inData,int N)
{
	TreeNodePtr T=NULL;
	if (N)
	{
		int i, j;
		for (i = 0; inData[i] != preData[0]; i++)
			;
		j = N - i - 1;
		T = (TreeNodePtr)malloc(sizeof(TreeNode));
		T->data = preData[0];
		T->lchild = BuildTree(preData + 1, inData, i);
		T->rchild = BuildTree(preData + i + 1, inData + i + 1, j);
	}
	return T;
}
int TreeHeight(TreeNodePtr T)
{
	if (T == NULL)
		return 0;
	int leftTreeHeight = TreeHeight(T->lchild) + 1;
	int rightTreeHeight = TreeHeight(T->rchild) + 1;
	return leftTreeHeight > rightTreeHeight ? leftTreeHeight : rightTreeHeight;
}
int main()
{
	scanf("%d", &N);
	preData = (TElemType *)malloc(N*sizeof(TElemType));
    inData = (TElemType *)malloc(N*sizeof(TElemType));
	Input();

	TreeNodePtr T = BuildTree(preData,inData,N);
	printf("%d", TreeHeight(T));
	return 0;
}