#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

#define MAXLNE 80

int main()
{
	int N;
	int n1, n2;
	char str[MAXLNE + 1];

	while (scanf("%s", str) != EOF) {
		N = strlen(str);
		n1 = (N + 2) / 3;
		n2 = N - 2 * n1;

		int i;
		for (i = 1; i < n1; ++i)
			cout << str[i - 1] << setw(n2 + 1) << right << str[N - i] << endl;
		str[N - i + 1] = '\0';
		cout << str + i - 1 << endl;
	}
	return 0;
}