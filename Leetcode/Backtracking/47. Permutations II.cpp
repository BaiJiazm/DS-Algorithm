#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//方法一：利用set等记录某个位置已经用过的元素，避免重复，效率较低，但是能过。
class Solution1 {
	public:
		vector<vector<int>> permuteUnique(vector<int>& nums) {
			sort(nums.begin(),nums.end());
			vector<vector<int> >res;
			dfs(res,nums,0);
			return res;
		}
		void dfs(vector<vector<int>>&res,vector<int>&nums,int index) {
			if(index+1>=nums.size()) {
				res.push_back(nums);
				return ;
			}
			unordered_set<int>s;	//ser<int>s;	慢很多
			for(int i=index; i<nums.size(); ++i)
				if(s.count(nums[i])==0) {
					s.insert(nums[i]);
					swap(nums[i],nums[index]);
					dfs(res,nums,index+1);
					swap(nums[i],nums[index]);
				}
		}
};

void outNum(vector<int>&num) {
	for(auto &a:num)
		cout<<" "<<a<<" ";
	cout<<endl;
}

/*discuss 区比较好的方法。值的学习，关键是清楚执行过程。
关键点在于vector<int>num不是引用，所以可以直接利用排好序的性质，
决定前面相同时该位置出现的元素不同，同时每次交换后向下传递的都是一个有序数组
*/
class Solution {
	public:
		void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
			if (i == j-1) {
				res.push_back(num);
				return;
			}
			for (int k = i; k < j; k++) {
				if (i != k && num[i] == num[k]) continue;
				swap(num[i], num[k]);
				recursion(num, i+1, j, res);
			}
		}
		vector<vector<int> > permuteUnique(vector<int> &num) {
			sort(num.begin(), num.end());
			vector<vector<int> >res;
			recursion(num, 0, num.size(), res);
			return res;
		}
};

int main() {
	vector<int>nums= {1,1,2};
	Solution s;
	s.permuteUnique(nums);
	return 0;
}
