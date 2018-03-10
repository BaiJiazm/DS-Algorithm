#define _CRT_SECURE_NO_WARNINGS

//Solution1
#include<map>
#include<iostream>
using namespace std;

int main()
{
	map<int, int>m;
	map<int, int>::iterator first, last;

	int N, M;
	scanf("%d %d", &N, &M);

	int faceValue;

	while (N--) {
		scanf("%d", &faceValue);
		first = m.find(faceValue);
		if (first == m.end())
			m[faceValue] = 1;
		else
			++first->second;
	}

	first = m.begin();
	last = m.end();
	for (--last; first != last;)
		if (first->first + last->first > M)
			--last;
		else if (first->first + last->first < M)
			++first;
		else {
			printf("%d %d", first->first, last->first);
			return 0;
		}
		
		if (first->second > 1 && first->first + last->first == M)
			printf("%d %d", first->first, last->first);
		else
			printf("No Solution");

		return 0;
}

//Solution2
//#include<iostream>  
//#include<vector>  
//#define FaceMax 1000  
//
//int main()
//{
//	int n, m;
//	while (scanf("%d%d", &n, &m) != EOF)
//	{
//		input  
//		std::vector<int> coins;
//		coins.assign(FaceMax + 1, 0);
//		while (n--)
//		{
//			int tmp;
//			scanf("%d", &tmp);
//			coins[tmp]++;
//		}
//		search  
//		bool flag = false;
//		for (int i = 1; i <= m / 2; ++i)
//		{
//			coins[i]--;
//			coins[m - i]--;
//			if (coins[i] >= 0 && coins[m - i] >= 0)
//			{
//				printf("%d %d\n", i, m - i);
//				flag = true;
//				break;
//			}
//		}
//		no solution  
//		if (!flag)
//			printf("No Solution\n");
//	}
//}
