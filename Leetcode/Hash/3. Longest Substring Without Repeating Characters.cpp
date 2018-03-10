class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			vector<int>map(256,0);
			int begin=0,end=0,maxlen=0;
			for(; end<s.length();) {
				if(map[s[end]]) {
					while(s[begin]!=s[end])
						map[s[begin++]]=0;
					++begin;
				} else
					map[s[end]]=1;
				maxlen=max(maxlen,++end-begin);
			}
			return maxlen;
		}
};
