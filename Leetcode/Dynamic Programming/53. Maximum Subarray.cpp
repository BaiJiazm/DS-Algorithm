class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			int maxSum=INT_MIN,tmpSum=0;
			for(int i=0; i<nums.size(); i++) {
				tmpSum=max(tmpSum+nums[i],nums[i]);//�����ۼ�ʱ���������
				maxSum=max(maxSum,tmpSum);//�������ֵ
			}
			return maxSum;
		}
};
