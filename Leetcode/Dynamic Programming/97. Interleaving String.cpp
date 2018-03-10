//解法一：自己做的迭代算法，3ms
class Solution {
	public:
		bool isInterleave(string s1, string s2, string s3) {
			int s1len=s1.length();
			int s2len=s2.length();
			int s3len=s3.length();
			if (s1len+s2len!=s3len)
				return false;
			map<int,int>m1,m2;
			m1[0]=0;
			for (int i=0; i<s3len&&!m1.empty(); ++i) {
				for (auto a:m1) {
					if (a.first<s1len&&s1[a.first]==s3[i]&&m2.count(a.first+1)==0)
						m2[a.first+1]=a.second;
					if (a.second<s2len&&s2[a.second]==s3[i]&&m2.count(a.first)==0)
						m2[a.first]=a.second+1;
				}
				m1=m2;
				m2.clear();
			}
			if (!m1.empty()&&m1.count(s1len)&&m1[s1len]==s2len)
				return true;
			return false;
		}
};

//解法二：Leetcode的正规DP  3ms
class Solution {
	public:
		bool isInterleave(string s1, string s2, string s3) {

			if(s3.length() != s1.length() + s2.length())
				return false;

			bool table[s1.length()+1][s2.length()+1];

			for(int i=0; i<s1.length()+1; i++)
				for(int j=0; j< s2.length()+1; j++) {
					if(i==0 && j==0)
						table[i][j] = true;
					else if(i == 0)
						table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
					else if(j == 0)
						table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
					else
						table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
				}

			return table[s1.length()][s2.length()];
		}
};

//解法三：BFS   https://leetcode.com/problems/interleaving-string/?tab=Solutions
struct MyPoint {
	int y, x;
	bool operator==(const MyPoint &p) const {
		return p.y == y && p.x == x;
	}
};
namespace std {
	template <>
	struct hash<MyPoint> {
		size_t operator () (const MyPoint &f) const {
			return (std::hash<int>()(f.x) << 1) ^ std::hash<int>()(f.y);
		}
	};
}

class Solution {
	public:
		bool isInterleave(string s1, string s2, string s3) {
			if (s1.size() + s2.size() != s3.size()) return false;

			queue<MyPoint> q;
			unordered_set<MyPoint> visited;
			bool isSuccessful = false;
			int i = 0;

			q.push(MyPoint { 0, 0 });
			q.push(MyPoint { -1, -1 });
			while (!(1 == q.size() && -1 == q.front().x)) {
				auto p = q.front();
				q.pop();
				if (p.y == s1.size() && p.x == s2.size()) {
					return true;
				}
				if (-1 == p.y) {
					q.push(p);
					i++;
					continue;
				}
				if (visited.find(p) != visited.end()) {
					continue;
				}
				visited.insert(p);

				if (p.y < s1.size()) { // down
					if (s1[p.y] == s3[i]) {
						q.push(MyPoint { p.y + 1, p.x });
					}
				}
				if (p.x < s2.size()) { // right
					if (s2[p.x] == s3[i]) {
						q.push(MyPoint { p.y, p.x + 1 });
					}
				}
			}
			return false;
		}
};


//解法四：DFS   https://leetcode.com/problems/interleaving-string/?tab=Solutions

public boolean isInterleave(String s1, String s2, String s3) {
	char[] c1 = s1.toCharArray(), c2 = s2.toCharArray(), c3 = s3.toCharArray();
	int m = s1.length(), n = s2.length();
	if(m + n != s3.length()) return false;
	return dfs(c1, c2, c3, 0, 0, 0, new boolean[m + 1][n + 1]);
}

public boolean dfs(char[] c1, char[] c2, char[] c3, int i, int j, int k, boolean[][] invalid) {
	if(invalid[i][j]) return false;
	if(k == c3.length) return true;
	boolean valid =
	    i < c1.length && c1[i] == c3[k] && dfs(c1, c2, c3, i + 1, j, k + 1, invalid) ||
	    j < c2.length && c2[j] == c3[k] && dfs(c1, c2, c3, i, j + 1, k + 1, invalid);
	if(!valid) invalid[i][j] = true;
	return valid;
}
