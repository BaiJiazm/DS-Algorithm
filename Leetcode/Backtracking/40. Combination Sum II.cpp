//�����Ǵ���ģ�����д�����Խ��⣬����Ҫ����һ�¡� ���ظ���Ԫ�����μ���0~n�������еݹ顣 
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

//��һ����ȷд���� 
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
