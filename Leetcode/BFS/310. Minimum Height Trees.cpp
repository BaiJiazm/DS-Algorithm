#include<iostream>
#include<vector>
#include<tr1/unordered_set>
#include<algorithm>
using namespace std;
using namespace std::tr1;

class Solution {
	public:
		vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
			if (n==1)
				return vector<int>(1,0);
			vector< unordered_set<int> > graph(n);
			for(int i=0; i<edges.size(); ++i) {
				graph[edges[i].first].insert(edges[i].second);
				graph[edges[i].second].insert(edges[i].first);
			}
			vector<int>p1,p2;
			for (int i=0; i<n; ++i)
				if (graph[i].size()==1)
					p1.push_back(i);
			while(1) {
				for (int i=0; i<p1.size(); ++i)
					for (unordered_set<int>::iterator it=graph[p1[i]].begin(); it!=graph[p1[i]].end(); ++it) {
						graph[*it].erase(p1[i]);
						if (graph[*it].size()==1)
							p2.push_back(*it);
					}
				if (p2.empty())
					return p1;
				p1.clear();
				swap(p1,p2);
			}
			return {};
		}
};

int main() {
	vector<pair<int, int>>edges;
	edges.push_back({1,0});
	edges.push_back({1,2});
	edges.push_back({1,3});
	Solution s;
	s.findMinHeightTrees(4,edges);
	return 0;
}
