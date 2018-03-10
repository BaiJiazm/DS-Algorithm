#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//����һ������set�ȼ�¼ĳ��λ���Ѿ��ù���Ԫ�أ������ظ���Ч�ʽϵͣ������ܹ���
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
			unordered_set<int>s;	//ser<int>s;	���ܶ�
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

/*discuss ���ȽϺõķ�����ֵ��ѧϰ���ؼ������ִ�й��̡�
�ؼ�������vector<int>num�������ã����Կ���ֱ�������ź�������ʣ�
����ǰ����ͬʱ��λ�ó��ֵ�Ԫ�ز�ͬ��ͬʱÿ�ν��������´��ݵĶ���һ����������
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
