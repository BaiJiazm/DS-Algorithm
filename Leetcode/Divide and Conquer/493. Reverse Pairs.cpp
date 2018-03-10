/*
	分治法的一般分析方法：一般能用分治在有效时间内解决问题的不会超过O（nlogn） 的算法复杂度，
	也即：T（n)=T（n/2）+O（kn） （k是常数） ，从这个角度分析转换问题是一个突破口。
*/
class Solution {
	public:
		int sort_and_count(vector<int>::iterator left,vector<int>::iterator right) {
			if(right-left<=1)
				return 0;
			vector<int>::iterator mid=left+(right -left)/2;
			int count=sort_and_count(left,mid)+sort_and_count(mid,right);
			for(vector<int>::iterator i=left,j=mid; i!=mid; ++i) {
				while(j!=right&&*i>2L**j)
					++j;
				count+=j-mid;
			}
			inplace_merge(left,mid,right);
			return count;
		}
		int reversePairs(vector<int>& nums) {
			return sort_and_count(nums.begin(),nums.end());
		}
};

//树状数组解法：先排序然后扫描原数组，二分查找离散化后的树状数组的位置，求数，更新，注意数的边界溢出用long long 范围 
class Solution {
	public:
		int reversePairs(vector<int>& nums) {
			vector<int>cp(nums),BIT(nums.size()+1,0);
			sort(cp.begin(),cp.end());
			int ans=0,x;
			for(int i=0; i<nums.size(); ++i) {
				long long tn=nums[i]*2L+1;
				if(tn<=INT_MAX) {
					x=binarySearch(cp,tn);
					ans+=i-getSum(BIT,x);
				}
				x=binarySearch(cp,nums[i]);
				updateBIT(BIT,x+1,1);
			}
			return ans;
		}
		void updateBIT(vector<int>&BIT,int x,int add) {
			while(x<BIT.size()) {
				BIT[x]+=add;
				x+=x&(-x);
			}
		}
		int getSum(vector<int>&BIT,int x) {
			int sum=0;
			while(x>0) {
				sum+=BIT[x];
				x-=x&(-x);
			}
			return sum;
		}
		int binarySearch(vector<int>&v,long long n) {
			int l=0;
			int r=v.size()-1;
			int m;
			while(l<=r) {
				m=(l+r)>>1;
				if(v[m]>=n)
					r=m-1;
				else
					l=m+1;
			}
			return l;
		}
};
