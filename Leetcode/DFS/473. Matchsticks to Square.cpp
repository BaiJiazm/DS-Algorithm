#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

/*  自己写的，time:26ms     beats 70.11%
*/
class Solution {
	public:
		bool makesquare(vector<int>& nums) {
			if (nums.empty())
				return false;
			int sum=accumulate(nums.begin(),nums.end(),0);
			if (sum%4!=0||*max_element(nums.begin(),nums.end())>sum/4)
				return false;
			this->nums=nums;
			edgeLen=sum/4;
			used=0;
			edgeNum=0;
			len=0;
			return mksquare(0);
		}
		int edgeLen;
		int used;
		int edgeNum;
		int len;
		vector<int>nums;

		bool mksquare(int index) {
			if (edgeNum==4)
				return true;
			for(int i=index; i<nums.size(); ++i) {
				//cout<<(~((1<<i)&used))<<" ";
				//最坑之处,将按位取非操作写成了取反，
				if (!((1<<i)&used))
					if (nums[i]+len<=edgeLen) {
						used|=1<<i;
						if (nums[i]+len==edgeLen) {
							++edgeNum;
							len=0;
							if (mksquare(0))
								return true;
							len=edgeLen-nums[i];
							--edgeNum;
						} else {
							len+=nums[i];
							if (mksquare(i+1))
								return true;
							len-=nums[i];
						}
						used^=1<<i;
					}
			}
			return false;
		}
};

int main() {
	vector<int>nums= {3,3,3,3,4};
	Solution s;
	cout<<s.makesquare(nums);
	return 0;
}

/*  下面这种方法虽然代码简单，但是时间复杂度为O(4^n)    TLE错误
*/
class Solution {
		bool dfs(vector<int> &sidesLength,const vector<int> &matches, int index) {
			if (index == matches.size())
				return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
			for (int i = 0; i < 4; ++i) {
				sidesLength[i] += matches[index];
				if (dfs(sidesLength, matches, index + 1))
					return true;
				sidesLength[i] -= matches[index];
			}
			return false;
		}
	public:
		bool makesquare(vector<int>& nums) {
			if (nums.empty()) return false;
			vector<int> sidesLength(4, 0);
			return dfs(sidesLength, nums, 0);
		}
};

/*  思想同上述方法，但是做了三种不同优化，time:6ms  beats 84.45%
*/
class Solution {
		bool dfs(vector<int> &sidesLength,const vector<int> &matches, int index, const int target) {
			if (index == matches.size())
				return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
			for (int i = 0; i < 4; ++i) {
				if (sidesLength[i] + matches[index] > target) // first
					continue;
				int j = i;
				while (--j >= 0) // third
					if (sidesLength[i] == sidesLength[j])
						break;
				if (j != -1) continue;
				sidesLength[i] += matches[index];
				if (dfs(sidesLength, matches, index + 1, target))
					return true;
				sidesLength[i] -= matches[index];
			}
			return false;
		}
	public:
		bool makesquare(vector<int>& nums) {
			if (nums.size() < 4) return false;
			int sum = 0;
			for (const int val: nums) {
				sum += val;
			}
			if (sum % 4 != 0) return false;
			sort(nums.begin(), nums.end(), [](const int &l, const int &r) {
				return l > r;
			}); // second
			vector<int> sidesLength(4, 0);
			return dfs(sidesLength, nums, 0, sum / 4);
		}
};
