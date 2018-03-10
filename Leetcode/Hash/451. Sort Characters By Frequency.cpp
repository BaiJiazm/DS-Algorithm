class Solution {
	public:
		string frequencySort(string s) {
			unordered_map<char,int> freq;
			vector<string> bucket(s.size()+1, "");
			string res;

			for(char c:s)
				freq[c]++;
			for(auto& it:freq) {
				int n = it.second;
				char c = it.first;
				bucket[n].append(n, c);
			}
			for(int i=s.size(); i>0; i--)
				res.append(bucket[i]);
			return res;
		}
};

class Solution {
	public:
		string frequencySort(string s) {
			int counts[256] = {0};
			for (char ch : s)
				++counts[ch];
			sort(s.begin(), s.end(), [&](char a, char b) {
				return counts[a] > counts[b] || (counts[a] == counts[b] && a < b);
			});
			return s;
		}
};

class Solution {
	private:
		struct comp {
			bool operator() (const pair<char, int> &p1, const pair<char, int> &p2) const {
				return (p1.second < p2.second);
			}
		};
	public:
		string frequencySort(string s) {
			priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;
			vector<int> dict(256);

			for (int i = 0; i < s.size(); i++) {
				dict[s[i]]++;
			}
			for (int i = 0; i < 256; i++) {
				if (dict[i]) {
					pq.push(make_pair((char)i, dict[i]));
				}
			}
			string res;
			while (!pq.empty()) {
				string l(pq.top().second, pq.top().first);
				res += l;
				pq.pop();
			}
			return (res);
		}
};
