#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
	����һ���������������Ŀ��
	Ҫ����O(log(m+n))ʱ�临�Ӷ��ڽ�����⣬��Ȼ�õ�����˼�룬Ҳ��Ȼ�ǵݹ���򡣵���һ��ʼ�ݹ麯���Ĺ�������ˣ���Ϊ��λ������ż�� ��
	������дһ�������м�������ֵȻ������ż���жϽ⡣��������д�ĺ������뷱�ӣ��߽������϶࣬������Ч�����Ŀ��Ȼ��ο���discuss���룬
	���ݹ麯�����ܸ�Ϊ���ص�k������֣��������β��ı�ʱ�临�Ӷȣ���ʵ�֡�
	��������߽��������ǲ���λ���ǻ��
	1.�ֱ���������������ǰk/2�������ǿ��ܳ���û��k/2;
	2.���Լ�ʹһ������С����һ������
	3.k=1�������Ҫ�жϣ������Խ�磬����
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
