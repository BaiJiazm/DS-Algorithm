/*
	�����Ŀ���ι��ˣ����Ǹо����ǲ���һ�㣬��Ҫ�Ƿ����ϣ�
		1. ����һ���㷨��˵������Ҫ���������ѧ���Ͻ��ԣ���Ҫ�������룬Ȼ����ÿ���һ�ԣ�����Ҹ�������֤��ȷ��Ȼ��;��ÿ����ˡ������������㷨��˼ά�����
		��û���洦��
		2��������������˵��һ����Ҫѧ��֤�����϶�һ���㷨����ȷ�Ļ��߲���ȷ�ġ�
		3. ���������㷨�ı����Ƿ��η�˼�룬��һ��������ת��Ϊ��ͬ�����⣬ֱ������Ϊһ������ֱ���жϵ����⣬����ȷ�Կ�ͨ����ѧ���ɷ���
		4. ���ںܶ�����������Σ���˼ά���Ժ���ȷ��֤����һ���ģ�ֻ�Ǽ������ܱ仯��
		left<=right,left<right;	
		�м���жϷ��ࣺ[left]<[right],[left]==[right],[left]>[right];
		left=mid,left=mid+1;
		right=mid,right=mid+1;
		���ķ���ֵһ��Ϊ[left]; 
		���ϼ�����Ҫ���ݾ�����Ŀ���ʼ����޸ģ������Ƿֽ��������������Ҫ����Ŀ��⣬������������
		�ݹ���ֹ�ĵײ���n=1��n=2�������
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
