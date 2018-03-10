#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */

int GetHeight(BinTree BT)
{
	if (BT == NULL)
		return 0;
	int leftTreeHeight = GetHeight(BT->Left) + 1;
	int rightTreeHeight = GetHeight(BT->Right) + 1;
	return leftTreeHeight > rightTreeHeight ? leftTreeHeight : rightTreeHeight;
}
int main()
{
	BinTree BT = CreatBinTree();
	printf("%d\n", GetHeight(BT));
	return 0;
}
/* 你的代码将被嵌在这里 */
