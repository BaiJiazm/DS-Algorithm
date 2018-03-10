/*
	这道题目应该算法简答题目，但是错了4次，注意细节。
	()&&()||()
	不要原来把语言题目做多了， 不考虑逻辑。
	当&&的第一个条件错误时，直接考虑||右边 
	但是第一个条件正确时，第二个条件错误，仍会考虑||右边 
*/ 
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
//	freopen("test.txt", "r", stdin);
	int N,K;
	while(cin>>N>>K) {
		vector<int>nums(N+1);
		set<int>s;
		int i, t;
		for(i=1;i<=N;++i)
			cin>>nums[i]; 
		if(N==K) {
			cout<<0<<endl;
			continue;
		}
		for(i=1; i<=N; ++i) {
			t=nums[i];
			set<int>::iterator it=s.insert(t).first;
			set<int>::iterator last=--it;
			set<int>::iterator next=++it;
			++next;
			//注意：it!=s.begin()&&t-*last==K+1||t-1==K		这样写是错误的，咋一看好像正确，但是&&的第二个条件也可能不满足 
			if((it!=s.begin()&&t-*last==K+1)||(it==s.begin()&&t-1==K)) {
				break;
			}
			if((next!=s.end()&&*next-t==K+1)||(next==s.end()&&N-t==K)) {
				break;
			}
		}
		cout<<(i<=N?i:-1)<<endl;
	}
	return 0;
}
