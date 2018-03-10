#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	getline(cin, s); //读取包含空格的一行  
	int max = 1;
	int n = s.size(); //字符串长度  
	bool flag[1005][1005];  //s[i]~s[j]是否是回文，1是，0不是  

	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
			flag[i][j] = true;

	for (j = 1; j < n; j++)
	{
		for (i = 0; i < j; i++)
		{
			flag[i][j] = false;
			if (s[i] == s[j] && flag[i + 1][j - 1] == true)
			{
				flag[i][j] = true;
				if (j - i + 1 > max)
					max = j - i + 1;
			}
		}
	}
	cout << max;

	return 0;
}