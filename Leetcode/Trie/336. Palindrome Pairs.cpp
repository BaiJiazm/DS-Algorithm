class Solution {
	public:
		vector<vector<int>> palindromePairs(vector<string>& words) {
			unordered_map<string, int> dict;
			for (int i = 0; i < (int)words.size(); ++i) {
				dict[Reverse(words[i])]= i;
			}

			vector<vector<int>> result;

			for (int i = 0; i < (int)words.size(); ++i) {
				for (int j = 0; j < (int)words[i].length(); ++j) {
					string left = words[i].substr(0, j);
					string right = words[i].substr(j);
					if (IsPalindrome(left) && dict.find(right) != dict.end() && dict[right] != i) {
						result.push_back(vector<int>({dict[right], i}));
					}

					if (IsPalindrome(right) && dict.find(left) != dict.end() && dict[left] != i) {
						result.push_back(vector<int>({i, dict[left]}));
						if (j == 0) {
							result.push_back(vector<int>({dict[left], i}));//if we append "", it can be append in both direction
						}
					}
				}
			}
			return result;
		}
	private:
		string Reverse(string s) {
			reverse(s.begin(), s.end());
			return s;
		}

		bool IsPalindrome(const string &s) {
			int lf = 0, rt = ((int)s.length() - 1);
			while (lf < rt) {
				if (s[lf++] != s[rt--]) {
					return false;
				}
			}
			return true;
		}
};
