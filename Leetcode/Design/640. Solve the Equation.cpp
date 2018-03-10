#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
	public:
		string solveEquation(string equation) {
			unsigned int eqPos=equation.find('=');
			string pre=equation.substr(0,eqPos);
			string post=equation.substr(eqPos+1);
			if(pre.front()!='-')
				pre.insert(0,"+");
			if(post.front()!='-')
				post.insert(0,"+");
			int preCst,preCoe;
			int postCst,postCoe;
			parse(pre,preCst,preCoe);
			parse(post,postCst,postCoe);
			preCoe-=postCoe;
			postCst-=preCst;
			if(!preCoe)
				if(!postCst)
					return "Infinite solutions";
				else
					return "No solution";
			return "x="+to_string(postCst/preCoe);
		}
		void parse(string str,int &cst,int &coe) {
			str.push_back('+');
			cst=coe=0;
			int num=0,sign=1,flag=0;
			for(int i=0; i<str.length(); ++i) {
				if(str[i]=='-'||str[i]=='+') {
					if(i) {
						if(flag)
							coe+=sign*num;
						else
							cst+=sign*num;
						sign=1,flag=0,num=0;
					}
					sign=str[i]=='-'?-1:1;
				} else if(str[i]=='x') {
					flag=1;
					num=str[i-1]=='-'||str[i-1]=='+'?1:num;
				} else
					num=num*10+str[i]-'0';
			}
		}
};
int main() {
	Solution s;
	string str="0x=0";
	cout<<s.solveEquation(str)<<endl;
	return 0;
}
