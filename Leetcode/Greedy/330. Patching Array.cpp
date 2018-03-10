/*
	不错的贪心算法类题目。
	卡了两次：
	1.忘记【】空数组
	2.long long！范围。 
*/ 
class Solution {
	public:
		int minPatches(vector<int>& nums, int n) {
			long long curn=0,cnt=0;
			for(int i=0; curn<n;) {
				if(i<nums.size()&&curn+1>=nums[i])
					curn+=nums[i++];
				else {
					++cnt;
					curn=curn<<1|1;
				}
			}
			return cnt;
		}
};
