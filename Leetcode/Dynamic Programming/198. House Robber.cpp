class Solution {
	public:
		int rob(vector<int>& nums) {
			int size=nums.size();
			if(size<=0)
				return 0;
			vector<int> stole(size,0);
			vector<int> notStole(size,0);
			stole[0]=nums[0];
			for (int i=1; i<size; ++i) {
				stole[i]=notStole[i-1]+nums[i];
				notStole[i]=max(stole[i-1],notStole[i-1]);
			}
			return max(stole[size-1],notStole[size-1]);
		}
};

/*
f(n) = max( f(n-1), nums[n-1] + f(n-2) )

       对方程的解释：

       偷前n个房子的最优解（即钱的总数），等于：偷前(n-1)个房子的最优解、偷前(n-2)个房子的最优解 + 第n个房子的钱，取这两者中较大的那个。
*/
class Solution {
	public:
		int rob(vector<int>& nums) {
			if (nums.size() == 0)
				return 0;
			if (nums.size() == 1)
				return nums[0];
			vector<int> f(nums.size() + 1);
			f[0] = 0;
			f[1] = nums[0];
			for (int i = 2, size = nums.size(); i <= size; ++i) {
				f[i] = max(f[i - 1],nums[i - 1] + f[i - 2]);
			}
			return f[nums.size()];
		}
};
