#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<map>
using namespace std;

int main()
{
	map<long long, int>m;
	map<long long, int >::iterator iter ;
	long long no;
	int num = 0, temnum;
	int count;

	int N;
	scanf("%d", &N);

	long long ll;
	for (N *= 2; N--;) {
		scanf("%lld", &ll);
		iter = m.find(ll);
		if (iter == m.end())
			m.insert(pair<long long, int>(ll, temnum = 1));
		else
			temnum = ++iter->second;
		
		if (temnum > num) {
			num = temnum;
			no = ll;
			count = 1;
		}
		else if (temnum == num) {
			if (ll < no)
				no = ll;
			++count;
		}
	}

	if (count > 1)
		printf("%lld %d %d", no, num, count);
	else
		printf("%lld %d", no, num);

	return 0;
}