class Solution {
	public:
		int findContentChildren(vector<int>& g, vector<int>& s) {
			sort(g.begin(),g.end());
			sort(s.begin(),s.end());
			int ans,i,j;
			for(i=0,j=0,ans=0; i<g.size()&&j<s.size(); ++i,++j) {
				while(j<s.size()&&s[j]<g[i])
					++j;
				if(j<s.size())
					++ans;
			}
			return ans;
		}
};
