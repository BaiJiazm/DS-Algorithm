
/* ******************************
   尚有问题----未知
   部分正确
   日后详查
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

#define NMAX 100000
#define VALUEMAX 1000
struct node
{
	int key;
	int next;
};

struct node n[NMAX + 1];
bool b[VALUEMAX + 1] = { false };

int root, N;

void removeDup()
{
	int rtail, ntail;
	int p, tem;

	ntail = root;
	rtail = NMAX;
	b[abs(n[root].key)] = true;

	for (p = n[root].next; p != -1; p = n[p].next)
	{
		tem = abs(n[p].key);
		if (!b[tem])
		{
			b[tem] = true;
			n[ntail].next = p;
			ntail = p;
		}
		else
		{
			n[rtail].next = p;
			rtail = p;
		}
	}

	n[ntail].next = -1;
	n[rtail].next = -1;
}

void print(int rt)
{
	int addr = rt;
	while (addr != -1)
	{
		int i;
		for (i = 10000; i >= 10; i /= 10)
			if (addr / i == 0)
				printf("0");
		printf("%d %d %d\n", addr, n[addr].key, n[addr].next);
		addr = n[addr].next;
	}
}
int main()
{
	scanf("%d %d", &root, &N);

	int addr;
	while (N--)
	{
		scanf("%d", &addr);
		scanf("%d%d", &n[addr].key, &n[addr].next);
	}

	removeDup();

	print(root);
	print(n[NMAX].next);

	return 0;
}