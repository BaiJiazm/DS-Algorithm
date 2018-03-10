/*
*	题目：给定一个数字集合及目标数字，找到所有情况使集合数字组成目标数字，同一数字可以使用多次。 
*/ 
class Solution {
	public:
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			sort(candidates.begin(),candidates.end());
			vector<int>noDupCan;
			int pre=-1;
			for(auto &a:candidates)
				if(a!=pre)
					noDupCan.push_back(a);
			vector<vector<int>>res;
			vector<int>path;
			dfs(noDupCan,upper_bound(noDupCan.begin(),noDupCan.end(),target)-noDupCan.begin()-1,target, res,path);
			return res;
		}
		void dfs(const vector<int>&can,int index,int target,vector<vector<int>>&res,vector<int>&path) {
			if(target==0) {
				res.push_back(path);
				return ;
			}
			if(index<0)
				return ;
			int cnt=0;
			while(target>=can[index]) {
				++cnt;
				path.push_back(can[index]);
				dfs(can,index-1,target-=can[index],res,path);
			}
			path.erase(path.end()-cnt,path.end());
			target+=cnt*can[index];
			dfs(can,index-1,target,res,path);
		}

};


class Solution {
	public:
		std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
			std::sort(candidates.begin(), candidates.end());
			std::vector<std::vector<int> > res;
			std::vector<int> combination;
			combinationSum(candidates, target, res, combination, 0);
			return res;
		}
	private:
		void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
			if (!target) {
				res.push_back(combination);
				return;
			}
			for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
				combination.push_back(candidates[i]);
				combinationSum(candidates, target - candidates[i], res, combination, i);
				combination.pop_back();
			}
		}
};
