#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<tr1/unordered_set>
#include<tr1/unordered_map>
#include<algorithm>
using namespace std;
using namespace std::tr1;

class Solution {
	public:
		void DFS(set<pair<string, int> >& st, vector<string> vec) {//临时变量不能作为引用传递
			set<pair<string,int> >::iterator it;
			for(it=st.begin(); it!=st.end(); ++it) {
				pair<string,int> val=*it;
				vec.push_back(val.first);
				if(hash.count(val.first)==0) {
					reverse(vec.begin(), vec.end());
					return result.push_back(vec);
				}
				DFS(hash[val.first], vec);
				vec.pop_back();
			}
		}
		vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
			unordered_set<string>wordL;
			for(auto a:wordList)
				wordL.insert(a);
			if (wordL.count(endWord)==0)
				return vector<vector<string>>({});
			return findLadder(beginWord,endWord,wordL);
		}

		vector<vector<string> > findLadder(string beginWord, string endWord, unordered_set<string> &wordList) {
			wordList.insert(endWord);
			wordList.erase(beginWord);
			que.push(make_pair(beginWord, 1));
			while(!que.empty()) {
				auto val = que.front();
				que.pop();
				for(int i = 0; i < val.first.size(); i++) {
					string tem = val.first;
					for(int j =0; j < 26; j ++) {
						tem[i] = 'a' + j;
						if(wordList.count(tem)) {
							que.push(make_pair(tem, val.second+1));
							wordList.erase(tem);
							hash[tem].insert(val);
						} else if(hash.count(tem)&&hash[tem].begin()->second==val.second)
							hash[tem].insert(val);
					}
				}
			}
			DFS(hash[endWord], vector<string> {endWord});
			return result;
		}
		vector<vector<string> > result;
		unordered_map<string, set<pair<string, int> > > hash;
		queue<pair<string, int> > que;
};


int main() {
	string beginWord = "hit";
	string endWord = "cog";
	vector<string>wordList = {"hot","dot","dog","lot","log","cog"};
	Solution s;
	s.findLadders(beginWord,endWord,wordList);
	return 0;
}
