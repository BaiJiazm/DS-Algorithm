/* ********************************
题目来源：网易2018校园招聘
https://www.nowcoder.com/question/next?pid=6910869&qid=126949&tid=11621771

* ********************************/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void solve(int n, string &str){
	if(n<=0)
		return ;
	if(n&1)	{
		str.push_back('1');
		solve(n>>1, str);
	}
	else {
		str.push_back('2');
		solve((n>>1)-1, str);
	}
	return ;
}

int main(){
	int n;
	while(cin>>n){
		string str="";
		solve(n, str);
		reverse(str.begin(), str.end());
		cout<<str<<endl;
	}
	return 0;
}
