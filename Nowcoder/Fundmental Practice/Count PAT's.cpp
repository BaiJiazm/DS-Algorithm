#include<iostream>
using namespace std;

#define MAXLEN 100000
#define MODE 1000000007

int main()
{
	char str[MAXLEN + 1];
	while (cin.getline(str, MAXLEN + 1)) {
		int i;
		int p = 0, pa = 0, pat = 0;
		for (i = 0; str[i]; ++i)
			if (str[i] == 'P')
				++p;
			else if (str[i] == 'A')
				pa += p;
			else
				pat = (pat + pa) % MODE;
			cout << pat;
	}
	return 0;
}