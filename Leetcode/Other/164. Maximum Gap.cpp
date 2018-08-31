#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maximumGap(vector<int>& nums) {
			radixSort(nums);
			int ans=0;
			for(int i=1; i<nums.size(); ++i) {
				ans=max(ans, nums[i]-nums[i-1]);
			}
			return ans;
		}

		void radixSort(vector<int>& nums) {
			for(int base=1; base<=1e9; base*=10) {
				vector<int>tmp(nums.size());
				vector<int>count(10, 0);
				for(int i=0; i<nums.size(); ++i) {
					count[nums[i]/base%10]++;
				}
				for(int i=1; i<10; ++i) {
					count[i]+=count[i-1];
				}
				for(int i=nums.size(); --i>=0; ) {
					tmp[--count[nums[i]/base%10]]=nums[i];
				}
				nums=tmp;
			}
		}
};

class Solution {
	public:
		class Bucket {
			public:
				bool used = false;
				int minval = numeric_limits<int>::max();        // same as INT_MAX
				int maxval = numeric_limits<int>::min();        // same as INT_MIN
		};

		int maximumGap(vector<int>& nums) {
			if (nums.empty() || nums.size() < 2)
				return 0;

			int mini = *min_element(nums.begin(), nums.end()),
			    maxi = *max_element(nums.begin(), nums.end());

			int bucketSize = max(1, (maxi - mini) / ((int)nums.size() - 1));        // bucket size or capacity
			int bucketNum = (maxi - mini) / bucketSize + 1;                         // number of buckets
			vector<Bucket> buckets(bucketNum);

			for (auto&& num : nums) {
				int bucketIdx = (num - mini) / bucketSize;                          // locating correct bucket
				buckets[bucketIdx].used = true;
				buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval);
				buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval);
			}

			int prevBucketMax = mini, maxGap = 0;
			for (auto&& bucket : buckets) {
				if (!bucket.used)
					continue;

				maxGap = max(maxGap, bucket.minval - prevBucketMax);
				prevBucketMax = bucket.maxval;
			}

			return maxGap;
		}
};

int main() {
	vector<int> nums= {3, 6, 9, 1};
	Solution s;
	s.maximumGap(nums);
	return 0;
}
