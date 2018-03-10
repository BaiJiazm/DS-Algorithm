/*
    解法一；BFS     time:26ms   拓扑排序
    采用利用	入度    拆边方法+栈结构
*/
class Solution {
	public:
		vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
			vector<int> degrees = compute_indegree(graph);
			vector<int>ans;
			for (int i = 0; i < numCourses; i++) {
				int j = 0;
				for (; j < numCourses; j++) //此处用栈更好，不必暴力遍历
					if (!degrees[j]) break;
				if (j == numCourses) return {};
				degrees[j] = -1;
				ans.push_back(j);
				for (int neigh : graph[j])
					degrees[neigh]--;
			}
			return ans;
		}
	private:
		vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<unordered_set<int>> graph(numCourses);
			for (auto pre : prerequisites)
				graph[pre.second].insert(pre.first);
			return graph;
		}
		vector<int> compute_indegree(vector<unordered_set<int>>& graph) {
			vector<int> degrees(graph.size(), 0);
			for (auto neighbors : graph)
				for (int neigh : neighbors)
					degrees[neigh]++;
			return degrees;
		}
};

/*
    解法二；DFS     time:16ms   拓扑排序=DFS的逆序列
*/
class Solution {
	public:
		vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
			vector<int> toposort;
			vector<bool> onpath(numCourses, false), visited(numCourses, false);
			for (int i = 0; i < numCourses; i++)
				if (!visited[i] && dfs(graph, i, onpath, visited, toposort))
					return {};
			reverse(toposort.begin(), toposort.end());
			return toposort;
		}
	private:
		vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<unordered_set<int>> graph(numCourses);
			for (auto pre : prerequisites)
				graph[pre.second].insert(pre.first);
			return graph;
		}
		bool dfs(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort) {
			if (visited[node]) return false;
			onpath[node] = visited[node] = true;
			for (int neigh : graph[node])
				if (onpath[neigh] || dfs(graph, neigh, onpath, visited, toposort))
					return true;
			toposort.push_back(node);
			return onpath[node] = false;
		}
};
