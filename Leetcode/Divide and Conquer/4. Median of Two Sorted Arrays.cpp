#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
	这是一道考验基本功的题目。
	要想在O(log(m+n))时间复杂度内解决问题，必然用到分治思想，也必然是递归程序。但是一开始递归函数的功能想错了，因为中位数分奇偶性 ，
	所以想写一个返回中间两个数值然后按照奇偶性判断解。但是这样写的函数代码繁杂，边界条件较多，不能有效解决题目。然后参考了discuss代码，
	将递归函数功能改为返回第k大的数字，调用两次不改变时间复杂度，易实现。
	但是如果边界条件考虑不到位还是会错。
	1.分别考虑两个有序序列前k/2个，但是可能长度没有k/2;
	2.可以假使一个长度小，另一个长。
	3.k=1情况必须要判断，否则会越界，错误。
*/
class Solution {
	public:
		int findK(vector<int>&vm,int indexm,int vmlen,vector<int>&vn,int indexn,int vnlen,int k) {
			if(vmlen>vnlen)
				return findK(vn,indexn,vnlen,vm,indexm,vmlen,k);
			if(vmlen==0)
				return vn[indexn+k-1];
			else if(k==1)
				return min(vm[indexm],vn[indexn]);
			int ml=min(k/2,vmlen);
			int nl=k-ml;
			int pm=indexm+ml-1;
			int pn=indexn+nl-1;
			if(vm[pm]==vn[pn])
				return vm[pm];
			else if(vm[pm]<vn[pn])
				return findK(vm,pm+1,vmlen-ml,vn,indexn,vnlen,k-ml);
			else
				return findK(vm,indexm,vmlen,vn,pn+1,vnlen-nl,k-nl);
		}
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int n1=nums1.size(),n2=nums2.size();
			if((n1+n2)&1)
				return findK(nums1,0,n1,nums2,0,n2,(n1+n2>>1)+1);
			else
				return (findK(nums1,0,n1,nums2,0,n2,(n1+n2>>1))+findK(nums1,0,n1,nums2,0,n2,(n1+n2>>1)+1))/2.0;;
		}
};

int main() {
	vector<int>n1= {1,3};
	vector<int>n2= {2};
	Solution s;
	cout<<s.findMedianSortedArrays(n1,n2)<<endl;
	return 0;
}
