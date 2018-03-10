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
			//�ͷ�����
		}
		//�ͷ�ԭ��
	}
	for (int j = 0; j < i; j++)
		cout << result[j] << endl;
	return 0;
}

//5 - 4 �Ƿ�ͬһ�ö���������(25��)
//����һ���������оͿ���Ψһȷ��һ�ö�����������Ȼ����һ�ø����Ķ���������ȴ�����ɶ��ֲ�ͬ�Ĳ������еõ�������ֱ������� {
//	2, 1, 3
//}��{ 2, 3, 1 }�����ʼΪ�յĶ��������������õ�һ���Ľ�������Ƕ�������ĸ��ֲ������У�����Ҫ�ж������Ƿ�������һ���Ķ�����������
//
//�����ʽ :
//
//	�������������������ݡ�ÿ�����ݵĵ�1�и�������������NN(\le 10��10)��LL���ֱ���ÿ�����в���Ԫ�صĸ�������Ҫ�������и�������2�и���NN���Կո�ָ�������������Ϊ��ʼ�������С����LL�У�ÿ�и���NN�������Ԫ�أ�����LL����Ҫ�������С�
//
//		����������Ǳ�֤ÿ���������ж���1��NN��һ�����С�������NNΪ0ʱ����־����������������ݲ�Ҫ����
//
//�����ʽ :
//
//	��ÿһ����Ҫ�������У���������ɵĶ�������������Ӧ�ĳ�ʼ�������ɵ�һ���������Yes�������������No����
//
//�������� :
//
//	    4 2
//		3 1 4 2
//		3 4 1 2
//		3 2 4 1
//		2 1
//		2 1
//		1 2
//		0
//�������:
//
//	    Yes
//		No
//		No