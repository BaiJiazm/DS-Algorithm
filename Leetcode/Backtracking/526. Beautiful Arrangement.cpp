class Solution {
	public:
		int countArrangement(int N) {
			count=0;
			used.resize(N+1,0);
			canUse.resize(N+1,0);
			for (int i=1; i<=N; ++i)
				for (int j=i; j<=N; ++j)
					if (j%i==0) {
						canUse[i]|=1<<j;
						canUse[j]|=1<<i;
					}
			helper(N,1);
			return count;
		}
		vector<int>used;
		vector<int>canUse;
		int count;
		void helper(const int &N,int index) {
			if (index==N+1) {
				++count;
				return ;
			}
			for(int j=1; j<=N; ++j)
				if (canUse[index]&1<<j&&!used[j]) {
					used[j]=1;
					helper(N,index+1);
					used[j]=0;
				}
		}
};

class Solution {
	public:
		int countArrangement(int N) {
			if (N == 0) return 0;
			vector<int> m(1<<(N+1), -1);
			return dfs(1, N, 0, m);
		}

		int dfs(int start, int n, int used, vector<int>& m) {
			if (start == n+1) return 1;
			if (m[used] != -1) return m[used];
			int res = 0;
			for (int i = 1; i <= n; ++i) {
				if (!(used & (1<<i)) && (i%start == 0 || start%i == 0))
					res += dfs(start+1, n, used|(1<<i), m);
			}
			m[used] = res;
			return res;
		}
};

class Solution {
	public:
		int countArrangement(int N) {
			vector<int> vs;
			for (int i=0; i<N; ++i) vs.push_back(i+1);
			return counts(N, vs);
		}
		int counts(int n, vector<int>& vs) {
			if (n <= 0) return 1;
			int ans = 0;
			for (int i=0; i<n; ++i) {
				if (vs[i]%n==0 || n%vs[i]==0) {
					swap(vs[i], vs[n-1]);
					ans += counts(n-1, vs);
					swap(vs[i], vs[n-1]);
				}
			}
			return ans;
		}
};
