#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
	�б�Ҫ�ܽ�һ�¶������淶�������Լ��ܿ�֪����˼·���������˺ܶ�ʱ���ac������ԭ��
	1.	����д��û�й̶�������һЩ��Ŀ���ܱ߽������������󣬾���ʼ������Լ�飬������ʱ���������Ŀ�ж������һ���ƫ�
		���׳�����ʱ�˰�������ȷ���±�Ϻá�
	2.	����������mod=1e9+7	������1e9+9
	3.	j-i���ַ�Ӧ�ٶۣ�̫������
*/
class Solution {
	public:
		int kInversePairs(int n, int k) {
#define MOD 1000000007
			vector<vector<int>>dp(n+1,vector<int>(k+1,0));
			//����д���� Memerry Limit Error !
			//vector<vector<int>>dp(1005,vector<int>(1005,0));

			dp[1][0]=1;
			for(int i=2; i<=n; ++i) {
				dp[i][0]=1;
				int maxk=i*(i-1)>>1;
				for(int j=1; j<=min(k,maxk); ++j) {
					dp[i][j]=(dp[i][j-1]+dp[i-1][j])%MOD+MOD;
					if(j-i>=0)
						dp[i][j]-=dp[i-1][j-i];
					dp[i][j]%=MOD;
				}
			}
			return dp[n][k];
		}
};

//discuss�����
//class Solution {
//public:
//    int kInversePairs(int n, int k) {
//        vector<vector<int>> dp(n+1, vector<int>(k+1));
//        dp[0][0] = 1;
//        for(int i = 1; i <= n; ++i){
//            dp[i][0] = 1;
//            for(int j = 1; j <= k; ++j){
//                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
//                if(j - i >= 0){
//                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + mod) % mod;
//                    //It must + mod, If you don't know why, you can check the case 1000, 1000
//                }
//            }
//        }
//        return dp[n][k];
//    }
//private:
//    const int mod = pow(10, 9) + 7;
//};

int main() {
	Solution s;
	cout<<s.kInversePairs(2,0)<<endl;
	return 0;
}
