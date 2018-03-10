/*Dijkstra，路径的花费不能有负。时间复杂度O(ElogE)
 */
 
const int maxn = 1500;
const int INF = 0x3f3f3f3f;
struct Edge {
	int from, to, dist;
};
struct HeapNode {
	int d, u;
	bool operator  < (const HeapNode & rhs) const {
		return d > rhs.d;
	}
};

struct Dijkstra {
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];	
	bool done[maxn];	//标记 
	int d[maxn];		//花费 

	void init(int n) {
		this -> n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}
	void AddEdge(int from, int to, int dist) {
		edges.push_back((Edge) {from, to, dist});
		m = edges.size();
		G[from].push_back(m-1);
	}
	void dijkstra(int s) {
		priority_queue<HeapNode> Q;
		memset(d,0x3f,sizeof(d));
		memset(done, 0, sizeof(done));
		d[s] = 0;
		Q.push((HeapNode) {0, s});
		while (!Q.empty()) {
			HeapNode x = Q.top();	Q.pop();
			int u = x.u;
			if (done[u]) continue;
			done[u] = true;
			for (int i = 0; i < (int)G[u].size(); i++) {
				Edge &e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.dist
				    	//&& d[u] + e.dist <= c	//一定注意具体题目限制 
				   ) {
					d[e.to] = d[u] + e.dist;
					//if (pp[e.to]) d[e.to] = 0;
					//p[e.to] = G[u][i];	//路径
					Q.push((HeapNode) {d[e.to], e.to});
				}
			}
		}
	}
} G, H;

int main() {
	H.init(n+1);
	G.init(n+1);
	H.AddEdge(u, v, w);
	G.AddEdge(v, u, w);
	H.dijkstra(1);
	G.dijkstra(n);
}
