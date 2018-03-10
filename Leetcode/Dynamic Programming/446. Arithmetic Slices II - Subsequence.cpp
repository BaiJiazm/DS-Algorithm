#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

#include<algorithm>
#include<functional>
#include<numeric>
#include<bitset>
using namespace std;

//�Լ�д�ģ�ֻͨ����39/101��case	���磺2,2,3,4��ͨ����
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int size = A.size();
		vector<unordered_map<int, int>>dp(size);
		int ans = 0;
		int i, j;
		for (i = 0; i < size; ++i)
			for (j = i - 1; j >= 0; --j) {
				int dif = A[i] - A[j];
				if (dp[j].find(dif) == dp[j].end())
					dp[i][dif] = 0;
				else
					ans += dp[i][dif] = dp[j][dif] + 1;
			}
		return ans;
	}
};

//LeetCode discuss��	����
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.empty()) return 0;
		vector<unordered_map<int, int>> dp(A.size());//[index, [difference, count]]

		int res = 0;
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				//������ע������������Ҫ��[0,2000000000,-294967296]	�迼���������ݵļ��˷�Χ
				if ((long)A[i] - (long)A[j] > INT_MAX || (long)A[i] - (long)A[j] < INT_MIN) continue;// do not ignore this step, it will help you save time & space to pass OJ.
				int dif = A[i] - A[j];
				dp[i][dif] += 1;
				if (dp[j].find(dif) != dp[j].end()) {
					dp[i][dif] += dp[j][dif];
					res += dp[j][dif];
				}
			}
		}
		return res;
	}
};

int main()
{
	vector<int>A({ 2, 2,2});
	Solution s;
	cout << s.numberOfArithmeticSlices(A);
	system("pause");
	return 0;
}