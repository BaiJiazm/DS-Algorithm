/*
	这道题目两次过了，但是感觉还是差了一点，主要是方法上：
		1. 对于一个算法来说，还是要多多运用数学的严谨性，不要随心所想，然后觉得可以一试，随便找个例子验证正确，然后就觉得可以了。这样做对于算法和思维的提高
		均没有益处。
		2，对于所有算来说都一样，要学会证明、肯定一个算法是正确的或者不正确的。
		3. 二分搜索算法的本质是分治法思想，把一个大问题转化为相同子问题，直到化解为一个可以直观判断的问题，其正确性可通过数学归纳法。
		4. 对于很多二分搜索变形，其思维策略和正确性证明是一样的，只是几处可能变化：
		left<=right,left<right;	
		中间的判断分类：[left]<[right],[left]==[right],[left]>[right];
		left=mid,left=mid+1;
		right=mid,right=mid+1;
		最后的返回值一般为[left]; 
		以上几处都要根据具体题目性质加以修改，核心是分解的子问题区间中要包含目标解，否则结束或错误。
		递归终止的底层是n=1和n=2的情况。
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
    	if(nums.front()<nums.back())
    		return nums.front();
    	else if(nums.front()==nums.back()){
    	    if(nums.size()<=2)
    	        return nums.front();
    		vector<int>nleft(nums.begin(),nums.begin()+nums.size()/2);
    		vector<int>nright(nums.begin()+nums.size()/2,nums.end());
    		return min(findMin(nleft),findMin(nright)); 
    	}
        int left=0,right=nums.size()-1;
        int mid;
        while(left!=right&&left+1!=right){
        	int mid=(left+right)>>1;
        	if(nums[left]<=nums[mid])
        		left=mid;
        	else 
        		right=mid;
        }
        return nums[right]; 
    }
};


class Solution {
public:
    int findMin(vector<int> &num) {
        int lo = 0;
        int hi = num.size() - 1;
        int mid = 0;
        
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (num[mid] > num[hi]) {
                lo = mid + 1;
            }
            else if (num[mid] < num[hi]) {
                hi = mid;
            }
            else { // when num[mid] and num[hi] are same
                hi--;
            }
        }
        return num[lo];
    }
};
