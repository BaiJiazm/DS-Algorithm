//�����Ƕ�ô��������̵�������
/*
	�߽���ԣ�
	-2147483647,0,-2147483647,2147483647
	-564
	3864
*/
/*
	����һ���㷨���Ӷ�Ϊ O��nlogn���ķ����㷨��һ��ֻ��������ʽ��
	1.T(n)=T(n-1)+O(logn)
	2.T(n)=2T(n/2)+O(n);
	һ�������������ʽ��ȥ�������ⷽ����

	��һ�ַ���һ����Ҫ���������������������������״���顢�߶�����һ��C++��multiset��multimap(���ܻ��õ�distance(begin,end)���������)

	���ڶ��ֵ�����ĳ�������ϵ����Χ��ϵʱ���鲢�����������һ�־���˼�롣
	�����������򣬿��Գ���ھ��������ʣ��Ӷ����ټ��㣬ʹ����O(n)ʱ�����ܴ������еõ��𰸡�

	�����	315. Count of Smaller Numbers After Self �� 493. Reverse Pairs ˼��һ�¡�
	���Ǳ��⻹�����ܴ�����ͷ�Χ���뵽sum������ͬʱע������д����
	����ע�⣺����ķ�ΧӦ����long long��
*/

//˼·һ��
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

//˼·����
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
			return countRange(sum,lower,upper,0,sum.size());	//����Ϊʲô��
		}
};
