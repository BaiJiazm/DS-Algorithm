#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

/*ע�⣺
	����˼·��һ��ʼ����Ȼ���뵽��̰�ģ����ǽ��ַ��������ȴӶ̵�������Ȼ��m��0��n��1���з��䣬����������̰�������ǲ������ģ�
	��Ϊ������111, 1100, 0011��m = 4��n = 4�������Ļ���ֻ�еó����Ϊ1����Ȼ�ǲ��Եġ�
	��ô��Ҫ������ж��ٸ�������ת��Ϊ��̬�滮�е�0 - 1�������⣬
	dp[i][j][k]�������ǰi���ַ���1�ĸ���Ϊj0�ĸ���Ϊk������ַ�����������ô����0 - 1������˼����ǶԵ�i���ַ������ҿ��Բ�ȡȡҲ���Բ�ȡ��ȡ��������
	��ôת�Ʒ���Ϊdp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - ones][k - zeros]), 
	����Ϊiֻ��i - 1�йأ���ô���Ա�Ϊ��ά����dp[i][j] = max(dp[i][j], dp[i �C a][j �C b] + 1).
	dp[m][n]���ǽ����ע�������ʱ���Ǵ����ҵײ���ʼ�����������õ�����Ϣ����ԭ���ģ��������ڸ��ǵ���.
*/

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		//����ѡ��࣬Ҳ����ת��Ϊ0,1��������
		vector<vector<int> >dp(m + 1, vector<int>(n + 1, 0));
		int len = strs.size();
		int i, j;

		for (i = 0; i < len; i++) {
			int zeros = 0, ones = 0;
			string temp = strs[i];
			for (j = 0; j < temp.length(); j++)
				temp[j] == '1' ? ones++ : zeros++;
			//��һ������߽����mС��zeros��������wС��ones������ô��
			//printf("%d,%d\n",m,n);
			for (int k = m; k >= zeros; k--) //һ��Ҫ������
			{
				for (int w = n; w >= ones; w--) //���Ǵ��ҵײ�һֱ��
				{
					//���dp[k][w]ʵ������dp[i-1][k][w]����û��ѡ���i��
					dp[k][w] = max(dp[k][w], dp[k - zeros][w - ones] + 1); //���dp��������
				}
			}
		}
		return dp[m][n];
	}
};