#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>tm;
vector<vector<int>>tree;
long long ans=0;

int traverse(int r){
	if(tree[r].empty())
		return tm[r];
	vector<int>t;
	for(int i=0;i<tree[r].size();++i){
		t.push_back(traverse(tree[r][i]));
	}
	int maxtm=*max_element(t.begin(), t.end());
	for(auto &a:t){
		ans+=maxtm-a;
	}
	return maxtm+tm[r];
}

int main(){
	int N;
	while(cin>>N){
		ans=0;
		tree.resize(N+1); 
		tm.resize(N+1);
		vector<bool>isRoot(N+1,true);
		int i,a,b;
		int mint=0;
		for(i=1;i<=N;++i)
			cin>>tm[i];
		for(i=1;i<N;++i){
			cin>>a>>b;
			tree[a].push_back(b);
			isRoot[b]=false;
		}
		for(i=1;i<=N&&!isRoot[i];++i)
			;
		traverse(i);
		cout<<ans<<endl;
	}
	return 0;
}
