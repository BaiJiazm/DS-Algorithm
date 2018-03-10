#include "headFile"

/*
	����ĿӦ����һ�ྭ�䱩����n!����Ŀ�еĵ��͡�
	һ�㱩����ٽ����Ҫn!�Ĵ�����Ŀ��һ�㶼������DP�㷨n^3�����������Ŀ����ǰ���ĳ����Ŀ����������ˣ��Լ�CCF��ѹ�����룬ʯ����Ϸ����Ŀ���ơ�
	���������ĿӦ��˵��Ϊһ�㡣����������Ŀ�������ⶼ���Էֿ����ǣ����������Ŀ�е㲻һ������ʵ��ĳ�ֽǶ���������һ���ġ�����ôȥ��⣡

	˼����ʽһ�������֣�
		1.�Ե����ϣ��Ӽ򵥵������⿼�ǣ����Ƶ��������ս⣩����������������ױ���⡣nums[i]Ӧ�ú�����1�����õȼۣ�
		2.�Զ����£����������������˼�����С��ģ����ͬ�����������󣬴����������εõ��������

    һ��˵�������ַ�ʽ�����Ƕ������ڵģ�Ӧ�����ศ��ɵģ���ͬ˼���ġ�

    �������д�������֣�
		1.�����ҵ�������
		2.���ҵ����������
		3.��б�ߵ�ֱ�ǵ�������

*/

//д��һ����б�ߵ�ֱ�ǵ�������
class Solution {
	public:
		int maxCoins(vector<int>& nums) {
			int size=nums.size();
			if (size==0)
				return 0;
			nums.insert(nums.begin(),1);
			nums.insert(nums.end(),1);
			vector<vector<int>>dp(size+2,vector<int>(size+2,0));
			for (int len=1; len<=size; ++len) {
				for (int i=1; i<=size+1-len; ++i) {
					for (int j=i; j<i+len; ++j) {
						dp[i][i+len-1]=max(dp[i][i+len-1],nums[j]*nums[i-1]*nums[i+len]+dp[i][j-1]+dp[j+1][i+len-1]);
					}
				}
			}
			return dp[1][size];
		}
};

//д�����������ҵ�������
class Solution {
	public:
		int maxCoins(vector<int>& nums) {
			int size=nums.size();
			if (size==0)
				return 0;
			nums.insert(nums.begin(),1);
			nums.insert(nums.end(),1);
			vector<vector<int>>dp(size+2,vector<int>(size+2,0));
			for(int j=1; j<=size; ++j) {
				for (int i=j; i>0; --i) {
					for (int k=i; k<=j; ++k)
						dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]);
				}
			}
			return dp[1][size];
		}
};
