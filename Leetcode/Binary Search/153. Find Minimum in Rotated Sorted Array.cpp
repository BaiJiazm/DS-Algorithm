class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1,mid;
        while(left<right){
        	mid=(left+right)>>1;
        	if(nums[mid]<nums[right])
        		right=mid;
        	else 
        		left=mid+1;
        }
        return nums[left];
    }
};
