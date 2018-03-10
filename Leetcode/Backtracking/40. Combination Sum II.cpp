//下面是错误的，这种写法可以解题，不过要处理一下。 将重复的元素依次加入0~n个，进行递归。 
class Solution {
	public:
		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			sort(candidates.begin(),candidates.end());
			vector<vector<int>>res;
			vector<int>path;
			dfs(res,path,candidates,target,0);
			return res;
		}
		void dfs(vector<vector<int>>&res,vector<int>&path,vector<int>&can,int target,int i) {
			if(target==0) {
				res.push_back(path);
				return ;
			} else if(i>=can.size()||target<can[i])
				return;
			path.push_back(can[i]);
			dfs(res,path,can,target-can[i],i+1);
			path.pop_back();
			dfs(res,path,can,target,i+1);
		}
};

//另一种正确写法。 
class Solution {
	public:
		vector<vector<int> > combinationSum2(vector<int> &num, int target) {
			vector<vector<int>> res;
			sort(num.begin(),num.end());
			vector<int> local;
			findCombination(res, 0, target, local, num);
			return res;
		}
		void findCombination(vector<vector<int>>& res, const int order, const int target, vector<int>& local, const vector<int>& num) {
			if(target==0) {
				res.push_back(local);
				return;
			} else {
				for(int i = order; i<num.size(); i++) { // iterative component
					if(num[i]>target) return;
					if(i&&num[i]==num[i-1]&&i>order) continue; // check duplicate combination
					local.push_back(num[i]),findCombination(res,i+1,target-num[i],local,num); // recursive componenet
					local.pop_back();
				}
			}
		}
};
