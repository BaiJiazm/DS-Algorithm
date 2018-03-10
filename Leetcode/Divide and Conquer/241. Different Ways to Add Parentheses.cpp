#include<iostream>
#include<vector>
#include<string>
using namespace std;

//分治	递归算法
class Solution {
	public:
		vector<int> diffWaysToCompute(string input) {
			vector<int>result;
			for(int i=0; i<input.length(); ++i) {
				char ch=input[i];
				if(ch=='+'||ch=='-'||ch=='*') {
					vector<int> lresult=diffWaysToCompute(input.substr(0,i));
					vector<int> rresult=diffWaysToCompute(input.substr(i+1));
					for(auto a:lresult)
						for(auto b:rresult)
							if(ch=='-')
								result.push_back(a-b);
							else if(ch=='+')
								result.push_back(a+b);
							else
								result.push_back(a*b);
				}
			}
			if(result.empty())
				result.push_back(stoi(input));
			return result;
		}
};

//DP解法	为什么时间和conquer时间一样？
class Solution {
	public:
		vector<int> diffWaysToCompute(string input) {
			int maxn=(input.length()+1)>>1;
			vector<vector<vector<int>>>dp(maxn,vector<vector<int>>(maxn));
			vector<int>nums;
			vector<char>op;
			int p,np;
			for(p=0; true;) {
				np=input.find_first_of("+-*",p);
				nums.push_back(stoi(input.substr(p,np-p)));
				if(np==string::npos)
					break;
				op.push_back(input[np]);
				p=np+1;
			}
			int n=nums.size();
			int i,j,k,len;
			for(i=0; i<n; ++i)
				dp[i][i]= {nums[i]};

			for(len=1; len<n; ++len)
				for(i=0; i<n-len; ++i) {
					j=i+len;
					for(k=i; k<j; ++k) {
						vector<int>&lv=dp[i][k];
						vector<int>&rv=dp[k+1][j];
						vector<int>&rs=dp[i][j];
						for(auto a:lv)
							for(auto b:rv)
								if(op[k]=='-')
									rs.push_back(a-b);
								else if(op[k]=='+')
									rs.push_back(a+b);
								else
									rs.push_back(a*b);
					}
				}
			return dp[0][n-1];
		}
};

int main() {
	string input="2-1+1";
	Solution s;
	vector<int> ans=s.diffWaysToCompute(input);
	for(auto a:ans)
		cout<<a<<" ";
	return 0;
}
