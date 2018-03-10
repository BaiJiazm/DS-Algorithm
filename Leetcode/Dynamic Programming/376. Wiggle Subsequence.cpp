#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

#include<algorithm>
#include<functional>
#include<numeric>
#include<bitset>
#include<cmath>
using namespace std;

//解法一：自己写的DP
class Solution {
	public:
		int wiggleMaxLength(vector<int>& nums) {
			int size=nums.size();
			struct node {
				int pos;
				int neg;
			};
			int ans=0;
			vector<node>dp(size, {1,1});
			int i,j;
			for (i=0; i<size; ++i) {
				for (j=0; j<=i; ++j) {
					if (nums[i]>nums[j])
						dp[i].pos=max(dp[i].pos,dp[j].neg+1);
					else if (nums[i]<nums[j])
						dp[i].neg=max(dp[i].neg,dp[j].pos+1);
				}
				ans=max(ans,max(dp[i].pos,dp[i].neg));
			}
			return ans;
		}
};

//LeetCode Discuss 贪心算法
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size=nums.size(), f=1, d=1;
        for(int i=1; i<size; ++i){
                 if(nums[i]>nums[i-1]) f=d+1;
            else if(nums[i]<nums[i-1]) d=f+1;
        }
        return min(size, max(f, d));
    }
};
