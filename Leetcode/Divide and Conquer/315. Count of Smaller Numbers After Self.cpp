#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main1() {
	vector<int>n= {1,2,3,3,4,5};
	cout<<lower_bound(n.begin(),n.end(),6)-n.begin()<<endl;
	cout<<*upper_bound(n.begin(),n.end(),3)<<endl;
	return 0;
}

//暴力解题，O(n^2)
class Solution1 {
	public:
		vector<int>countSmaller(vector<int>&nums) {
			vector<int>db;
			vector<int>result(nums.size());
			for(int i=nums.size()-1; i>=0; --i) {
				auto it=lower_bound(db.begin(),db.end(),nums[i]);
				result[i]=it-db.begin();
				db.insert(it,nums[i]);
			}
			return result;
		}
};

//分治法，归并排序思维。开始忽略排序后位置已经改变了，所以要记录元素位置。
class Solution {
	public:
		vector<int>result;
		struct node {
			int val;
			int pos;
			bool operator <(const node &n) const {
				return val<n.val;
			}
		};
		void divide(vector<node>::iterator left,vector<node>::iterator right) {
			if(left==right||left+1==right)
				return ;
			vector<node>::iterator mid=left+(right-left)/2;
			divide(left,mid);
			divide(mid,right);

//			cout<<"left="<<left-begin<<" mid="<<mid-begin<<" right="<<right-begin<<endl;
//			cout<<"left value: ";
//			for(vector<node>::iterator it=left; it!=mid; ++it)
//				cout<<*it<<" ";
//			cout<<"right value: ";
//			for(vector<node>::iterator it=mid; it!=right; ++it)
//				cout<<*it<<" ";
//			cout<<endl;

			for(vector<node>::iterator it=left; it!=mid; ++it) {
//				int pos=it-begin;
//				int pos2=lower_bound(mid,right,*it)-mid;
//				cout<<"pos="<<pos<<" p2="<<pos2<<endl;
//				getchar();
				result[it->pos]+=lower_bound(mid,right,*it)-mid;
			}
			inplace_merge(left,mid,right);
			return ;
		}

		vector<int>countSmaller(vector<int>&nums) {
			result.resize(nums.size(),0);
			vector<node>nd(nums.size());
			for(int i=0; i<nums.size(); ++i)
				nd[i]= {nums[i],i};
			divide(nd.begin(),nd.end());
			return result;
		}
};

int main() {
	vector<int>v= {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
	vector<int>ans;
	Solution s;
	ans=s.countSmaller(v);
	for(auto a:ans)
		cout<<a<<" ";
	cout<<endl;
	for(auto a:v)
		cout<<a<<" ";
	return 0;
}
