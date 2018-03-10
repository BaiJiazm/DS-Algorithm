class Solution {
	public:
		int lengthOfLastWord(string s) {
			int end=s.length()-1;
			while(end>=0&&s[end]==' ')
                --end;
            int begin=end;
            while(begin>=0&&s[begin]!=' ')
                --begin;
            return end-begin;
		}
};
