#include<iostream>
#include<set>
#include<string>
using namespace std;

#define MAXLEN 10000

int main()
{
	char s1[MAXLEN + 1];
	char s2[MAXLEN + 1];
	char s[MAXLEN + 1];

	while (cin.getline(s1, MAXLEN)) {
		cin.getline(s2, MAXLEN);

		set<char>subSet;
		int i, j;
		for (i = 0; s2[i]; ++i)
			subSet.insert(s2[i]);

		for (i = 0, j = 0; s1[i]; ++i)
			if (subSet.find(s1[i]) == subSet.end())
				s[j++] = s1[i];
		s[j] = '\0';

		printf("%s\n", s);
	}
	return 0;
}