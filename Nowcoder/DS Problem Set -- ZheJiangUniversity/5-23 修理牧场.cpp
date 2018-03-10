//#define _CRT_SECURE_NO_WARNINGS
//#include <stdlib.h>
//#include <stdio.h>
//
//typedef struct {
//	unsigned int weight;
//	unsigned int parent, lchild, rchild;
//}HTNode, *HuffmanTree;
//
//void setHuffmanTree(HuffmanTree HT, int N)
//{
//	HTNode *p = HT;
//	HTNode *q = HT + N;
//	for (++p; p <= q; ++p)
//	{
//		scanf("%d", &p->weight);
//		p->parent = 0;
//		p->lchild = 0;
//		p->rchild = 0;
//	}
//}
//int FindMin(HuffmanTree HT, int n)
//{
//	HTNode *p = HT;
//	HTNode *q = HT + n - 1;
//	unsigned int min = -1;
//	int pos;
//
//	for (++p; p <= q; ++p)
//		if (!p->parent&&p->weight < min)
//		{
//		    min = p->weight;
//			pos = p - HT;
//		}
//	HT[pos].parent = 1;
//	return pos;
//}
//void buildHuffmanTree(HuffmanTree HT, int N)
//{
//	HTNode *p = HT + N + 1;
//	HTNode *q = HT + 2 * N - 1;
//	int pos1, pos2;
//	
//	for (; p <= q; ++p)
//	{
//		pos1 = FindMin(HT, p - HT);
//		pos2 = FindMin(HT, p - HT);
//
//		p->lchild = pos1;
//		p->rchild = pos2;
//		p->parent = 0;
//		p->weight = HT[pos1].weight + HT[pos2].weight;
//
//		HT[pos1].parent = HT[pos2].parent = p - HT;
//	}
//}
//
//int totalCost(HuffmanTree HT, int N)
//{
//	HTNode *p = HT + N + 1;
//	HTNode *q = HT + 2 * N - 1;
//
//	int cost = 0;
//	for (; p <= q; ++p)
//		cost += p->weight;
//	return cost;
//}
//int main()
//{
//	int N;
//	scanf("%d", &N);
//
//	HuffmanTree HT = (HuffmanTree)malloc((2 * N)*sizeof(HTNode));
//
//	setHuffmanTree(HT, N);
//    
//	buildHuffmanTree(HT, N);
//
//	printf("%d", totalCost(HT, N));
//	return 0;
//}
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;

//void setHuffmanTree(HuffmanTree HT, int N)
//{
//	HTNode *p = HT;
//	HTNode *q = HT + N;
//	for (++p; p <= q; ++p)
//	{
//		scanf("%d", &p->weight);
//		p->parent = 0;
//	}
//}
//int FindMin(HuffmanTree HT, int n)
//{
//	HTNode *p = HT;
//	HTNode *q = HT + n - 1;
//	unsigned int min = -1;
//	int pos = 0;
//
//	for (++p; p <= q; ++p)
//		if (!p->parent&&p->weight < min)
//		{
//			min = p->weight;
//			pos = p - HT;
//		}
//	HT[pos].parent = 1;
//	return pos;
//}
//
//int totalCost(HuffmanTree HT, int N)
//{
//	int pos1, pos2;
//	pos1 = FindMin(HT, N + 1);
//	pos2 = FindMin(HT, N + 1);
//
//	int cost = 0;
//	for (; pos2;)
//	{
//		HT[pos2].parent = 0;
//		HT[pos2].weight += HT[pos1].weight;
//		cost += HT[pos2].weight;
//
//		pos1 = FindMin(HT, N + 1);
//		pos2 = FindMin(HT, N + 1);
//	}
//	return cost;
//}
//int main()
//{
//	int N;
//	scanf("%d", &N);
//
//	HuffmanTree HT = (HuffmanTree)malloc((N+1)*sizeof(HTNode));
//
//	setHuffmanTree(HT, N);
//
//
//	printf("%d", totalCost(HT, N));
//	return 0;
//}

#define MaxWeight 1000000

void set(HuffmanTree HT, int *w, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		HT[i + 1].weight = *(w + i);
		HT[i + 1].parent = HT[i + 1].lchild = HT[i + 1].rchild = 0;
	}
	for (i++; i < 2 * n; i++)
		HT[i].parent = 0;
}

int min(HuffmanTree HT, int i)
{
	int j, m;
	int w = MaxWeight;
	for (j = 1; j < i; j++)
		if (HT[j].parent == 0 && HT[j].weight < unsigned (w))
		{
			m = j;
			w = HT[j].weight;
		}
	HT[m].parent = 1;
	return m;
}
void BuildHuffmanTree(HuffmanTree HT, int n)
{
	int i;
	int s1, s2;
	for (i = n + 1; i <= 2 * n - 1; i++)
	{
		s1 = min(HT, i);
		s2 = min(HT, i);
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[s1].parent = HT[s2].parent = i;
	}
}
int totalCost(HuffmanTree HT, int N)
{
	HTNode *p = HT + N + 1;
	HTNode *q = HT + 2 * N - 1;

	int cost = 0;
	for (; p <= q; ++p)
		cost += p->weight;
	return cost;
}
int main()
{
	int N;
	scanf("%d", &N);

	HuffmanTree HT = (HuffmanTree)malloc((2*N)*sizeof(HTNode));
	int *w = (int *)malloc(N*sizeof(int));

	int i = 0;
	for (; i < N; ++i)
		scanf("%d", w + i);

	set(HT, w, N);
	BuildHuffmanTree(HT, N);

	printf("%d", totalCost(HT, N));
	return 0;
}
