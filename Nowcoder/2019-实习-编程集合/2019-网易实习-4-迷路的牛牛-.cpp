//把NESW用数字0123表示，向左走就减一，向右走就加一，由于在处理的过程中ans可能为负数，因此对ans加4再模4。 
#include <bits/stdc++.h>

using namespace std;

int main() {
	const char DIR[] = "NESW";
	for (int n; cin >> n; ) {
		string str;
		cin >> str;
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = (ans + (str[i] == 'L' ? -1 : 1) + 4) % 4;
		cout << DIR[ans % 4] << endl;
	}
	return 0;
}
