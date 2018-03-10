#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
#include<algorithm>
#include<numeric>
using namespace std;

//�ⷨһ���Լ�д��
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int>dp(num + 1, 0);
		for (int i = 1; i <= num; ++i)
			dp[i] = (i & 1) + dp[i >> 1];
		return dp;
	}
};

//�ⷨ����discuss
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> ret(num + 1, 0);
		for (int i = 1; i <= num; ++i)
			ret[i] = ret[i&(i - 1)] + 1;
		return ret;
	}
};

//�ⷨ����discuss
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> ret(num + 1, 0);
		ret[0] = 0;
		int pow = 1;
		for (int i = 1, t = 0; i <= num; i++, t++) {
			if (i == pow) {
				pow *= 2;
				t = 0;
			}
			ret[i] = ret[t] + 1;
		}
		return ret;
	}
};