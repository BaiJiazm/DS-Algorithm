#include<iostream>
#include<vector> 
using namespace std;
class NumArray {
	public:
		NumArray(vector<int> nums) {
			n=nums.size();
			a.assign(n+1,0);
			for(int i=0; i<nums.size(); ++i)
				update(i,nums[i]);
		}

		void update(int xx, int val) {
			int x=xx+1;
			int add=val-getsum(x)+getsum(x-1);
			while(x<=n) {
				a[x]+=add;
				x+=lowbit(x);
			}
		}

		int sumRange(int i, int j) {
			return getsum(j+1)-getsum(i);
		}
		vector<int>a;
		int n;
		int lowbit(int x) {
			return x&(-x);
		}
		int getsum(int x) {
			int sum=0;
			while(x>0) {
				sum+=a[x];
				x-=lowbit(x);
			}
			return sum;
		}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
 
int main(){
	vector<int>n(3);
	n[0]=1;n[1]=3;n[2]=5;
	NumArray s(n);
	cout<<s.a[0]<<s.a[1]<<s.a[2]<<s.a[3]<<endl;
	cout<<s.sumRange(0,2);
	return 0;
}
