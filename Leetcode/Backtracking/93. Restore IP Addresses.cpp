class Solution {
	public:
		vector<string> restoreIpAddresses(string s) {
			dfs(s,4,"");
			return ans;
		}
		vector<string> ans;
		bool isValid(string s) {
			int i=atoi(s.c_str());
			if(s.length()==1)
				return true;
			else if(s.length()==2&&i>=10)
				return true;
			else if (s.length()==3&&i>=100&&i<=255)
				return true;
			return false;
		}
		void dfs(string s, int n,string ip) {
			if(s.length()>(n*3)||s.length()<n)
				return ;
			else if(n==1&&isValid(s)) {
				ans.push_back(ip+s);
				return ;
			}
			for (int i=1; i<=3; ++i) {
				string ss=s.substr(0,i);
				if(s.length()>i&&isValid(ss)) {
					dfs(s.substr(i),n-1,ip+ss+".");
				}
			}
		}
};s
