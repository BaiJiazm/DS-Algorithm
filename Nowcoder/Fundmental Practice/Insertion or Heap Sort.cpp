#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NMAX 100

int n[NMAX];
int p[NMAX];
int N;

void InsertSort()
{
	int i, j;
	for (i = 0; i < N - 1; ++i)
		if (p[i]>p[i + 1])
			break;
	int t = p[i + 1];
	for (j = i ; j >= 0; --j)
		if (p[j] > t)
			p[j + 1] = p[j];
		else
			break;
	p[j + 1] = t;
}

void HeapAdjust(int array[],int i,int lengthN)
{
	int child;
	int tem;
	for (; 2*i+1 < lengthN; i=child)
	{
		child = 2 * i + 1;
		if (child<lengthN-1&&p[child] < p[child + 1])
			++child;
		if (p[child] > p[i])
		{
			tem = p[child];
			p[child] = p[i];
			p[i] = tem;
		}
		else
			return;
	}
}

void HeapSort()
{
	int i;
	int tem;
	for (i = N - 1; i > 0; --i)
		if (p[i] < p[(i - 1) / 2])
			break;

	p[i] = p[i] ^ p[0];
	p[0] = p[i] ^ p[0];
	p[i] = p[i] ^ p[0];
	
	HeapAdjust(p, 0, i);
}

int main()
{
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d", n + i);
	for (i = 0; i < N; ++i)
		scanf("%d", p + i);

	for (i = 0; i < N - 1; ++i)
		if (p[i]>p[i + 1])
			break;
	for (++i; i < N; ++i)
		if (n[i] != p[i])
			break;
	if (i == N)
	{
		printf("Insertion Sort\n");
		InsertSort();
	}
	else
	{
		printf("Heap Sort\n");
		HeapSort();
	}

	for (i = 0; i < N; ++i)
		if (i == 0)
			printf("%d", p[i]);
		else
			printf(" %d", p[i]);

	return 0;
}



/* 附：堆排序算法：*/
/*
#include <stdio.h>
//array是待调整的堆数组，i是待调整的数组元素的位置，nlength是数组的长度
//本函数功能是：根据数组array构建大根堆
void HeapAdjust(int array[],int i,int nLength)
{
    int nChild;
    int nTemp;
    for(;2*i+1<nLength;i=nChild)
    {
        //子结点的位置=2*（父结点位置）+1
        nChild=2*i+1;
        //得到子结点中较大的结点
        if(nChild<nLength-1&&array[nChild+1]>array[nChild])++nChild;
        //如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
        if(array[i]<array[nChild])
        {
            nTemp=array[i];
            array[i]=array[nChild];
            array[nChild]=nTemp; 
        }
        else break; //否则退出循环
    }
}
//堆排序算法
void HeapSort(int array[],int length)
{
    int i;
    //调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
    //length/2-1是最后一个非叶节点，此处"/"为整除
    for(i=length/2-1;i>=0;--i)
    HeapAdjust(array,i,length);
    //从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for(i=length-1;i>0;--i)
    {
        //把第一个元素和当前的最后一个元素交换，
        //保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
        array[i]=array[0]^array[i];
        array[0]=array[0]^array[i];
        array[i]=array[0]^array[i];
        //不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        HeapAdjust(array,0,i);
    }
}
int main()
{
    int i;
    int num[]={9,8,7,6,5,4,3,2,1,0};
    HeapSort(num,sizeof(num)/sizeof(int));
    for(i=0;i<sizeof(num)/sizeof(int);i++)
    {
        printf("%d ",num[i]);
    }
    printf("\nok\n");
    return 0;
}
*/