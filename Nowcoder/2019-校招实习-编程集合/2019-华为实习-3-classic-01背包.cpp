#include <iostream>
#include <vector>
using namespace std;

void getAns(vector<int>& w, vector<vector<int> >&path, vector<int>&ans, int i, int j) {
	if(i<=0||j<0) {
		return ;
	}
	if(path[i][j]) {
		getAns(w, path, ans, i-w[j], j-1);
		ans.push_back(j+1);
	} else {
		getAns(w, path, ans, i, j-1);
	}
	return ;
}

int main() {
//	freopen("3test.txt", "r", stdin);
	
	int c;
	cin >> c;

	vector<int>vt, w, v;
	int n, t;
	int i, j;
	while (scanf("%d", &t) != EOF) {
		vt.push_back(t);
	}
	n=vt.size()>>1;
	w=vector<int>(vt.begin(), vt.begin()+n);
	v=vector<int>(vt.begin()+n, vt.end());

	vector<vector<int> >dp(c+1, vector<int>(n, 0));
	vector<vector<int> >path(c+1, vector<int>(n, 0));
	for (j=0; j<n; ++j) {
		for (i=0; i<=c; ++i) {
			if(j==0) {
				if(i<w[j]) {
					dp[i][j]=0;
				} else {
					dp[i][j]=v[j];
					path[i][j]=1;
				}
			} else {
				if(i<w[j]) {
					dp[i][j]=dp[i][j-1];
				} else {
					dp[i][j]=dp[i][j-1];
					if(dp[i-w[j]][j-1]+v[j]>dp[i][j]) {
						dp[i][j]=dp[i-w[j]][j-1]+v[j];
						path[i][j]=1;
					}
				}
			}
		}
	}
	vector<int>ans;
	getAns(w, path, ans, c, n-1);
	for (i=0; i<ans.size(); ++i) {
		if(i==0)
			cout<<ans[i];
		else
			cout<<" "<<ans[i];
	}
	return 0;
}
