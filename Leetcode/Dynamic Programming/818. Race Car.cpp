#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

class Solution {
#define TMAX 65536
	public:
		int dp1[(TMAX<<1)+1];
		int dp2[(TMAX<<1)+1];
		queue<pair<int, int>> Q;
		int target;
		int racecar(int target) {
			if(target==0)
				return 0;
			this->target=target;
			memset(dp1, 0, sizeof(dp1));
			memset(dp2, 0, sizeof(dp2));
			int p = 0, s = 1;
			int ans=0, qsize;
			Q.push({p, s});
			dp1[TMAX + p] |= s;
			while (1) {
				++ans;
				qsize=Q.size();
//				cout<<"ans="<<ans<<" size="<<qsize<<"\n";
				while (qsize--) {
					p = Q.front().first;
					s = Q.front().second;
					Q.pop();
//					cout<<"---- p="<<p<<" s="<<s<<"\n";
					if(s>0&&(check(dp1, p+s, s<<1)||check(dp2, p, -1))||s<0&&(check(dp2, p+s, s<<1)||check(dp1, p, 1)))
						return ans;
				}
			}
			return 0;
		}

		bool check(int dp[(TMAX<<1)+1], int np, int ns) {
			if (abs(np) <= TMAX && (dp[TMAX + np] & abs(ns)) == 0) {
				Q.push({np, ns});
				dp[TMAX + np] |= abs(ns);
//				cout<<"np="<<np<<" ns="<<ns<<"\n";
			}
			return np == target;
		}
};

int main() {
	Solution s;
	cout<<s.racecar(10000)<<endl;
}
