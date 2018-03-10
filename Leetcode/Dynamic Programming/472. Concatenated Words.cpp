#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
#include<algorithm>
#include<numeric>
using namespace std;

//解法1：对每一个单词进行 DP
class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		if (words.size() <= 2) return{};
		vector<string> res;
		unordered_set<string> dict(words.begin(), words.end());
		for (string word : words) {
			int len = word.size();
			if (!len)//题目中没有明确说明，要注意
				continue;
			dict.erase(word);
			vector<bool> v(len + 1, false);
			v[0] = true;
			for (int i = 0; i < len + 1; ++i) {
				for (int j = 0; j < i; ++j) {
					if (v[j] && dict.count(word.substr(j, i - j))) {
						v[i] = true;
						break;
					}
				}
			}
			if (v.back()) res.push_back(word);
			dict.insert(word);
		}
		return res;
	}
};


//解法2：递归解法
class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		vector<string> res;
		unordered_set<string> dict(words.begin(), words.end());
		for (string word : words) {
			if (helper(word, dict, 0, 0)) {
				res.push_back(word);
			}
		}
		return res;
	}
	bool helper(string& word, unordered_set<string>& dict, int pos, int cnt) {
		if (pos >= word.size() && cnt >= 2) return true;
		for (int i = 1; i <= (int)word.size() - pos; ++i) {
			string t = word.substr(pos, i);
			if (dict.count(t) && helper(word, dict, pos + i, cnt + 1)) {
				return true;
			}
		}
		return false;
	}
};