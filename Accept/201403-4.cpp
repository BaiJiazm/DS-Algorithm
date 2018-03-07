/*
	���������ϴ𰸵�һ�֣��������ù��������������Ȼ����ͨ�����в��ԣ����Ǹ�����Ϊ�ǲ��Եġ�������ccf���Բ��걸��
	
	��⣺http://blog.csdn.net/u014679804/article/details/48212851
	��⣺http://blog.csdn.net/u013580497/article/details/48382733
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
	// ������ʼ��
	memset(visited, false, sizeof(visited));

	// ���ø����
	node start, front, v;
	start.x = coord[begin].x;
	start.y = coord[begin].y;
	start.step = 0;
	queue<node> q;
	q.push(start);

	// ���ø����Ϊ�Ѿ����ʹ�
	visited[begin] = true;

	while(!q.empty()) {
		front = q.front();
		q.pop();

		// �����յ������
		if(front.x == coord[end].x && front.y == coord[end].y)
			return front.step - 1;

		// �����������ӵ�·����
		for(int i=0; i<n; i++) {
			// ���ʹ�������������
			if(visited[i])
				continue;

			// �ж���һ��·�����������Ƿ��ڰ뾶r֮��, ���ڰ뾶֮�����������ڰ뾶֮�����������
			if((front.x - coord[i].x) * (front.x - coord[i].x) + (front.y - coord[i].y) * (front.y - coord[i].y) > r * r)
				continue;
			else {
				// ��i��·������Ϊ�Ѿ����ʹ�
				visited[i] = true;

				// ���㲽�������ҽ���i��·�����������
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

	// ��������
	cin >> n >> m >> k >> r;
	for(int i=0; i<n+m; i++)       // n��·������λ�ã����������m��·������λ��
		cin >> coord[i].x >> coord[i].y;

	// BFS
	int ans = bfs(n + m, 0, 1, r);

	// ������
	cout << ans << endl;

	return 0;
}
