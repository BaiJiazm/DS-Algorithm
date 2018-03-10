/* 
	麻痹，一个单词拼写错误，花了两个小时，好爽，草草草
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

#define NMAX 100010

class BIT {
	int* elem;
	int size;
public:
	BIT(int size) :size(size) {
		elem = new int[size];
		//memset(elem, 0, sizeof(int)*size);
		for (int i = 0; i<size; i++)/*还没试过用memset初始化，下次试试*/
			elem[i] = 0;
	}
	void add(int index, int value) {
		while (index < size) {
			elem[index] += value;
			index += index&-index;
		}
	}
	int getSum(int index) {
		int sum = 0;
		while (index>0) {
			sum += elem[index];
			index -= index&-index;
		}
		return sum;
	}
	int findMed(int left, int right, int k) {
		int mid;
		while (left < right) {
			mid = (left + right) / 2;
			if (getSum(mid) < k)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
	~BIT() {
		delete []elem;
	}
};
BIT bit(NMAX);

int main()
{
	int N;
	scanf("%d", &N);
	stack<int>s;

	char str[20];
	int num;
	while (N--) {
		scanf("%s", str);
		switch (str[1]) {
		case 'u':
			scanf("%d", &num);
			s.push(num);
			bit.add(num, 1);
			break;
		case 'o':
			if (s.empty())
				printf("Invalid\n");
			else {
				printf("%d\n", num = s.top());
				s.pop();
				bit.add(num, -1);
			}
			break;
		case 'e':
			if (s.empty())
				printf("Invalid\n");
			else
				printf("%d\n", bit.findMed(1, 100000, (s.size() + 1) / 2));
			break;
		}
	}
	return 0;
}


#include <cstdio>  
#include <stack>  
using namespace std;

const int _size = 100000;
const int capi = 500;
int bucket[_size / capi][capi];
int cont[_size / capi];
int getmid(int size)
{
	int ind = (size + 1) / 2, cnt = 0, i, j;
	for (i = 0; i<_size / capi; i++)
	{
		if (cnt + cont[i] >= ind)
			break;
		cnt += cont[i];
	}
	for (j = 0; j<capi; j++)
	{
		cnt += bucket[i][j];
		if (cnt >= ind)
			return j + i*capi+1;
	}
	return 0;
}

int main()
{
	int n, tmp;
	char str[10];
	scanf("%d", &n);
	stack<int> s;
	while (n--)
	{
		scanf("%s", str);
		switch (str[1])
		{
		case 'e':
		{
			if (s.empty())
				printf("Invalid\n");
			else
				printf("%d\n", getmid(s.size()));
			break;
		}
		case 'o':
		{
			if (s.empty())
				printf("Invalid\n");
			else
			{
				tmp = s.top(); s.pop();
				printf("%d\n", tmp);
				tmp--;
				bucket[tmp / capi][tmp%capi]--;
				cont[tmp / capi]--;
			}
			break;
		}
		case 'u':
		{
			scanf("%d", &tmp); s.push(tmp);
			tmp--;
			bucket[tmp / capi][tmp%capi]++;
			cont[tmp / capi]++;
		}
		break;
		}
	}
	return 0;
}