#include <iostream>
#include <vector>
using namespace std;

long long ans=0;
int n,m;

void solve(vector<int>&v, int pos);
void solve2(vector<int>&v1, vector<int>&v0, int pos);

void divide(vector<int>&v, vector<int>&v0, vector<int>&v1, int pos) {
	for(auto &a:v) {
		if(a&1<<pos) {
			v1.push_back(a);
		} else {
			v0.push_back(a);
		}
	}
}

void solve(vector<int>&v, int pos) {
	if(pos<0||v.size()==0) {
		return;
	}

	vector<int>v0, v1;
	divide(v, v0, v1, pos);
	int mbit=m&1<<pos;
	if(!mbit) {
		ans+=v0.size()*v1.size();
		solve(v0, pos-1);
		solve(v1, pos-1);
	} else {
		return solve2(v1, v0, pos-1);
	}
}

void solve2(vector<int>&v1, vector<int>&v0, int pos) {
	if(pos<0||v1.empty()||v0.empty()) {
		return;
	}

	vector<int>v00, v01, v10, v11;
	divide(v0, v00, v01, pos);
	divide(v1, v10, v11, pos);

	int mbit=m&1<<pos;
	if(!mbit) {
		ans+=v00.size()*v11.size();
		ans+=v01.size()*v10.size();
		solve2(v01, v11, pos-1);
		solve2(v00, v10, pos-1);
		return ;
	}
	solve2(v00, v11, pos-1);
	solve2(v01, v10, pos-1);
}

int main() {
	int i, t;
	while(cin>>n>>m) {
		vector<int>vec;
		ans=0;
		for(i=0; i<n; ++i) {
			cin>>t;
			vec.push_back(t);
		}
		solve(vec, 31);
		cout<<ans<<endl;
	}
	return 0;
}
