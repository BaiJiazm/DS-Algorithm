/*
	ƾ���Լ��Ĳ���˼����������˷ܡ�
	һ������û���ض��㷨����Ŀ���Ǵ����������ʽ�������˼�������������ʺͲ²�õ��𰸡�
	ע���߼������ԡ� 
*/ 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	int i,p;
    	for(i=0;i<nums.size();++i){
    		for(p=nums[i];p>0&&p<=nums.size()&&nums[p-1]!=p;p=nums[i])
				swap(nums[i],nums[p-1]);
    	}
    	for(i=0;i<nums.size()&&nums[i]==i+1;++i)
			;
		return i+1; 
    }
};
