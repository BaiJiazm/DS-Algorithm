/*
	�����̰���㷨����Ŀ��
	�������Σ�
	1.���ǡ���������
	2.long long����Χ�� 
*/ 
class Solution {
	public:
		int minPatches(vector<int>& nums, int n) {
			long long curn=0,cnt=0;
			for(int i=0; curn<n;) {
				if(i<nums.size()&&curn+1>=nums[i])
					curn+=nums[i++];
				else {
					++cnt;
					curn=curn<<1|1;
				}
			}
			return cnt;
		}
};
