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

       �Է��̵Ľ��ͣ�

       ͵ǰn�����ӵ����Ž⣨��Ǯ�������������ڣ�͵ǰ(n-1)�����ӵ����Ž⡢͵ǰ(n-2)�����ӵ����Ž� + ��n�����ӵ�Ǯ��ȡ�������нϴ���Ǹ���
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
