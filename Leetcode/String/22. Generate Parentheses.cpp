#include<iostream>
#include<string>
#include<vector>
using namespace std;
//自己写的非递归算法，n<=3时正确，但是是错误的答案。没有经过严格的证明，经不起考量
//错误情况	( (()) () )	会出现两次，
class Solution1 {
	public:
		vector<string> generateParenthesis(int n) {
			vector<vector<string> >strs(n+2);
			strs[1].push_back("()");
			for (int i=1; i<n; ++i)
				for (int j=0; j<strs[i].size(); ++j) {
					int pos=0;
					while(1) {
						strs[i+1].push_back('('+strs[i][j].substr(0,pos)+')'+strs[i][j].substr(pos,strs[i][j].length()-pos));
						pos=strs[i][j].find_first_not_of(')',pos);
						if (pos==string::npos)
							break;
						pos=strs[i][j].find_first_of(')',pos);
					}
				}
			return strs[n];
		}
};

//这类求所有情况的题目，一般是考虑递归+回溯
//递归回溯题目，递归写法

class Solution {
	public:
		vector<string> generateParenthesis(int n) {
			vector<string> res;
			addingpar(res, "", n, 0);
			return res;
		}
		void addingpar(vector<string> &v, string str, int n, int m) {
			if(n==0 && m==0) {
				v.push_back(str);
				cout<<str<<endl;
				return;
			}
			//顺序可以交换
			if(n > 0) {
				addingpar(v, str+"(", n-1, m+1);
			}
			if(m > 0) {
				addingpar(v, str+")", n, m-1);
			}
		}
};

int main() {
	Solution s;
	vector<string>strs=s.generateParenthesis(4);
	return 0;
}
