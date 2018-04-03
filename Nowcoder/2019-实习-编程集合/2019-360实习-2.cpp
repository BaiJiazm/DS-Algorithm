#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

long long ans;
void solve(vector<long long>&v){
	sort(v.begin(), v.end());
//	cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
	if(v[0]==0){
		if(v[1]==0||v[1]+v[2]<3){
			return; 
		}
	}
	else if(v[0]==1&&v[1]==1&&v[2]==1){
		ans+=1;
		return ;
	}
	long long t=v[2]/2;
	if(t>=v[1]){
		ans+=v[1];
		v[2]-=v[1]*2;
		v[1]=0;
		solve(v);
	}
	else {
		ans+=t;
		v[2]-=t*2;
		v[1]-=t;
		solve(v);
	}
}

int main(){
	int T;
	long long r,g,b;
	cin>>T;
	while(T--){
		scanf("%lld %lld %lld", &r, &g, &b);
//		cin>>r>>g>>b;
		ans=0;
		vector<long long>v;
		v.push_back(r);
		v.push_back(g);
		v.push_back(b);
		solve(v);
		cout<<ans<<endl;
	}
	return 0;
}
