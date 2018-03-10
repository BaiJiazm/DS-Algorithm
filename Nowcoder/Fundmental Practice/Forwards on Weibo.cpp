/* 我写的----最好方法 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define NMAX 1000

vector<vector<int>>m(NMAX + 1, vector<int>());
int N;
int Level;
int visits;
bool visit[NMAX + 1];

void BFS(int start)
{
	queue<int>q;
	queue<int>qt;
	int lev = 0;
	visit[start] = true;
	visits = 0;
	q.push(start);

	int tem;
	while (lev < Level)
	{
		while (!q.empty())
		{
			tem = q.front();
			q.pop();
			for (int i = 0; i < m[tem].size(); ++i)
			{
				int j = m[tem][i];
				if (!visit[j])
				{
					++visits;
					visit[j] = true;
					qt.push(j);
				}
			}
		}
		q = qt;
		++lev;
	}
}


int main() 
{
	scanf("%d%d", &N, &Level);

	int i, j, n, k;
	for (i = 1; i <= N; ++i)
	{
		scanf("%d", &n);
		for (j = n; j--;)
		{
			scanf("%d", &k);
			m[k].push_back(i);
		}
	}

	scanf("%d", &i);
	while (i--)
	{
		scanf("%d", &j);
		memset(visit, false, sizeof(visit));
		
		BFS(j);
		printf("%d\n", visits);
	}

	return 0;
}

*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > graph;
vector<int> visited;
int N, M;
int maxLevel;
int K, num;

int BFS(int source) {
	for (int i = 0; i <= N; i++)
		visited[i] = false;
	queue<int> q;
	q.push(source);
	int level = 0, last = source, tail = source;
	visited[source] = true;
	int cnt = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < graph[v].size(); i++) {
			int w = graph[v][i];
			if (visited[w]) continue;
			q.push(w);
			tail = w;
			visited[w] = true;
		}
		if (level >= 1 && level <= maxLevel) {
			cnt++;
		}
		if (v == last) {
			level++;
			last = tail;
		}

		if (level > maxLevel) break;
	}

	return cnt;

}

int main()
{
	cin >> N >> maxLevel;
	graph.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &M);
		for (int j = 0; j < M; j++) {
			scanf("%d", &num);
			graph[num].push_back(i);
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		scanf("%d", &num);
		cout << BFS(num) << endl;
	}

	return 0;
}
