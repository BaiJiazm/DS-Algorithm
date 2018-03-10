//字串自然能整除整串长度，可以优化
class Solution {
	public:
		bool repeatedSubstringPattern(string s) {
			int slen=s.length();
			string str;
			int i,j;
			for (i=1; i<=slen/2; ++i) {
				if (slen%i==0) {
					str=s.substr(0,i);
					for (j=i; j<slen; j+=i) {
						if (str!=s.substr(j,i))
							break;
					}
					if (j==slen)
						return true;
				}
			}
			return false;
		}
};
