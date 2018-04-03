/*
这里我们从k + 1枚举y到n，对于一个确定的y，x % y的值的大小是有周期性的，因此可以直接计算出来，但是对于k = 0要特殊处理，因为对于任意的(x, y)，x % y永远大于等于0，因此，当k = 0时，答案为n * n。
*/ 
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
	for (LL n, k; cin >> n >> k; ) {
		LL ans = 0;
		if (!k)
			ans = n * n;
		else
			for (LL y = k + 1; y <= n; y++)
				ans += n / y * (y - k) + (n % y >= k ? n % y - k + 1 : 0);
		cout << ans << endl;
	}
	return 0;
}
