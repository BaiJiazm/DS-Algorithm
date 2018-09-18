//²Î¿¼£ºhttps://blog.csdn.net/jirryzhang/article/details/82722274
 
#include <iostream>
using namespace std;
int main() {
	int n;
	int a, b, c;
	while(cin >> n) {
		for(auto i=0; i<n; ++i) {
			cin >> a >> b >> c;
			int m = a - b;
			bool r=false;
			for(int x = 0; x < 1000; x++) {
				for(int y = -1000; y < 1000; y++) {
					if(x * m + y * a == c) {
						r = true;
						break;
					}
				}
			}
			cout << (r ? "YES" : "NO") << endl;
		}
	}
	return 0;
}
