#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int N;
	while(cin>>N){
		vector<int>n(N);
		int i;
		for(i=0;i<N;++i)
			cin>>n[i];
		sort(n.begin(),n.end());
		int ans=0,sum=0;
		for (i=0;i<N;++i){
			sum+=n[i];
			ans+=sum;
		}
		cout<<ans;	
	}
	return 0;
}
