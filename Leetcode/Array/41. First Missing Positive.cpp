/*
	凭借自己的才智思考出来真的兴奋。
	一般这种没有特定算法的题目都是从其特有性质进行启发思考，归纳其性质和猜测得到答案。
	注意逻辑严密性。 
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
