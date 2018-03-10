//ºìºÚÊ÷	 46ms
class Solution {
	public:
		int subarraySum(vector<int>& nums, int k) {
			int cum=0; // cumulated sum
			map<int,int> rec; // prefix sum recorder
			int cnt = 0; // number of found subarray
			rec[0]++; // to take into account those subarrays that begin with index 0
			for(int i=0; i<nums.size(); i++) {
				cum += nums[i];
				cnt += rec[cum-k];
				rec[cum]++;
			}
			return cnt;
		}
};

//hash·½·¨	 39ms
class Solution {
	public:
		int subarraySum(vector<int>& nums, int k) {
			unordered_map<int, int> umap;
			int size = (int)nums.size(), prev = 0, ans = 0;
			for (int i=0; i<size; ++i) {
				++umap[prev];
				prev += nums[i];
				int target = prev - k;
				ans += umap[target];
			}
			return ans;
		}
};
