//穷举法1，通过60%case
//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long LL;
//
//int main()
//{
//    for (LL n, w; cin >> n >> w; ) {
//        vector<LL> v;
//        for (int i = 0, x; i < n; cin >> x, v.push_back(x), ++i) {}
//        LL ans = 0;
//        for (int i = 0; i < (1 << n); i++) {
//            LL sum = 0;
//            for (int bit = 0; bit < n; bit++)
//                sum += (i & (1 << bit)) ? v[bit] : 0;
//            ans += sum <= w;
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

//穷举法2，通过80%case
//#include <cstdio>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//long long dfs(vector<int>&v, int index, long long w) {
//	if(w<0) {
//		return 0;
//	}
//	if(w>=0&&index>=v.size()) {
//		return 1;
//	}
//	long long ret=0;
//	ret+=dfs(v, index+1, w);
//	ret+=dfs(v, index+1, w-v[index]);
//	return ret;
//}
//
//int main() {
//	unsigned int n, w;
//	int t;
//	while(cin>>n>>w) {
//		vector<int>v;
//		while(n--) {
//			cin>>t;
//			v.push_back(t);
//		}
//		cout<<dfs(v, 0, w)<<endl;
//	}
//	return 0;
//}


#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
	for (LL n, w; cin >> n >> w; ) {
		vector<LL> v;
		for (int i = 0, x; i < n; cin >> x, v.push_back(x), ++i) {}

		LL n1 = n >> 1, n2 = n - n1;

		vector<LL> arr;
		for (int i = 0; i < (1 << n1); i++) {
			LL sum = 0;
			for (int bits = 0; bits < n1; bits++)
				sum += (i & (1 << bits)) ? v[bits] : 0;
			arr.push_back(sum);
		}
		sort(arr.begin(), arr.end());

		LL ans = 0;
		for (int i = 0; i < (1 << n2); i++) {
			LL sum = 0;
			for (int bits = 0; bits < n2; bits++)
				sum += (i & (1 << bits)) ? v[n1 + bits] : 0;
			ans += upper_bound(arr.begin(), arr.end(), w - sum) - arr.begin();
		}
		cout << ans << endl;
	}
	return 0;
}
