class Solution {
	public:
		string getPermutation(int n, int k) {
			vector<int>ptable(n);
			vector<char>vset;
			ptable[0]=1;
			for(int i=1; i<n; ++i)
				ptable[i]=ptable[i-1]*i;
			for(int i=1; i<=n; ++i)
				vset.push_back(i+'0');
			string ans;
			--k;
			for(int i=n-1; i>=0; --i) {
				int kth=k/ptable[i];
				k%=ptable[i];
				ans.push_back(vset[kth]);
				vset.erase(vset.begin()+kth);
			}
			return ans;
		}
};

