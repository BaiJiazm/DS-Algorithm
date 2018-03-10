#include <iostream>  
#include <string>  

using namespace std;

int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int pos = 0;
	while (!(s1[pos] == s2[pos] && s1[pos] >= 'A' && s1[pos] <= 'G'))
		pos++;
	switch (s1[pos])
	{
	case 'A':
		cout << "MON ";
		break;
	case 'B':
		cout << "TUE ";
		break;
	case 'C':
		cout << "WED ";
		break;
	case 'D':
		cout << "THU ";
		break;
	case 'E':
		cout << "FRI ";
		break;
	case 'F':
		cout << "SAT ";
		break;
	case 'G':
		cout << "SUN ";
		break;
	}
	pos++;
	while (!(s1[pos] == s2[pos] && (s1[pos] >= 'A' && s1[pos] <= 'N' || s1[pos] >= '0' && s1[pos] <= '9')))
		pos++;
	printf("%02d:", s1[pos] >= '0' && s1[pos] <= '9' ? s1[pos] - '0' : s1[pos] - 'A' + 10);

	pos = 0;
	while (!(s3[pos] == s4[pos] && (s3[pos] >= 'a' && s3[pos] <= 'z' || s3[pos] >= 'A' && s3[pos] <= 'Z')))
		pos++;
	printf("%02d\n", pos);

	return 0;
}