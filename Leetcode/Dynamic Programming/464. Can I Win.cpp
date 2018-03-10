#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<numeric>
using namespace std;

//LeetCode discuss区答案之一，也是十分精彩
class Solution {
	unordered_map<unsigned int, bool> cache;
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (maxChoosableInteger >= desiredTotal) return true;
		//the sum of all available numbers are less than desireTotal, which means it cannot reach the desireTotal
		if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;
		unsigned int used = (1 << maxChoosableInteger) - 1; // use bit to record which number has been used (bit '1' means available, bit '0' means used)
		return play(desiredTotal, used, maxChoosableInteger);
	}
	bool play(int target, unsigned int used, int size) {
		if (cache.find(used) != cache.end()) return cache[used];
		//exist available integer >= target, return true
		if (target - 1<size && (used > (1 << target - 1))) {
			cache[used] = true;
			return true;
		}
		int bit = 1;
		for (int i = 0; i<size; i++, bit <<= 1) {
			if ((used & bit) == 0) continue; // the (i+1)th bit is '0', means (i+1) is used
			used ^= bit;
			if (!play(target - i - 1, used, size)) {
				used |= bit;
				cache[used] = true;
				return true;
			}
			used |= bit;
		}
		cache[used] = false;
		return false;
	}
};

/*网上大神写的比较好的，对DP问题理解和运用到位
http://qkxue.net/info/195697/LeetCode-Can-Win-464

*/

class Solution {
public:
	bool miniMax(int status, vector<unordered_map<int, bool> > &dp, int goal, int maxn)
	{
		if (dp[goal - 1].find(status) != dp[goal - 1].end())//该状态已经被搜索过
			return dp[goal - 1][status];
		for (int i = maxn - 1; i >= 0; i--)
		{
			if (status & (1 << i))//遍历每个数字，如果该数字还没被使用 
			{
				//亦或，把该位变0表示使用该数字
				if (i + 1 >= goal || !miniMax(status ^ (1 << i), dp, goal - i - 1, maxn)) //如果当前已经能实现目标，或对方接下来不能赢
				{
					dp[goal - 1][status] = true;
					return true;
				}
			}
		}
		dp[goal - 1][status] = false;
		return false;
	}

	bool canIWin(int maxChoosableInteger, int desiredTotal)
	{
		if (maxChoosableInteger >= desiredTotal)
			return true;
		if ((maxChoosableInteger)*(maxChoosableInteger + 1) / 2 < desiredTotal)//可选数之和小于目标则必定不可能成功 
			return false;
		int status = (1 << maxChoosableInteger) - 1;//初始状态为全1即全部数字都可用 
		vector<unordered_map<int, bool> > dp(desiredTotal);//记录状态,dp[goal][sta]表示当前可用数为sta，目标为goal时能不能赢 
		return miniMax(status, dp, desiredTotal, maxChoosableInteger);
	}
};


//自己理解后写的，要熟练位操作
class Solution {
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (maxChoosableInteger >= desiredTotal)
			return  true;
		if (maxChoosableInteger*(maxChoosableInteger + 1) / 2 < desiredTotal)
			return false;
		dp.clear();
		dp.resize(desiredTotal + 1);
		int status = (1 << maxChoosableInteger) - 1;
		return CanIWin(status, maxChoosableInteger, desiredTotal);
	}
private:
	vector<unordered_map<int, bool>>dp;
	bool CanIWin(int status, int maxi, int goal) {
		if (dp[goal].find(status)!=dp[goal].end())
			return dp[goal][status];
		int i;
		for (i = maxi; i; --i)
			if (1 & status >> (i - 1))
				if (i >= goal || !CanIWin(status ^ 1 << (i - 1), maxi, goal - i)) {
					dp[goal][status] = true;
					return true;
				}
		dp[goal][status] = false;
		return false;
	}
};