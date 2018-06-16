#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define M_MAX 100010
const int mod = 1e9 + 7;

int m1[M_MAX];
int m2[M_MAX];

vector<int>v1;
vector<int>v2;
int m;

int help1(int m) {
	if (m < 0) {
		return 0;
	}
	if (m1[m] != -1) {
		return m1[m];
	}
	int i, t = 0;
	for (i = 0; i < v1.size(); ++i) {
		t = (t + help1(m - v1[i])) % mod;
	}
	return m1[m] = t;
}

void help11() {
	int i, j, t;
	m1[0]=1;
	for (i=1; i<=m; ++i) {
		for (j=0, t=0; j<v1.size(); ++j) {
			if(i-v1[j]>=0) {
				t=(t+m1[i-v1[j]])%mod;
			} else
				break;
		}
		m1[i]=t;
	}
}

void help2(int index, int t) {
	if (t > m) {
		return;
	}
	m2[t] = (m2[t] + 1) % mod;
	if (index >= v2.size()) {
		return;
	}
	help2(index + 1, t + v2[index]);
	help2(index + 1, t);
}

int main() {
	int n1, n2;
	int i, t;
	while (scanf("%d %d %d", &n1, &n2, &m) != EOF) {
		for (i = 0; i < n1; ++i) {
			scanf("%d", &t);
			v1.push_back(t);
		}
		for (i = 0; i < n2; ++i) {
			scanf("%d", &t);
			v2.push_back(t);
		}
//		memset(m1, -1, sizeof(m1));
//		help1(100000);
		help11();
		help2(0, 0);
		for (i=0; i<=m; ++i) {
			cout<<m1[i]<<" "<<m2[i]<<endl;
		}
		int ans = 0;
		for (i = 0; i <= m; ++i) {
			if (m1[i] == -1) {
				m1[i] = 0;
			}
			ans = (ans + m1[i] + m2[m - i]) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
