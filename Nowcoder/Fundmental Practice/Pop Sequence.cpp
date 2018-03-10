#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stack>
using namespace std;

#define MAX 1000

int main()
{
	int maxSize, N, K;
	int elem;
	int sequence[MAX + 1];

	while (scanf("%d %d %d", &maxSize, &N, &K) != EOF) {
		while (K--) {
			stack<int>s;
			int i;
			for (i = 1; i <= N; ++i)
				scanf("%d", sequence + i);

			for (i = 1, elem = 0; i <= N; ++i) {
				if (elem < sequence[i]) {
					while (++elem < sequence[i])
						s.push(elem);
					if ((int)s.size() >= maxSize)
						break;
				}
				else if (s.top() != sequence[i])
					break;
				else
					s.pop();
			}
			printf("%s\n", s.empty() ? "YES" : "NO");
		}
	}
	return 0;
}