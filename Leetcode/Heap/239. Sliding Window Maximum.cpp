/*
	第一次用到双端队列（deque）,兼具栈和队列的所有性质，是一种融合。
	在与元素大小相关问题时，栈是一种常用的数据结构；
	与数据顺序有关时，队列是一种常用的数据结构。
*/
class Solution {
	public:
		vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			deque<int>dq;
			vector<int>res;
			for(int i=0; i<nums.size(); ++i) {
				if(!dq.empty()&&dq.front()+k<i+1)
					dq.pop_front();
				while(!dq.empty()&&nums[i]>nums[dq.back()])
					dq.pop_back();
				dq.push_back(i);
				if(i+1>=k)
					res.push_back(nums[dq.front()]);
			}
			return res;
		}
};

class Solution {
	public:
		vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			deque<int> dq;
			vector<int> ans;
			for (int i=0; i<nums.size(); i++) {
				if (!dq.empty() && dq.front() == i-k) dq.pop_front();
				while (!dq.empty() && nums[dq.back()] < nums[i])
					dq.pop_back();
				dq.push_back(i);
				if (i>=k-1) ans.push_back(nums[dq.front()]);
			}
			return ans;
		}
};
