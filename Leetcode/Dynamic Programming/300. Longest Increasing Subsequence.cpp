#include "headFile"

//����DP���⣬����������O��n^2����ΪO��nlogn��
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
