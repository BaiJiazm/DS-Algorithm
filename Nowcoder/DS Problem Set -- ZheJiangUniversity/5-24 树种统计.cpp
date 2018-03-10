#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char *ElementType;
struct TNode
{
	ElementType Data;
	struct TNode *Left;
	struct TNode *Right;
	int num;//��������
};
typedef struct TNode *BinTree;
typedef struct TNode *Position;
BinTree Insert(BinTree BST, ElementType X)
{
	if (!BST) { /* ��ԭ��Ϊ�գ����ɲ�����һ�����Ķ��������� */
		BST = (BinTree)malloc(sizeof(struct TNode));
		//BST->Data = X;
		BST->Data = (ElementType)malloc((strlen(X) + 1)*sizeof(char));
		strcpy(BST->Data, X);
		BST->num = 1;

		BST->Left = BST->Right = NULL;
	}
	else { /* ��ʼ��Ҫ����Ԫ�ص�λ�� */
		if (strcmp(BST->Data, X) == 0)
			BST->num++;
		else if (strcmp(X, BST->Data) < 0)
			BST->Left = Insert(BST->Left, X);   /*�ݹ����������*/
		else
			BST->Right = Insert(BST->Right, X); /*�ݹ����������*/
												/* else X�Ѿ����ڣ�ʲô������ */
	}
	return BST;
}

void InOrderTraverse(BinTree BST,int N)
{
	if (BST == NULL)
		return;
	InOrderTraverse(BST->Left, N);
	
	printf("%s %.4f%%\n", BST->Data, BST->num*100.0 / N);

	InOrderTraverse(BST->Right, N);
}
int main()
{
	int N;
	scanf("%d\n", &N);
	BinTree BST = NULL;
	int i;
	char str[31];
	for (i = 0; i < N; i++)
	{
		gets_s(str);
		BST = Insert(BST, str);
	}
	InOrderTraverse(BST, N);
	return 0;
}
