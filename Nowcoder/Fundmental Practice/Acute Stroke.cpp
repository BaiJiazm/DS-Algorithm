/* 非常好的方法----广度优先搜索*/
/*
#include <iostream>
#include <queue>

using namespace std;

#define LMAX 60
#define MMAX 1280
#define NMAX 128

int matrix[LMAX][MMAX][NMAX];
int M, N, L, T, total = 0;

int xd[] = { 1,-1,0,0,0,0 };
int yd[] = { 0,0,1,-1,0,0 };
int zd[] = { 0,0,0,0,1,-1 };

class node
{
public :
	int x, y, z;
	node(int _x, int _y, int _z) :x(_x), y(_y), z(_z){
	}
};

void bfs(int x, int y, int z)
{
	if (matrix[x][y][z] == 0)
		return;

	queue<node>que;
	int volumn = 1;
	que.push(node(x, y, z));
	matrix[x][y][z] = 0;

	int i;
	while (!que.empty())
	{
		node tem = que.front();
		que.pop();
		for (i = 0; i < 6; ++i)
		{
			int tx = tem.x + xd[i];
			int ty = tem.y + yd[i];
			int tz = tem.z + zd[i];
			if (tx >= 0 && tx < L&&ty >= 0 && ty < M&&tz >= 0 && tz < N&&matrix[tx][ty][tz])
			{
				++volumn;
				matrix[tx][ty][tz] = 0;
				que.push(node(tx, ty, tz));
			}
		}
	}
	if (volumn >= T)
		total += volumn;
}

int main()
{
	scanf("%d%d%d%d", &M, &N, &L, &T);

	int i, j, k;
	for (k = 0; k < L; ++k)
		for (j = 0; j < M; ++j)
			for (i = 0; i < N; ++i)
				scanf("%d", matrix[k][j] + i);

	for (k = 0; k < L; ++k)
		for (j = 0; j < M; ++j)
			for (i = 0; i < N; ++i)
				bfs(k, j, i);

	printf("%d", total);
	return 0;
}
*/


/* 深度优先搜索----在数据规模一定情况下正确，过多会造成函数调用过多，堆栈溢出*/
/* 
#include <iostream>

using namespace std;

#define LMAX 60
#define MMAX 1280
#define NMAX 128

int matrix[LMAX][MMAX][NMAX];
int M, N, L, T, total = 0, volumn;

int xd[] = { 1,-1,0,0,0,0 };
int yd[] = { 0,0,1,-1,0,0 };
int zd[] = { 0,0,0,0,1,-1 };

void dfs(int x, int y, int z)
{
	++volumn;
	matrix[x][y][z] = 0;

	int i;
	for (i = 0; i < 6; ++i)
	{
		int tx = x + xd[i];
		int ty = y + yd[i];
		int tz = z + zd[i];
		if (tx >= 0 && tx < L&&ty >= 0 && ty < M&&tz >= 0 && tz < N&&matrix[tx][ty][tz])
			dfs(tx, ty, tz);
	}
}

int main()
{
	scanf("%d%d%d%d", &M, &N, &L, &T);

	int i, j, k;
	for (k = 0; k < L; ++k)
		for (j = 0; j < M; ++j)
			for (i = 0; i < N; ++i)
				scanf("%d", matrix[k][j] + i);

	for (k = 0; k < L; ++k)
		for (j = 0; j < M; ++j)
			for (i = 0; i < N; ++i)
				if (matrix[k][j][i])
				{
					volumn = 0;
					dfs(k, j, i);
					if (volumn >= T)
						total += volumn;
				}

	printf("%d", total);
	return 0;
}
*/