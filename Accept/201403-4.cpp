/*
	以下是网上答案的一种，仅仅采用广度优先搜索，虽然可以通过所有测试，但是个人认为是不对的。可能是ccf测试不完备？
	
	另解：http://blog.csdn.net/u014679804/article/details/48212851
	另解：http://blog.csdn.net/u013580497/article/details/48382733
*/
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100 + 100;

struct {
	long long x, y;
} coord[N+1];

struct node {
	long long x, y;
	int step;
};

bool visited[N+1];

int bfs(int n, int begin, int end, long long r) {
	// 变量初始化
	memset(visited, false, sizeof(visited));

	// 设置根结点
	node start, front, v;
	start.x = coord[begin].x;
	start.y = coord[begin].y;
	start.step = 0;
	queue<node> q;
	q.push(start);

	// 设置根结点为已经访问过
	visited[begin] = true;

	while(!q.empty()) {
		front = q.front();
		q.pop();

		// 到达终点则结束
		if(front.x == coord[end].x && front.y == coord[end].y)
			return front.step - 1;

		// 搜索可以连接的路由器
		for(int i=0; i<n; i++) {
			// 访问过的坐标则跳过
			if(visited[i])
				continue;

			// 判定下一个路由器的坐标是否在半径r之内, 不在半径之内则跳过，在半径之内则继续搜索
			if((front.x - coord[i].x) * (front.x - coord[i].x) + (front.y - coord[i].y) * (front.y - coord[i].y) > r * r)
				continue;
			else {
				// 第i个路由器设为已经访问过
				visited[i] = true;

				// 计算步数，并且将第i个路由器加入队列
				v.x = coord[i].x;
				v.y = coord[i].y;
				v.step = front.step + 1;
				q.push(v);
			}
		}
	}

	return 0;
}

int main() {
	int n, m, k;
	long long r;

	// 输入数据
	cin >> n >> m >> k >> r;
	for(int i=0; i<n+m; i++)       // n个路由器的位置＋可以增设的m个路由器的位置
		cin >> coord[i].x >> coord[i].y;

	// BFS
	int ans = bfs(n + m, 0, 1, r);

	// 输出结果
	cout << ans << endl;

	return 0;
}
