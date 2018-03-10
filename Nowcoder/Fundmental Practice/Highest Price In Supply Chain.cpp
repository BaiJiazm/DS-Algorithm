#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int treeDepth = 0;
int sumTreeDepth = 0;
void dfs(int **graph, int N,int root,int depth)
{
	if (depth > treeDepth)
	{
		treeDepth = depth;
		sumTreeDepth = 1;
	}
	else if (depth == treeDepth)
		++sumTreeDepth;

	int i;
	for (i = 0; i < N; ++i)
		if (graph[root][i])
			dfs(graph, N, i, depth + 1);
}

int main()
{
	int N;
	double P, r;
	cin >> N >> P >> r;

	int *chain = new int[N];
	int **graph = new int *[N];
	int root;

	int i, j;

	for (i = 0; i < N; ++i)
	{
		cin >> chain[i];
		if (chain[i] == -1)
			root = i;
		graph[i] = new int[N];
		for (j = 0; j < N; ++j)
			graph[i][j] = 0;
	}

	for (i = 0; i < N; ++i)
		if (i != root)
			graph[chain[i]][i] = 1;

	dfs(graph, N, root, 0);

	cout << setiosflags(ios::fixed) << setprecision(2) << P*pow(1 + r / 100, treeDepth) << " " << sumTreeDepth;

	return 0;
}


#include <iostream>  
#include <cstdio>  
#include <vector>  
#include <cmath>  

using namespace std;

vector<vector<int>> chains;
int maxLevel = 0;
int maxNum = 0;

void dfs(int src, int level) {
	if (chains[src].empty()) {
		if (maxLevel < level) {
			maxLevel = level;
			maxNum = 1;
		}
		else if (maxLevel == level) {
			maxNum++;
		}

		return;
	}

	for (auto& next : chains[src]) {
		dfs(next, level + 1);
	}
}

int main() {
	int n;
	double p, r;
	cin >> n >> p >> r;

	chains.resize(n, vector<int>());
	int root = -1;
	for (int i = 0; i < n; ++i) {
		int s;
		scanf("%d", &s);
		if (s == -1) root = i;
		else chains[s].push_back(i);
	}

	dfs(root, 0);
	printf("%.2f %d", p * pow(1 + r / 100, maxLevel), maxNum);

	return 0;
}