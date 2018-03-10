#include <vector>
#include <algorithm>
using namespace std;
//��Ŀ������
//
//��Ǯ�Ի��������ٵ���Ǯ������ȡĿ���������
//
//����˼·��
//
//��̬�滮���
//
//1��dp[i]��ʾ�Ի�Ŀ��i���������Ӳ����Ŀ��
//
//2����������еĶ�̬�滮��ʽΪdp[i + coins[j]] = min(dp[i + coins[j], dp[i] + 1)��
//
//ʵ�ֳ���
//
//C++�汾

// CPP  
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0) {
			return 0;
		}
		// ��ʼ������Ϊ 0����������Ǯ����Ϊ 1   
		// initialized vector f with 0 then fill the coin value as 1  
		vector<int> f(amount + 1, 0);
		for (int i = 0; i < coins.size(); ++i) {
			if (coins[i] <= amount) {
				f[coins[i]] = 1;
			}
		}
		// ���ܹ��ճ�Ǯ��Ŀ�Ļ����ϣ�������µĿɴճ���Ǯ��������������Ҫ������   
		// for every value which can be added up to, calculate new value and refresh new value's times  
		for (int pos = 0; pos <= amount; ++pos) {
			if (f[pos] == 0) {
				continue;
			}
			for (int i = 0; i < coins.size(); ++i) {
				int value = pos + coins[i];
				if (value <= amount) {
					f[value] = (f[value] == 0) ?
						(f[pos] + 1) : min(f[value], f[pos] + 1);
				}
			}
		}
		return (f[amount] == 0) ? -1 : f[amount];
	}
};  //Java�汾
//
//public int coinChange(int[] coins, int amount) {
//	int[] dp = new int[amount + 1];
//	final int INF = 0x7ffffffe;
//	// ��ʼ��dp[i]���飬ע���1��ʼ��ʼ��
//	for (int i = 0; i <= amount; i++)
//		dp[i] = INF;
//	dp[0] = 1;
//	// ��̬�滮�������
//	for (int i = 0; i <= amount; i++) {
//		for (int j = 0; j < coins.length; j++) {
//			if (i + coins[j] <= amount)
//				dp[i + coins[j]] = Math.min(dp[i + coins[j]], dp[i] + 1);
//		}
//	}
//	return dp[amount] == INF ? -1 : dp[amount];
//}