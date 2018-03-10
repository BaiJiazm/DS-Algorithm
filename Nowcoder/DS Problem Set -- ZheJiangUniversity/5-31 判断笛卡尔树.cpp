#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef int ElemType1;
typedef int ElemType2;

typedef struct Node{
	ElemType1 k1;
	ElemType2 k2;
	int lchild;
	int rchild;
}Node,*NodePtr;

int InputData(NodePtr T, int N)
{
	if (N == 0)
		return -1;
	int i;
	int *tem = new int[N];
	for (i = 0; i < N; i++)
		tem[i] = 0;

	for (i = 0; i < N; i++)
	{
		scanf("%d%d%d%d", &T[i].k1, &T[i].k2, &T[i].lchild, &T[i].rchild);
		if (T[i].lchild >= 0)
			tem[T[i].lchild] = 1;
		if (T[i].rchild >= 0)
			tem[T[i].rchild] = 1;
	}

	for (i = 0; tem[i]; i++)
		;
	return i;
}

void InorderTraverse(NodePtr T, int root, ElemType1 * pE1, int &pos)
{
	if (root == -1)
		return;
	InorderTraverse(T, T[root].lchild, pE1, pos);
	pE1[pos++] = T[root].k1;
	InorderTraverse(T, T[root].rchild, pE1, pos);
	return;
}

int isOrderRank(ElemType1 * pE1, int N)
{
	ElemType1 *p = pE1;
	ElemType1 *q = pE1 + N - 1;
	for (; p < q;p++)
		if (*p>*(p+1))
			return 0;
	return 1;
}
int IsBinarySearchTree(NodePtr T, int root,int N)
{
	if (root == -1)
		return 1;
	ElemType1* pE1 = (ElemType1*)malloc(N*sizeof(ElemType1));
	
	int pos = 0;
	InorderTraverse(T, root, pE1, pos);
    
	return isOrderRank(pE1, N);
}

// 判断是否为搜索二叉树时会错误
//int IsBinarySearchTree(NodePtr T, int root)
//{
//	if (root == -1)
//		return 1;
//	
//	int left = T[root].lchild;
//	int right = T[root].rchild;
//
//	if (left != -1)
//		if (T[left].k1 >= T[root].k1 || T[left].k2 <= T[root].k2)
//			return 0;
//
//	if (right != -1)
//		if (T[root].k1 >= T[right].k1 || T[right].k2 <= T[root].k2)
//			return 0;
//
//	return IsBinarySearchTree(T, left) && IsBinarySearchTree(T, right);
//}

int IsMinHeap(NodePtr T, int root)
{
	if (root == -1)
		return 1;

	int left = T[root].lchild;
	int right = T[root].rchild;

	if (left != -1)
		if (T[left].k2 <= T[root].k2)
			return 0;

	if (right != -1)
		if (T[right].k2 <= T[root].k2)
			return 0;

	return IsMinHeap(T, left) && IsMinHeap(T, right);
}

int main()
{
	int N;
	int root;

	scanf("%d", &N);
	NodePtr T = (NodePtr)malloc(N*sizeof(Node));

	root=InputData(T, N);

	if (IsBinarySearchTree(T, root,N)&&IsMinHeap(T,root))
		printf("YES");
	else
		printf("NO");

	return 0;
}
//C++ 方式答案
//#include <iostream>  
//#include <deque>  
//using namespace std;
//
//typedef struct
//{
//	int K1;
//	int K2;
//	int lChild;
//	int rChild;
//}BNode;
//
//deque<BNode> de;
//
//deque<int> tde;
//
//bool a[1005] = { false };
//
//int sum = 0;
//
//void PreTraval(BNode root)
//{
//	if (root.lChild != -1)
//		PreTraval(de[root.lChild]);
//	tde.push_back(root.K1);
//	if (root.rChild != -1)
//		PreTraval(de[root.rChild]);
//}
//
//bool IsSDD(BNode root)
//{
//	if (root.lChild == -1 && root.rChild == -1)
//		return true;
//	else if (root.lChild == -1 && root.rChild != -1)
//	{
//		if (de[root.rChild].K2 > root.K2)
//			return IsSDD(de[root.rChild]);
//		else
//			return false;
//	}
//	else if (root.lChild != -1 && root.rChild == -1)
//	{
//		if (de[root.lChild].K2 > root.K2)
//			return IsSDD(de[root.lChild]);
//		else
//			return false;
//	}
//	else
//	{
//		if (root.K2 < de[root.lChild].K2 && root.K2 < de[root.rChild].K2)
//			return IsSDD(de[root.lChild]) && IsSDD(de[root.rChild]);
//		else
//			return false;
//	}
//}
//
//bool IsBST()
//{
//	for (int i = 1; i < tde.size(); ++i)
//	{
//		if (tde[i] <= tde[i - 1])
//			return false;
//	}
//	return true;
//}
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		BNode tn;
//		scanf("%d%d%d%d", &tn.K1, &tn.K2, &tn.lChild, &tn.rChild);
//		//  cin>>tn.K1>>tn.K2>>tn.lChild>>tn.rChild;  
//		if (tn.lChild >= 0)
//			a[tn.lChild] = true;
//		if (tn.rChild >= 0)
//			a[tn.rChild] = true;
//		de.push_back(tn);
//	}
//	int rootIndex = 0;
//	for (int i = 0; i < de.size(); ++i)
//		if (!a[i])
//		{
//			rootIndex = i;
//			break;
//		}
//	PreTraval(de[rootIndex]);
//
//
//	if (IsBST() && IsSDD(de[rootIndex]))
//		cout << "YES" << endl;
//	else
//		cout << "NO" << endl;
//	return 0;
//}