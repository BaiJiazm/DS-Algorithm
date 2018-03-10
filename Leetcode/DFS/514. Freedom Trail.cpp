#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

/*
	写代码要静得下心，不急不燥，明明这么简单的东西，思路都想好了，还花了那么久去调试。
	都是细小的错误，比如：ringLen---->keyLen,state[0].begin()---->state.begin,++it---->++i;
	想好思路，写代码不急不燥，不急不燥，不急不燥
*/

class mapComp {
	public:
		bool operator ()(const pair<int,int>&p1,const pair<int,int>&p2 ) const {
			return p1.second<p2.second;
		}
};

class Solution {
	public:
		int findRotateSteps(string ring, string key) {
			int keyLen=key.length();
			int ringLen=ring.length();
			string findStr=ring+ring;
			vector< unordered_map<int,int> >state(keyLen+1);
			state[0][0]=0;

			unordered_map<int,int>::iterator it;
			for (int i=0; i<keyLen; ++i) {
				for (it=state[i].begin(); it!=state[i].end(); ++it) {
					int pos=it->first;
					int endPos=pos+ringLen;
					while(1) {
						pos=findStr.find(key[i],pos);
						if (pos!=string::npos&&pos<endPos) {
							int temstep=min(pos-it->first,ringLen-pos+it->first);
							int nextPos=pos%ringLen;
							if (state[i+1].count(nextPos)==0||state[i+1][nextPos]>it->second+temstep)
								state[i+1][nextPos]=it->second+temstep;
							++pos;
						} else
							break;
					}
				}
			}

			return (*min_element(state[keyLen].begin(),state[keyLen].end(),mapComp())).second+keyLen;
		}
};

int main() {
	Solution s;
	cout<<s.findRotateSteps("tawzu","zzzwwwuuutttaaa");
	return 0;
}

//Leetcode Discuss 区答案
class Solution {
	public:
		int findRotateSteps(string ring, string key) {
			int size = ring.size();
			int ksize = key.size();
			unordered_map<char,vector<int>> mp;//stored index of each characters in ring,pay attention to duplcate characters.
			for(int i=0; i<size; ++i) {
				mp[ring[i]].push_back(i);
			}

			vector<vector<int>> dp(ksize+1,vector<int> (size,INT_MAX));// initializing dp vector
			fill(dp[0].begin(),dp[0].end(),0);

			vector<int> tmp(1,0);// starting index

			int res = INT_MAX;
			for(int i=1; i<=ksize; ++i) {
				for(auto it:mp[key[i-1]]) { //
					for(int j=0; j<tmp.size(); ++j) { //Search The shortest distance key[i-1] in ring
						int minDist = min((tmp[j] + size -it)%size,(it + size - tmp[j])%size) + dp[i-1][tmp[j]];// Look at the above explanation
						dp[i][it] =min(dp[i][it],minDist);
						res = (i!=ksize?res:min(res,dp[i][it])); //Can we optimize it?
					}
				}
				tmp = mp[key[i-1]]; //next start is the characters we search in this time
			}
			return res + ksize;
		}
};
