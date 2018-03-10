#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define NMAX 1000
#define MMAX 11
#define INF 0xffffff

struct gNode {
	int order;
	int distance;
};
struct gasNode {
	int min;
	int max;
	int total;
	int order;
};
vector<list<gNode>>graph(NMAX + MMAX , list<gNode>());
vector<gasNode>gasStation;
int N, M, K,Ds;

struct gasNode dijstl(int G)
{
	struct gasNode gstation = { INF,0,0,G-NMAX };
	int dist[NMAX] = { 0 };
	int visit[NMAX] = { 0 };
	int i,j;
	for (list<gNode>::iterator iter = graph[G].begin(); iter != graph[G].end(); ++iter)
		dist[iter->order] = iter->distance;
	int min, curMin;
	for (i = 1; i <= N; ++i) {
		for (min = INF, j = 1; j<=N; ++j) 
			if (!visit[j] && dist[j] && dist[j] < min) {
				curMin = j;
				min = dist[j];
			}
		visit[curMin] = 1;
		if (min > Ds) {
			gstation.max = Ds + 1;
			return gstation;
		}
		if (min > gstation.min)
			gstation.min = min;
		gstation.total += min;
		for (list<gNode>::iterator iter = graph[curMin].begin(); iter != graph[curMin].end(); ++iter)
			if (dist[iter->order] == 0 || min + iter->distance < dist[iter->order])
				dist[iter->order] = min + iter->distance;
	}
	return gstation;
}
bool comp(const gasNode&g1, const gasNode&g2)
{
	if (g1.max > Ds || g2.max > Ds)
		return g1.max > g2.max ? false : true;
	if (g1.min != g2.min)
		return g1.min > g2.min ? true : false;
	if (g1.total != g2.total)
		return g1.total > g2.total ? false : true;
	return g1.order > g2.order ? false : true;
}
int main()
{
	scanf("%d%d%d%d", &N, &M, &K, &Ds);
	int i = K;
	while (i--) {
		string str1, str2;
		int house1, house2, dist;
		cin >> str1 >> str2 >> dist;
		if (str1[0] == 'G')
			house1 = atoi(str1.substr(1).c_str()) + NMAX;
		else
			house1 = atoi(str1.c_str());
		if (str2[0] == 'G')
			house2 = atoi(str2.substr(1).c_str()) + NMAX;
		else
			house2 = atoi(str2.c_str());
		graph[house1].push_back(gNode{ house2,dist });
		graph[house2].push_back(gNode{ house1,dist });
	}
	for (i = 1; i <= M; ++i) {
		gasStation.push_back(dijstl(NMAX + i));
	}
	sort(gasStation.begin(), gasStation.end(), comp);

	vector<gasNode>::iterator iter = gasStation.begin();
	if (iter->max > Ds)
		printf("No Solution");
	else {
		printf("G%d\n", iter->order);
		printf("%.1f %.1f", (double)iter->min, iter->total*1.0 / N);
	}
	return 0;
}

