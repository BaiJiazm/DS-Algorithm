#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXLEN 1000

int main()
{
	char sell[MAXLEN + 1];
	char need[MAXLEN + 1];
	while (cin.getline(sell, MAXLEN)) {
		cin.getline(need, MAXLEN);

		int lens = strlen(sell);
		int lenn = strlen(need);
		sort(sell, sell + lens, less<char>());
		sort(need, need + lenn, less<char>());

		int missing = 0, extra = 0;
		int i, j;
		for (i = 0, j = 0; i < lens&&j < lenn;)
			if (sell[i] == need[j])
				++i, ++j;
			else if (sell[i] > need[j])
				++j, ++missing;
			else
				++i, ++extra;

			extra += lens - i;
			missing += lenn - j;

			if (missing == 0)
				printf("Yes %d", extra);
			else
				printf("No %d", missing);

	}
	return 0;
}