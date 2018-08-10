/*	下面前三种算法理论上是正确的，但是实际Time Lime Error
 	测试：	"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
			["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
 */
 
 //简单暴力回溯穷举	TLE
class Solution {
	public:
		vector<string> wordBreak(string s, vector<string>& wordDict) {
			unordered_set<string>wordSet;
			for(auto &a:wordDict)
				wordSet.insert(a);
			vector<string>res;
			string path;
			dfs(res,path,s,0,wordSet);
			return res;
		}
		void dfs(vector<string>&res,string &path,string &s,int index,unordered_set<string>&wordSet) {
			if(index==s.length()) {
				res.push_back(path.substr(1));
				return ;
			}
			for(int i=index+1; i<=s.length(); ++i) {
				string substr=s.substr(index,i-index);
				if(wordSet.find(substr)!=wordSet.end()) {
					path+=" "+substr;
					dfs(res,path,s,i,wordSet);
					path.erase(path.end()-(i-index+1),path.end());
				}
			}
		}
};

//dfs+dp	少写 return m[s]=res; 结果TLE。后来改掉！ 
class Solution {
	public:
		unordered_map<string,vector<string>>m;
		unordered_set<string>hashDict;
		vector<string> wordBreak(string s, vector<string>& wordDict) {
			for(auto &a:wordDict)
				hashDict.insert(a);
			return wordBrk(s);
		}
		vector<string> wordBrk(string s) {
			if(m.find(s)!=m.end())
				return m[s];
			vector<string>res;
			if(hashDict.count(s))
				res.push_back(s);
			for(int i=1; i<s.length(); ++i) {
				string pres=s.substr(0,i);
				if(hashDict.count(pres)) {
					vector<string>tem=wordBrk(s.substr(i));
					for(auto &a:tem)
						res.push_back(pres+" "+a);
				}
			}
			return m[s]=res;
		}
};

//另一种角度， dfs+dp	模仿下面的ac的Java版程序 
class Solution {
	public:
		unordered_map<string,vector<string>>m;
		vector<string> wordBreak(string s,const vector<string>&wordDict) {
			if(m.count(s))
				return m[s];
			if(s.empty()) {
				m[s]=vector<string>(1,"");
				return m[s];
			}
			vector<string>res;
			for(auto &a:wordDict)
				if(a==s.substr(0,a.length())) {
					vector<string>tem=wordBreak(s.substr(a.length()),wordDict);
					for(auto &b:tem)
						res.push_back(a+(b.empty()?"":" ")+b);
				}
			return m[s]=res;
		}
};


//ac的Java代码 	dfs+dp 
public class Solution {
		public List<String> wordBreak(String s, List<String> wordDict) {
			HashMap<String, LinkedList<String>> map = new HashMap<String, LinkedList<String>>();
			return helper(map, s, wordDict);

		}
		private List<String> helper(HashMap<String, LinkedList<String>> map, String s, List<String> wordDict) {
			if (map.containsKey(s)) return map.get(s);
			LinkedList<String> res = new LinkedList<String>();
			if (s.length() == 0) {
				res.add("");
				return res;
			}
			for ( String item : wordDict) {
				if (s.startsWith(item)) {
					String sub = s.substring(item.length());
					List<String> subList = helper(map, sub, wordDict);
					for (String word : subList) {
						res.add(item + (word.isEmpty() ? "" : " ") + word);
					}
				}
			}
			map.put(s, res);
			return res;
		}
}
