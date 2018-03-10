#include <iostream>
using namespace std;

int main() {
//	freopen("201703-1-test.txt", "r", stdin);
	int n,k;
	int a, sum;
	int ans;
	while(scanf("%d %d", &n, &k)!=EOF) {
		ans=0;
		sum=0;
		while(n--) {
			scanf("%d", &a);
			sum+=a;
			if(sum>=k) {
				++ans;
				sum=0;
			}
		}
		ans+=sum!=0;
		cout<<ans<<endl;
	}
	return 0;
}
