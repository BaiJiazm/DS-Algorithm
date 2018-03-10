#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

#include<algorithm>
#include<functional>
#include<numeric>
#include<bitset>
using namespace std;

/* 二分搜索方法	按值进行二分搜索，比较精彩，
	参考链接：https://all4win78.wordpress.com/
			UB (upper bound) 是所有原array的所有数字的和，
			LB (lower bound) 是UB/m以数组中最大值两者之间的较大者。
			然后根据binary search的方式去验证给定的array能否依据这个largest sum进行分割。
			需要注意的是，这里sum需要使用long而不是int，不然会有overflow的问题。
			时间复杂度是O(n log sum) <= O(n log n*Integer.MAX_VALUE) <= O(n (logn + c)) = O(n logn)，额外的空间复杂度为O(1)。
	Java代码：
		public class Solution {
    public int splitArray(int[] nums, int m) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        long ub = 0;
        long lb = 0;
        for (int i : nums) {
            ub += i;
            lb = Math.max(lb, i);
        }
        lb = Math.max(lb, ub / m);
        while (lb < ub) {
            long mid = (ub - lb) / 2 + lb;
            if (isSplitable(nums, mid, m)) {
                ub = mid;
            } else {
                lb = mid + 1;
            }
        }
        return (int) lb;
    }
     
    private boolean isSplitable(int[] nums, long sum, int m) {
        int count = 1;
        int tempSum = 0;
        for (int i : nums) {
            tempSum += i;
            if (tempSum > sum) {
                count += 1;
                if (count > m) {
                    return false;
                }
                tempSum = i;
            }
        }
        return true;
    }

	另参考：https://www.deadend.me/2016/12/22/split-array-largest-sum/
	二分法使用的情形是有序搜索空间，二分法的主要思想是利用搜索空间的有序性，不断缩小包含目标值的空间。空间的缩小基于索引或基于数值。
	经典的数组二分查找算法中，索引与数值存在映射关系，通过修改索引范围缩小范围。
	另一种二分法的应用是基于数值，直接缩小范围（实际上可以理解为基于索引，只是索引与数值恰好相等）。此题目使用的是后者，把题目由求解转换为判断。
}
*/

class Solution {
private:
	bool doable(const vector<int>& nums, int cuts, long long max) {
		int acc = 0;
		for (auto num : nums) {
			// This step is unnecessary for this problem. I didn't discard this line because I want doable function more generalized.
			if (num > max) return false;
			else if (acc + num <= max) acc += num;
			else {
				--cuts;
				acc = num;
				if (cuts < 0) return false;
			}
		}
		return true;
	}

public:
	int splitArray(vector<int>& nums, int m) {
		long long left = 0, right = 0;
		for (auto num : nums) {
			left = max(left, (long long)num);
			right += num;
		}

		while (left < right) {
			long long mid = left + (right - left) / 2;
			if (doable(nums, m - 1, mid)) right = mid;
			else left = mid + 1;
		}
		return left;
	}
};