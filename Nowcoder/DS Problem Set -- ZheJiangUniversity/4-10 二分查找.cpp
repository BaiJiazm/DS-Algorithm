#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List Tbl, ElementType K);

int main()
{
	List Tbl;
	ElementType K;
	Position P;

	Tbl = ReadInput();
	scanf("%d", &K);
	P = BinarySearch(Tbl, K);
	printf("%d\n", P);

	return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch(List Tbl, ElementType K)
{
	int left = 1;
	int right = Tbl->Last;

	ElementType e;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		e = Tbl->Data[mid];

		if (e == K)
			return mid;
		else if (e < K)
			left = mid + 1;
		else if (e > K)
			right = mid - 1;
	}
	return NotFound;
}