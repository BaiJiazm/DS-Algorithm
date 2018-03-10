#include "headFile"

//经典DP问题，二分搜索将O（n^2）化为O（nlogn）
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<int>dp;
		for (auto a:nums){
			auto it=lower_bound(dp.begin(),dp.end(),a);
			if(it==dp.end())
				dp.push_back(a);
			else
				*it=a;
		}
		return dp.size();
    }
};
