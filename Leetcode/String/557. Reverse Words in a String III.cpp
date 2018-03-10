#include<iostream>
#include<string>
using namespace std;

class Solution {
	public:
		string reverseWords(string s) {
			string ans="";
			unsigned int p1,p2;
			for(p1=0,p2=0; p2<s.length();) {
				p2=s.find_first_of(' ',p1);
				string str=s.substr(p1,p2-p1);
				if(!ans.empty())
					ans+=" ";			
				ans+=string(str.rbegin(),str.rend());
				p1=p2+1;
			}
			return ans;
		}
};

int main() {
	string s="Let\'s a take  LeetCode   contest";
	Solution sl;
	cout<<sl.reverseWords(s);
	return 0;
}
