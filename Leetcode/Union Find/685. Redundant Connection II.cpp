class Solution {
	public:
		vector<vector<int>>graph;
		int start;
		vector<int>ans;

		void buildGraph(vector<vector<int>>& edges) {
			graph.clear();
			graph.resize(edges.size()+1);
			for(int i=0; i<edges.size(); ++i) {
				graph[edges[i][0]].push_back(edges[i][1]);
			}
		}

		int dfs(int u) {
			for(auto &a: graph[u]) {
				if(a==start) {
					ans.push_back(u);
					ans.push_back(a);
					return 1;
				}
				if(dfs(a))
					return 1;
			}
			return 0;
		}

		vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
			int n=edges.size();
			vector<int> inDegree(n+1, 0);
			for(int i=0; i<n; ++i) {
				if(++inDegree[edges[i][1]]>1) {
					buildGraph(edges);
					start=edges[i][1];
					if(dfs(start))
						return ans;
					return edges[i];
				}
			}

			init(n);
			for(int i=0; i<n; ++i) {
				int p=edges[i][0];
				int c=edges[i][1];
				int pFa=findFa(p);
				int cFa=findFa(c);
				if(pFa==cFa)
					return edges[i];
				fa[cFa]=pFa;
			}
			return vector<int>();
		}

		vector<int>fa;
		void init(int n) {
			fa.resize(n+1);
			for(int i=0; i<=n; ++i) {
				fa[i]=i;
			}
		}
		int findFa(int c) {
			if(fa[c]==c)
				return c;
			return fa[c]=findFa(fa[c]);
		}
};
