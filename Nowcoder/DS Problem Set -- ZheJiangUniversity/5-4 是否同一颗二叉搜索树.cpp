#include <iostream>
using namespace std;

typedef int TElemType;
struct TNode
{
	TElemType Data;
	TNode *Left;
	TNode *Right;
};
typedef TNode *BinTree;
void InsertBinTree(BinTree &B, TElemType e)
{
	if (B == NULL)
	{
		B = new TNode;
		B->Data = e;
		B->Left = B->Right = NULL;
	}
	if (e < B->Data)
		InsertBinTree(B->Left, e);
	else if (e>B->Data)
		InsertBinTree(B->Right, e);
}
void BuildBinTree(BinTree & B, int N)
{
	int i;
	while (N--)
	{
		cin >> i;
		InsertBinTree(B, i);
	}
}
int IsSameTree(BinTree Ori, BinTree New)
{
	if (Ori == NULL&&New == NULL)
		return 1;
	if (Ori == NULL || New == NULL)
		return 0;
	if (Ori->Data != New->Data)
		return 0;
	return IsSameTree(Ori->Left, New->Left) && IsSameTree(Ori->Right, New->Right);
}
int main()
{
	int N, L;
	int i = 0;
	char *result[100];
	BinTree OriTree;
	BinTree NewTree;
	while (1)
	{
		cin >> N;
		if (N == 0)
			break;
		cin >> L;
		OriTree = NULL;
		BuildBinTree(OriTree, N);
		while (L--)
		{
			NewTree = NULL;
			BuildBinTree(NewTree, N);
			if (IsSameTree(OriTree, NewTree))
				result[i++] = "Yes";
			else
				result[i++] = "No";
			//释放新树
		}
		//释放原树
	}
	for (int j = 0; j < i; j++)
		cout << result[j] << endl;
	return 0;
}

//5 - 4 是否同一棵二叉搜索树(25分)
//给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列 {
//	2, 1, 3
//}和{ 2, 3, 1 }插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。
//
//输入格式 :
//
//	输入包含若干组测试数据。每组数据的第1行给出两个正整数NN(\le 10≤10)和LL，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出NN个以空格分隔的正整数，作为初始插入序列。最后LL行，每行给出NN个插入的元素，属于LL个需要检查的序列。
//
//		简单起见，我们保证每个插入序列都是1到NN的一个排列。当读到NN为0时，标志输入结束，这组数据不要处理。
//
//输出格式 :
//
//	对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。
//
//输入样例 :
//
//	    4 2
//		3 1 4 2
//		3 4 1 2
//		3 2 4 1
//		2 1
//		2 1
//		1 2
//		0
//输出样例:
//
//	    Yes
//		No
//		No