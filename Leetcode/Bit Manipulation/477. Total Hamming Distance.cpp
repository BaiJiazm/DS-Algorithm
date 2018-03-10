/*
    ��������⣬�뵱Ȼ��O(n^2)����������������10000�����Ի�TLE
    ͨ���۲죬������ѧ��Ͽ��ٽ������֮��answer
*/
class Solution {
	public:
		int totalHammingDistance(vector<int>& nums) {
			int result = 0, oneCount = 0, len = nums.size();
			for (int i = 0; i < 32; i++) {
				oneCount = 0;
				for (int j = 0; j < len; j++) {
					if ((nums[j] & 1) != 0)
						oneCount++;
					nums[j] >>= 1;
				}
				result += (oneCount * (len - oneCount));
			}
			return result;
		}
};
