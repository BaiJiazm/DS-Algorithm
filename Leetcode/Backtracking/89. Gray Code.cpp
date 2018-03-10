class Solution {
	public:
		vector<int> grayCode(int n) {
			vector<int>ans(1<<n);

			ans[0]=0;
			ans[1]=1;

			for (int j=1; j<n; ++j) {
				for (int k=(1<<j)-1,max=(1<<j+1)-1,high=1<<j; k>=0; --k)
					ans[max-k]=ans[k]|high;
			}
			return ans;
		}
};
