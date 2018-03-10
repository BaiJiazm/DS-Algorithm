/* ********************************
题目来源：网易2018校园招聘 
https://www.nowcoder.com/question/next?pid=6910869&qid=126948&tid=11621771

 
* ********************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string n1, n2;
	int t1, t2;
	while(cin>>n1){
		n2=string(n1.rbegin(), n1.rend());
		int ans=stoi(n1)+stoi(n2);
		cout<<ans<<endl;
	}
	return 0;
}
