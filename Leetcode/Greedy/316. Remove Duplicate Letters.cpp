/*
	思考了一会儿，写了如下算法，虽然过了259/286种case，但是仍然是错误的。比如：cbacdcbc
	我始终在想，解决一个问题绝不是凭感觉去想算法，不是天马行空的小鹿乱撞，看运气去解决问题的。
	思考是有一定内在逻辑的，一定要问为什么这样思考。

	按照最先的思路，对于出现的一个字符，必定会有其中多个中的一个留在最后，但是要怎么考虑呢？根据最大条件，自然要从最小或最大字符思考保留哪一个？
	但是反例高诉我们这样是行不通的。改变思路，按照从左到右的顺序会怎样？
	根据答案条件要求，我们可以思考：如果当前字符后面还会出现，那么可以删除，如果仅有一个，那么必须保留；要想是字典序最小，那么必定要使待定序列前面中可以删除且比当前
	大的字符去掉。
*/
class Solution {
	public:
		string removeDuplicateLetters(string s) {
			vector<vector<int>>m(26);
			vector<int>pos;
			int i,maxpos=-1;
			for(i=0; i<s.length(); ++i)
				m[s[i]-'a'].push_back(i);
			for(i=0; i<26; ++i)
				if(!m[i].empty()) {
					auto it=upper_bound(m[i].begin(),m[i].end(),maxpos);
					if(it==m[i].end())
						--it;
					else
						maxpos=*it;
					pos.push_back(*it);
				}
			sort(pos.begin(),pos.end());
			string res;
			for(auto &a:pos)
				res+=s[a];
			return res;
		}
};


class Solution {
	public:
		string removeDuplicateLetters(string s) {
			vector<int> cand(256, 0);
			vector<bool> visited(256, false);
			for (char c : s)
				cand[c]++;
			string result = "0";
			for (char c : s) {
				cand[c]--;
				if (visited[c]) continue;
				while (c < result.back() && cand[result.back()]) {
					visited[result.back()] = false;
					result.pop_back();
				}
				result += c;
				visited[c] = true;
			}
			return result.substr(1);
		}
};
