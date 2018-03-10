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

/* ������������	��ֵ���ж����������ȽϾ��ʣ�
	�ο����ӣ�https://all4win78.wordpress.com/
			UB (upper bound) ������ԭarray���������ֵĺͣ�
			LB (lower bound) ��UB/m�����������ֵ����֮��Ľϴ��ߡ�
			Ȼ�����binary search�ķ�ʽȥ��֤������array�ܷ��������largest sum���зָ
			��Ҫע����ǣ�����sum��Ҫʹ��long������int����Ȼ����overflow�����⡣
			ʱ�临�Ӷ���O(n log sum) <= O(n log n*Integer.MAX_VALUE) <= O(n (logn + c)) = O(n logn)������Ŀռ临�Ӷ�ΪO(1)��
	Java���룺
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

	��ο���https://www.deadend.me/2016/12/22/split-array-largest-sum/
	���ַ�ʹ�õ����������������ռ䣬���ַ�����Ҫ˼�������������ռ�������ԣ�������С����Ŀ��ֵ�Ŀռ䡣�ռ����С���������������ֵ��
	�����������ֲ����㷨�У���������ֵ����ӳ���ϵ��ͨ���޸�������Χ��С��Χ��
	��һ�ֶ��ַ���Ӧ���ǻ�����ֵ��ֱ����С��Χ��ʵ���Ͽ������Ϊ����������ֻ����������ֵǡ����ȣ�������Ŀʹ�õ��Ǻ��ߣ�����Ŀ�����ת��Ϊ�жϡ�
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