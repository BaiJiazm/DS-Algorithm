#include<iostream>
#include<vector>
using namespace std;

/*
    暴力性质DFS深搜回溯穷举，time:9ms;
*/
class Solution {
	public:
		int findMinStep(string board, string hand) {
			int boardLen=board.length();
			int handLen=hand.length();
			if(boardLen==0)
				return 0;
			else if (handLen==0)
				return -1;
			vector< pair<int,int> >bd;
			helpConvert(board,bd);
			vector< int >hd(5,0);
			for (int i=0; i<hand.length(); ++i) {
				++hd[colorInt(hand[i])];
			}
			this->ans=INT_MAX;
			minBall(bd,hd,0);
			return this->ans==INT_MAX?-1:this->ans;
		}
	private:
		int ans;
		int colorInt(char ch) {
			if (ch=='R')
				return 0;
			else if (ch=='Y')
				return 1;
			else if (ch=='B')
				return 2;
			else if (ch=='G')
				return 3;
			else if (ch=='W')
				return 4;
		}

		void helpConvert(string str,vector< pair<int,int> >&v) {
			for (int i=0; i<str.length(); ++i) {
				int cint=colorInt(str[i]);
				if (v.size()==0||cint!=v.back().first)
					v.push_back(make_pair(cint,1));
				else
					++v.back().second;
			}
		}

		void minBall(vector< pair<int,int> >&bd,vector< int>&hd,int useBall) {
			for (int i=0; i<hd.size(); ++i) {
				int &pr=hd[i];
				if (pr) {
					for (int j=0; j<bd.size(); ++j) {
						if (i==bd[j].first) {
							vector< pair<int,int> >nextbd(bd);
							nextbd[j].second++;
							if(nextbd[j].second>=3) {
								int left=j-1,right=j+1;
								while(left>=0&&right<nextbd.size()&&nextbd[left].first==nextbd[right].first&&nextbd[left].second+nextbd[right].second>=3)
									--left,++right;
								//一定要考虑到可能1+1=2的情况
								if (left>=0&&right<nextbd.size()&&nextbd[left].first==nextbd[right].first) {
									nextbd[left].second+=nextbd[right].second;
									++right;
								}
								nextbd.erase(nextbd.begin()+left+1,nextbd.begin()+right);
							}
							if (nextbd.empty()) {
								this->ans=min(this->ans,useBall+1);
								return ;
							} else if (useBall<ans) {
								--pr;
								minBall(nextbd,hd,useBall+1);
								++pr;
							}
						}
					}
				}
			}
		}
};

int main() {
	Solution s;
	cout<<s.findMinStep("WWRRBBWW","WRBRW");
	return 0;
}




/*
    此处更上边方法一样，只是代码更简洁一点，但是更加耗时    time:36ms
*/
class Solution {
	public:
		int findMinStep(string board, string hand) {
			int boardLen=board.length();
			int handLen=hand.length();
			if(boardLen==0)
				return 0;
			else if (handLen==0)
				return -1;
			vector< pair<int,int> >bd;
			for (int i=0; i<board.length(); ++i)
				if (bd.size()==0||board[i]!=bd.back().first)
					bd.push_back(make_pair(board[i],1));
				else
					++bd.back().second;

			vector< pair<int,int> >hd;
			for (int i=0; i<hand.length(); ++i)
				hd.push_back({hand[i],1});

			this->ans=INT_MAX;
			minBall(bd,hd,0);
			return this->ans==INT_MAX?-1:this->ans;
		}
	private:
		int ans;
		void minBall(vector< pair<int,int> >&bd,vector< pair<int,int> >&hd,int useBall) {
			for (int i=0; i<hd.size(); ++i) {
				pair<int,int> &pr=hd[i];
				if (pr.second) {
					for (int j=0; j<bd.size(); ++j) {
						if (pr.first==bd[j].first) {
							vector< pair<int,int> >nextbd(bd);
							nextbd[j].second++;
							if(nextbd[j].second>=3) {
								int left=j-1,right=j+1;
								while(left>=0&&right<nextbd.size()&&nextbd[left].first==nextbd[right].first&&nextbd[left].second+nextbd[right].second>=3)
									--left,++right;
								//一定要考虑到可能1+1=2的情况
								if (left>=0&&right<nextbd.size()&&nextbd[left].first==nextbd[right].first) {
									nextbd[left].second+=nextbd[right].second;
									++right;
								}
								nextbd.erase(nextbd.begin()+left+1,nextbd.begin()+right);
							}
							if (nextbd.empty()) {
								this->ans=min(this->ans,useBall+1);
								return ;
							} else if (useBall<ans) {
								--pr.second;
								minBall(nextbd,hd,useBall+1);
								++pr.second;
							}
						}
					}
				}
			}
		}
};


#define MAX_STEP 6
class Solution {
	public:
		int findMinStep(string board, string hand) {
			sort(hand.begin(), hand.end());
			int res = helper(board, hand);
			return res > hand.size() ? -1 : res;
		}

		int helper(string b, string h) {
			if (b.empty()) return 0;
			if (h.empty()) return MAX_STEP;
			int res = MAX_STEP;
			for (int i = 0; i < h.size(); i++) {
				int j = 0;
				int n = b.size();
				while (j < n) {
					int k = b.find(h[i], j);
					if (k == string::npos) break;
					if (k < n-1 && b[k] == b[k+1]) { // 2 consecutive balls with same color on board
						string nextb = shrink(b.substr(0, k) + b.substr(k+2)); // shrink the string until no 3 or more consecutive balls in same color
						if (nextb.empty()) return 1; // this is the best result for current board, no need to continue
						string nexth = h;
						nexth.erase(i, 1); // remove the used ball from hand
						res = min(res, helper(nextb, nexth) + 1);
						k++;
					} else if (i > 0 && h[i] == h[i-1]) { // 2 balls with same color in hand
						string nextb = shrink(b.substr(0, k) + b.substr(k+1)); // shrink the string until no 3 or more consecutive balls in same color
						if (nextb.empty()) return 2;  // this is the best result for current board, no need to continue
						string nexth = h;
						nexth.erase(i, 1); // remove the used balls from hand
						nexth.erase(i-1, 1);
						res = min(res, helper(nextb, nexth) + 2);
					}
					j = k + 1;
				}
			}
			return res;
		}

		string shrink(string s) {
			while(s.size() > 0) {
				int start = 0;
				bool done = true;
				for (int i = 0; i <= s.size(); i++) {
					if (i == s.size() || s[i] != s[start]) {
						if (i - start >= 3) {
							s = s.substr(0, start) + s.substr(i);
							done = false;
							break;
						}
						start = i;
					}
				}
				if (done) break;
			}
			return s;
		}
};
