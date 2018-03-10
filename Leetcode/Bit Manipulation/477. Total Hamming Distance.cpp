/*
    初看这道题，想当然的O(n^2)，但是数据量超过10000，所以会TLE
    通过观察，利用数学组合快速解决两两之间answer
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
