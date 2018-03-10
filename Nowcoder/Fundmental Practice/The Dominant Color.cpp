#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
using namespace std;

int main()
{
	int N, M;
	while (scanf("%d %d", &N, &M) != EOF) {
		map<int, int>m;
		map<int, int>::iterator iter;

		int i, pixValue;
		int totalPix = N*M;
		for (i = totalPix; i--;) {
			scanf("%d", &pixValue);
			if ((iter = m.find(pixValue)) == m.end())
				m[pixValue] = 1;
			else
				++iter->second;
		}
		
		int half = totalPix / 2;
		for (iter = m.begin(); iter != m.end(); ++iter)
			if (iter->second > half)
				break;
		printf("%d\n", iter->first);
	}
	return 0;
}