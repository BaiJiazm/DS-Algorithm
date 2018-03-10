#include<string>
#include<sstream>
using namespace std;

class Solution {
	public:
		string decodeString(string s) {
			str=s;
			index=0;
			return helpDecode();
		}
	private:
		string str;
		int index;
		string helpDecode() {
			string s1="";

			for (; index<str.length(); ++index) {
				char ch=str[index];
				if (ch>='1'&&ch<='9') {
					int nextIndex=str.find('[',index);
					stringstream ss;
					int count;
					ss<<str.substr(index,nextIndex);
					ss>>count;
					index=nextIndex+1;
					string s2=helpDecode();
					while(count--)
						s1+=s2;
				} else if (ch==']') {
					return s1;
				} else
					s1+=ch;
			}
			return s1;
		}
};
