#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//	public:
//		vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
//			int mlen=nums1.size()+nums2.size();
//			vector<int>m(mlen);
//			merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),m.begin(),greater<int>());
//			vector<int>res;
//			k=mlen-k;
//			int i;
//			for(i=0; i<m.size()&&k>0; --k) {
//				while(i<m.size()&&(res.empty()||res.back()>=m[i]))
//					res.push_back(m[i++]);
//				res.pop_back();
//			}
//			res.insert(res.end(),m.begin()+i,m.end());
//			res.erase(res.end()-k,res.end());
//			return res;
//		}
//};
struct node {
	int value;
	int pos;
	int v;
};
bool cmp1(const node&n1,const node&n2) {
	return n1.value<n2.value;
}
bool cmp2(const node&n1,const node&n2) {
	return n1.pos<n2.pos;
}

class Solution {
	public:
		vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
			vector<node>m;
			vector<node>t1,t2;
			vector<int>res;
			int i,p1,p2;
			for(i=0; i<nums1.size(); ++i)
				m.push_back({nums1[i],i,1});
			for(i=0; i<nums2.size(); ++i)
				m.push_back({nums2[i],i,2});
			sort(m.begin(),m.end(),cmp1);
			for(i=m.size()-k; i<m.size(); ++i) {
				node&nd=m[i];
				if(nd.v==1)
					t1.push_back(nd);
				else
					t2.push_back(nd);
			}
			sort(t1.begin(),t1.end(),cmp2);
			sort(t2.begin(),t2.end(),cmp2);
			for(p1=p2=0; p1<t1.size()&&p2<t2.size();) {
				if(t1[p1].value>t2[p2].value)
					res.push_back(t1[p1++].value);
				else
					res.push_back(t2[p2++].value);
			}
			while(p1<t1.size())
				res.push_back(t1[p1++].value);
			while(p2<t2.size())
				res.push_back(t2[p2++].value);
			return res;
		}
};

class Solution {
	public:
		vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
			
		}
};


int main() {
	vector<int>n1= {3, 4, 6, 5};
	vector<int>n2= {9, 1, 2, 5, 8, 3};
	vector<int>n3(10);
	merge(n1.begin(),n1.end(),n2.begin(),n2.end(),n3.begin(),greater<int>());
	for(auto a:n3)
		cout<<a<<" ";
	return 0;
}
