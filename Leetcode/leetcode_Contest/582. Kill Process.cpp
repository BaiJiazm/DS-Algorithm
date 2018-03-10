class Solution {
	public:
		unordered_map<int,int>m,um;
		vector<int>ans;
		void traverse(vector<vector<int>>&tree,int root) {
			ans.push_back(um[root]);
			for(auto &a:tree[root])
				traverse(tree,a);
		}
		vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
			for(int i=0; i<pid.size(); ++i) {
				m[pid[i]]=i+1;
				um[i+1]=pid[i];
			}
			m[0]=0;
			um[0]=0;
			vector<vector<int>>tree(pid.size()+1);
			for(int i=0; i<pid.size(); ++i)
				tree[m[ppid[i]]].push_back(m[pid[i]]);
			traverse(tree,m[kill]);
			return ans;
		}
};

class Solution {
	public:
		vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
			vector<int> killed;
			map<int, set<int>> children;
			for (int i = 0; i < pid.size(); i++) {
				children[ppid[i]].insert(pid[i]);
			}

			queue<int> q;
			q.push(kill);
			while (!q.empty()) {
				int p = q.front();
				q.pop();
				killed.push_back(p);
				for (int child : children[p]) {
					q.push(child);
				}
			}

			return killed;
		}
};
