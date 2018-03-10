# include <cstdio>  
# include <iostream>
#include <algorithm>
# include <string>  
using namespace std;

const int _size = 10000;
string num[_size];
bool cmp(const string& a, const string& b) { return a + b< b + a; }
int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n, cmp);
	string out;
	for (i = 0; i < n; i++)
		out += num[i];
	for (i = 0; i < out.size() && out[i] == '0'; i++);
	if (i == out.size())
		printf("0");
	else
		printf("%s", out.c_str() + i);
	printf("\n");
	return 0;
}
