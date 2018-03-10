#include<string>
#include<algorithm>
using namespace std;
class Solution {
	public:
		string reverseStr(string s, int k) {
			int flag=1;
			string ans;
			for (int i=0; i<s.length(); i+=k) {
				if (flag)
					ans+=s.substr(i,k);
				else {
					string temStr=s.substr(i,k);
					reverse(temStr.begin(),temStr.end());
					ans+=temStr;
				}
				flag~=flag;
			}
			return ans;
		}
};
