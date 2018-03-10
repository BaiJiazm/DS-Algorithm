#include <iostream>
using namespace std;


#define NMAX 501
#define INF 0x0fffff

int map[NMAX][NMAX];
int road[NMAX];
int s[NMAX];
int ssent[NMAX];
int sback[NMAX];

int Cmax;
int Sp;
int N;
int M;

void ShortestRoad()
{
	int visit[NMAX];
	int distance[NMAX];
	int Chalf = Cmax / 2;

	int i;
	for (i = 0; i <= N; ++i)
	{
		visit[i] = 0;
		distance[i] = INF;
	}

	ssent[0] = 0;
	road[0] = -1;
	distance[0] = 0;
	sback[0] = 0;

	int s1, s2, value;
	int t;
	for (i = 0; i < N; ++i)
	{
		for (value = INF, s1 = 0; s1 <= N; ++s1)
			if (!visit[s1] && distance[s1] < value)
			{
				value = distance[s1];
				s2 = s1;
			}

		visit[s2] = 1;
		if (s2 == Sp)
			return;
		for (s1 = 1; s1 <= N; ++s1)
			if (!visit[s1])
			{
				t = s[s1] + sback[s2] - Chalf;
				if (value + map[s2][s1] < distance[s1])
				{
					distance[s1] = map[s2][s1] + value;
					road[s1] = s2;
					ssent[s1] = ssent[s2] + (t >= 0 ? 0 : -t);
					sback[s1] = t >= 0 ? t : 0;
				}
				else if (value + map[s2][s1] == distance[s1] && ssent[s1] > ssent[s2] + (t >= 0 ? 0 : -t))
				{
					road[s1] = s2;
					ssent[s1] = ssent[s2] + (t >= 0 ? 0 : -t);
					sback[s1] = t >= 0 ? t : 0;
				}
			}
	}
}

void OutPutRoad(int s)
{
	if (s == -1)
		return;
	OutPutRoad(road[s]);

	cout << s << "->";
}
int main()
{
	cin >> Cmax >> N >> Sp >> M;

	int i, j, s1, s2, value;
	for (i = 1; i <= N; ++i)
		cin >> s[i];
	for (i = 0; i <= N; ++i)
		for (j = 0; j <= N; ++j)
			map[i][j] = INF;

	for (i = 0; i < M; ++i)
	{
		cin >> s1 >> s2 >> value;
		map[s1][s2] = map[s2][s1] = value;
	}

	ShortestRoad();

	cout << ssent[Sp] << ' ' ;
	OutPutRoad(road[Sp]);
	cout << Sp<<' '<<sback[Sp];

	return 0;
}
