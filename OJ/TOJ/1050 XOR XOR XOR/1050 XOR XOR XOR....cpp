#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void divide(vector<int>&v,vector<int>&v0,vector<int>&v1,int i) {
	int size=v.size();
	for (int j=0; j<size; ++j)
		if (v[j]&(1<<i))
			v1.push_back(v[j]);
		else
			v0.push_back(v[j]);
}

int oror(vector<int>&v0,vector<int>&v1,int i) {
	if (i==0)
		return v0.empty()||v1.empty()?0:1;

	vector<int>v00,v01,v11,v10;
	divide(v0,v00,v01,i-1);
	divide(v1,v10,v11,i-1);

	if (v0.empty())
		return oror(v10,v11,i-1);
	if (v1.empty())
		return oror(v00,v01,i-1);

	int ans1=0,ans2=0;
	if (!v00.empty()&&!v11.empty()||!v10.empty()&&!v01.empty()) {
		if (!v00.empty()&&!v11.empty())
			ans1=oror(v00,v11,i-1);
		if (!v10.empty()&&!v01.empty())
			ans2=oror(v10,v01,i-1);
	} else {
		vector<int>ept;
		if (!v01.empty()&&!v11.empty()) {
			v01.insert(v01.end(),v11.begin(),v11.end());
			ans1=oror(ept,v01,i-1);
		}
		if (!v00.empty()&&!v10.empty()) {
			v00.insert(v00.end(),v10.begin(),v10.end());
			ans2=oror(v00,ept,i-1);
		}
	}
	return 1<<i|max(ans1,ans2);
}

int main() {
	int N;
	while(~scanf("%d",&N)&&N) {
		vector<int>v0(N);
		vector<int>v1;
		int i;
		for (i=0; i<N; ++i)
			cin>>v0[i];
		cout<<oror(v0,v1,31)<<endl;
	}
	return 0;
}
