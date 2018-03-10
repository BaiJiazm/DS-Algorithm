#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string>dict;
		for (vector<string>::iterator it = wordDict.begin(); it != wordDict.end(); ++it)
			dict.insert(*it);

		int i, j;
		int slen = s.length();
		vector<bool>v(slen + 1, false);
		v[0] = true;
		for (i = 1; i <= slen; ++i)
			for (j = i - 1; j >= 0; --j)
				if (v[j] && dict.count(s.substr(j, i - j))) {
					v[i] = true;
					break;
				}
		return v[slen];
	}
};