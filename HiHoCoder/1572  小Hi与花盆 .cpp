/*
	�����ĿӦ���㷨�����Ŀ�����Ǵ���4�Σ�ע��ϸ�ڡ�
	()&&()||()
	��Ҫԭ����������Ŀ�����ˣ� �������߼���
	��&&�ĵ�һ����������ʱ��ֱ�ӿ���||�ұ� 
	���ǵ�һ��������ȷʱ���ڶ������������Իῼ��||�ұ� 
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
			//ע�⣺it!=s.begin()&&t-*last==K+1||t-1==K		����д�Ǵ���ģ�զһ��������ȷ������&&�ĵڶ�������Ҳ���ܲ����� 
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
