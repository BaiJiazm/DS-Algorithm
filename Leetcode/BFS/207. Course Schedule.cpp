/*
    �ⷨһ��BFS     time:19ms   ��������������
    ��������	���    ��߷���
*/
class Solution {
	public:
		bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
			vector<int> degrees = compute_indegree(graph);
			for (int i = 0; i < numCourses; i++) {
				int j = 0;
				for (; j < numCourses; j++)
					if (!degrees[j]) break;
				if (j == numCourses) return false;
				degrees[j] = -1;
				for (int neigh : graph[j])
					degrees[neigh]--;
			}
			return true;
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
    �ⷨ����DFS     time:26ms   �ؼ������ж��Ƿ������γɻ�
    ��������	����    ����
*/
class Solution {
	public:
		bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
			vector<bool> onpath(numCourses, false), visited(numCourses, false);
			for (int i = 0; i < numCourses; i++)
				if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
					return false;
			return true;
		}
	private:
		vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
			vector<unordered_set<int>> graph(numCourses);
			for (auto pre : prerequisites)
				graph[pre.second].insert(pre.first);
			return graph;
		}
		bool dfs_cycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
			if (visited[node]) return false;
			onpath[node] = visited[node] = true;
			for (int neigh : graph[node])
				if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
					return true;
			return onpath[node] = false;
		}
};
