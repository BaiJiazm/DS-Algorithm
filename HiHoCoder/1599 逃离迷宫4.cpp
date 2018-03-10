/*
	����һ���ǳ��õ������򷴵���Ŀ����ʼ��Ϊ�����У���������������ˣ�
	Ȼ��Ѱ�ҹ��ɣ��������������ѣ�ֻ������˼ά��
	Ҫ��õ�(a, b)��ֻ������������� 
		(a-b, b)(a>bʱ);
		(a, b-A)(a<bʱ);
	���߱ؾ���һ��
	�������˵�һ��д����a-=b,b-=a����д�������Ǽ�������϶�TLE;
	���磺x=2	y=1000009	a=2		b=1000000009	�����϶��ǿ��Եģ�����ʱ�䲻�У�
	����򵥵�ȡģ�ֻ�ܿ���ȷ�𰸡����ǵ�����ʱa>=x	b>=y�����������ֻ��ѡ����a,b��
	���������С�����һ��ֱ���жϵĹ��̣��ɿ�����⡣ 
	
	����⻹��Ҫ���ù��ɣ���÷�����ȷ���̡� 
*/
#include<iostream>
using namespace std;

int T;
int x, y, a, b;

bool solve() {
	while(a>=x&&b>=y) {
		if(x==a&&y==b)
			return true; 
		if(a>b){
			if((a-x)%b==0)
				return true;
			a%=b;
		}
		else{
			if((b-y)%a==0)
				return true;
			b%=a;
		}
	}
	return false;
}

int main() {
	cin>>T;
	while(T--) {
		cin>>x>>y>>a>>b;
		cout<<(solve()?"YES": "NO")<<endl;
	}
	return 0;
}
