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



/* �����������㷨��*/
/*
#include <stdio.h>
//array�Ǵ������Ķ����飬i�Ǵ�����������Ԫ�ص�λ�ã�nlength������ĳ���
//�����������ǣ���������array���������
void HeapAdjust(int array[],int i,int nLength)
{
    int nChild;
    int nTemp;
    for(;2*i+1<nLength;i=nChild)
    {
        //�ӽ���λ��=2*�������λ�ã�+1
        nChild=2*i+1;
        //�õ��ӽ���нϴ�Ľ��
        if(nChild<nLength-1&&array[nChild+1]>array[nChild])++nChild;
        //����ϴ���ӽ����ڸ������ô�ѽϴ���ӽ�������ƶ����滻���ĸ����
        if(array[i]<array[nChild])
        {
            nTemp=array[i];
            array[i]=array[nChild];
            array[nChild]=nTemp; 
        }
        else break; //�����˳�ѭ��
    }
}
//�������㷨
void HeapSort(int array[],int length)
{
    int i;
    //�������е�ǰ�벿��Ԫ�أ�������֮���һ��Ԫ�������е�����Ԫ��
    //length/2-1�����һ����Ҷ�ڵ㣬�˴�"/"Ϊ����
    for(i=length/2-1;i>=0;--i)
    HeapAdjust(array,i,length);
    //�����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
    for(i=length-1;i>0;--i)
    {
        //�ѵ�һ��Ԫ�غ͵�ǰ�����һ��Ԫ�ؽ�����
        //��֤��ǰ�����һ��λ�õ�Ԫ�ض��������ڵ��������֮������
        array[i]=array[0]^array[i];
        array[0]=array[0]^array[i];
        array[i]=array[0]^array[i];
        //������С����heap�ķ�Χ��ÿһ�ε�����ϱ�֤��һ��Ԫ���ǵ�ǰ���е����ֵ
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