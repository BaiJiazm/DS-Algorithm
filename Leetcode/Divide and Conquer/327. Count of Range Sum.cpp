//程序是多么优美！编程的艺术！
/*
	边界测试：
	-2147483647,0,-2147483647,2147483647
	-564
	3864
*/
/*
	对于一般算法复杂度为 O（nlogn）的分治算法，一般只有两种形式：
	1.T(n)=T(n-1)+O(logn)
	2.T(n)=2T(n/2)+O(n);
	一般从这两个递推式中去分析解题方法。

	第一种方法一般需要借助二叉搜索树、红黑树或者树状数组、线段树。一般C++用multiset、multimap(可能会用到distance(begin,end)函数求个数)

	而第二种当用于某种有序关系、范围关系时，归并排序的运用是一种经典思想。
	运用序列有序，可以充分挖掘有序性质，从而减少计算，使得在O(n)时间内能从序列中得到答案。

	本题和	315. Count of Smaller Numbers After Self 及 493. Reverse Pairs 思想一致。
	但是本题还在于能从区间和范围联想到sum方法。同时注意程序的写法。
	另外注意：区间的范围应该是long long。
*/

//思路一：
class Solution {
	public:
		int countRangeSum(vector<int>& nums, int lower, int upper) {
			multiset<long long> pSum;
			int res = 0,  i;
			long long left, right, sum=0;
			for(i=0,pSum.insert(0); i<nums.size(); ++i) {
				sum +=nums[i];
				res += std::distance(pSum.lower_bound(sum-upper), pSum.upper_bound(sum-lower));
				pSum.insert(sum);
			}
			return res;
		}
};

//思路二：
class Solution {
	public:
		int countRange(vector<long long>&sum,const int &lower,const int &upper,int begin,int end) {
			if(begin+1<end) {
				int mid=(begin+end)/2;
				int cnt=countRange(sum,lower,upper,begin,mid)+countRange(sum,lower,upper,mid,end);
				int l,r,i;
				for(l=r=mid,i=begin; i<mid; ++i) {
					while(l<end&&sum[l]-sum[i]<lower)
						++l;
					while(r<end&&sum[r]-sum[i]<=upper)
						++r;
					cnt+=r-l;
				}
				inplace_merge(sum.begin()+begin,sum.begin()+mid,sum.begin()+end);
				return cnt;
			}
			return 0;
		}
		int countRangeSum(vector<int>& nums, int lower, int upper) {
			vector<long long>sum(nums.size()+1);
			sum[0]=0;
			for (int i=0; i<nums.size(); ++i)
				sum[i+1]=sum[i]+nums[i];
			return countRange(sum,lower,upper,0,sum.size());	//想想为什么！
		}
};
