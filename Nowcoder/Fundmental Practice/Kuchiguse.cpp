#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define NMAX 100
#define MAXLEN 256

char str[NMAX][MAXLEN + 1];
char ans[MAXLEN + 1];
int N;

void restr(char *str, int len)
{
	int i, j;
	char tem;
	for (i = 0, j = len - 1; i < j; ++i, --j)
	{
		tem = str[i];
		str[i] = str[j];
		str[j] = tem;
	}
}

int main()
{
	int i, j;
	scanf("%d\n", &N);
	char ch = '\0';

	for (i = 0; i < N; ++i)
		/*{
			for (j = 0; (ch = getchar()) && ch != '\n'; ++j)
				str[i][j] = ch;
			str[i][j] = '\0';
		}*/
		cin.getline(str[i], 256, '\n');

	int len;
	for (i = 0; i < N; ++i)
	{
		len = strlen(str[i]);
		restr(str[i], len);

		if (i == 0)
		{
			memcpy(ans, str[0], len);
			ans[len] = '\0';
		}
		else
		{
			for (j = 0; ans[j] && str[i][j] && ans[j] == str[i][j]; ++j)
				;
			ans[j] = '\0';
		}
	}

	len = strlen(ans);
	if (len)
		restr(ans, len);
	else
		strcpy(ans, "nai");

	printf("%s", ans);
	return 0;
}



/* 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    vector<string> v;
    string s, rs;
    cin >> n;
    getline(cin, s);// È¥µô»Ø³µ
    while (n--){
        getline(cin, s);
        reverse(s.begin(), s.end());
        v.push_back(s);
    }
    int loc = -1;
    bool flag = true;
    while (flag && ++loc < v[0].size()){
        for (int i = 0; i < v.size(); ++i){
            if (v[i][loc] != v[0][loc]){
                flag = false;
                break;
            }
        }
        if (flag){
            rs += v[0][loc];
        }
    }
    if (rs.empty()){
        cout <<"nai" <<endl;
    }else{
        reverse(rs.begin(), rs.end());
        cout <<rs <<endl;
    }
    return 0;
}
*/



/*
#include<iostream>  
#include<string>  
using namespace std;

int main()
{
	int n;
	cin >> n;
	getchar();//there is a '\n' behind n  
	string kuchiguse;
	getline(cin, kuchiguse);
	for (int i = 1; i<n; ++i)
	{
		string s;
		getline(cin, s);
		int j = 0;
		while (s[s.size() - 1 - j] == kuchiguse[kuchiguse.size() - 1 - j])
		{//check forward the common suffix  
			++j;
			if (j == s.size() || j == kuchiguse.size())
				break;
		}
		if (j == 0)
		{//if there is no common suffix  
			cout << "nai" << endl;
			return 0;
		}
		string c;//record the common suffix  
		c.assign(kuchiguse, kuchiguse.size() - j, j);
		kuchiguse = c;
	}
	cout << kuchiguse << endl;
	return 0;
}
*/