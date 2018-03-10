class Solution {
	public:
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			vector<vector<int>>ans;
			vector<int>path;
			sort(nums.begin(),nums.end());
			solve(ans,nums,path,0);
			return ans;
		}
		void solve(vector<vector<int>>&ans,vector<int>&nums,vector<int>&path,int index) {
			if (index>=nums.size()) {
				ans.push_back(path);
				return ;
			}
			for(int i=index; i<nums.size(); ++i)
				if(i==index||nums[i]!=nums[i-1]) {
					path.push_back(nums[i]);
					solve(ans,nums,path,i+1);
					path.pop_back();
				}
			solve(ans,nums,path,nums.size());
		}
};

/*������޸�д��������������� 39. Combination Sum/40. Combination Sum II,46. Permutations/47. Permutations II��һ�����͵���Ŀ�����ǻ�����һ�����
����ǰ���ĵ���Ŀ��������·��һ���ģ����ǿ����˶Խ����˼����ǰ�����ߵļ�¼�𰸵Ĵ��������Ǵﵽ���ֵ������ͬ�Ӽ���¼�����ÿ�ξ��Ǵ𰸡� 
*/ 
class Solution {
	public:
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			vector<vector<int>>ans;
			vector<int>path;
			sort(nums.begin(),nums.end());
			solve(ans,nums,path,0);
			return ans;
		}
		void solve(vector<vector<int>>&ans,vector<int>&nums,vector<int>&path,int index) {
			ans.push_back(path);
			for(int i=index; i<nums.size(); ++i)
				if(i==index||nums[i]!=nums[i-1]) {
					path.push_back(nums[i]);
					solve(ans,nums,path,i+1);
					path.pop_back();
				}
		}
};
