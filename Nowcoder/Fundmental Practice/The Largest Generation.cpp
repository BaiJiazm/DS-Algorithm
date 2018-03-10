#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define NMAX 101

vector<vector<int>>root(NMAX, vector<int>());
int theGeneration;
int maxPopulation = 0;

void BFS()
{
	queue<int >que1;
	queue<int >que2;
	int generation = 0;
	que1.push(1);

	int i;
	while (!que1.empty() || !que2.empty())
	{
		if (!que1.empty())
		{
			++generation;
			if (que1.size() > maxPopulation)
			{
				maxPopulation = que1.size();
				theGeneration = generation;
			}
			while (!que1.empty())
			{
				int tr = que1.front();
				que1.pop();
				for (i = 0; i<root[tr].size(); ++i)
					que2.push(root[tr][i]);
			}
		}
		if (!que2.empty())
		{
			++generation;
			if (que2.size() > maxPopulation)
			{
				maxPopulation = que2.size();
				theGeneration = generation;
			}
			while (!que2.empty())
			{
				int tr = que2.front();
				que2.pop();
				for (i = 0; i<root[tr].size(); ++i)
					que1.push(root[tr][i]);
			}
		}
	}
}

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	int rootN, childN, child;
	int i, j;
	for (i = 0; i < M; ++i)
	{
		scanf("%d%d", &rootN, &childN);
		for (j = 0; j < childN; ++j)
		{
			scanf("%d", &child);
			root[rootN].push_back(child);
		}
	}

	BFS();
	printf("%d %d", maxPopulation, theGeneration);

	return 0;
}