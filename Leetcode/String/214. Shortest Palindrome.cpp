#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
	public:
		string shortestPalindrome(string s) {
			int pe=s.length()-1;
			int ps,t;
			for (ps=0; pe>ps; --pe) {
				for (ps=0,t=pe; ps<t&&s[t]==s[ps];)
					++ps,--t;
				if(ps>=t)
					break;
			}
			string prefix=s.substr(pe+1,s.length()-pe-1);
			reverse(prefix.begin(),prefix.end());
			return prefix+s;
		}
};

int main() {
	string str="aacecaaa";
	Solution s;
	cout<<s.shortestPalindrome(str)<<endl;
	return 0;
}

