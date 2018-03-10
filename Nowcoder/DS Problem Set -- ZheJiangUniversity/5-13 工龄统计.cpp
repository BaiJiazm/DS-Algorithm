#include<iostream>
#include<set>
using namespace std;

int main()
{
	multiset<int>S1;
	set<int>S2;

	int m;
	cin >> m;
	while (m--) {
		int tem;
		cin >> tem;
		S1.insert(tem);
		S2.insert(tem);
	}

	set<int>::iterator it;
	for (it = S2.begin(); it != S2.end(); ++it)
		cout << *it << ":" << S1.count(*it) << endl;

	return 0;
}