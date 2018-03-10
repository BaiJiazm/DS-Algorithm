/*
	题目大义：求最小区间使得包含k个有序数组中的至少一个元素。

	这道题目不能算作特别难的题目，但是将近一个小时都没有做出来！
	原因：
		1. 心态。前面的题比较顺利，有的嘚瑟，这种心理在以后很多竞赛可能都会有，这时候就要发挥自己的情商了，努力调整自我心态，进入较好的做题状态，平常心。
		2. 其实这道题目最后的答案与自己做时基本一致，但是自己就是没有去下手，因为当时被前面做过一道deque相关的题目，一直在向相关方向靠，结果入坑。所以
			记住并学会以前做过题目的思想和方法是重要的，但绝不是照搬或者要被某些以往的旧方法所束缚，当机立断，具体问题具体分析。

	分析方法：k的取值为[1:3500],考虑最大情况，算法的复杂度一般为O(n^2)或O(logn)，由于数组中有多个元素，关键是有序，所以基本上是nlog相关。考虑优先队列或红黑树，
	 再进行一下步考虑，每一个数组中都需包含一个，可以将其放入到优先队列或红黑树，初始时构成一个初始解，每次拿出最小，加入其后元素，直到某个数组为空。
*/

//两者思路一样，实现方式不同。

//优先队列方法
class Solution {
	public:
		vector<int> smallestRange(vector<vector<int>>& nums) {
			vector<int>pid(nums.size(),0);
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
			int ansStart,ansEnd,start,end=INT_MIN;
			int i,pn,nextId;

			for(i=0; i<nums.size(); ++i) {
				Q.push({nums[i][0],i});
				end=max(end,nums[i][0]);
			}
			ansStart=start=Q.top().first;
			ansEnd=end;
			while(++pid[Q.top().second]<nums[Q.top().second].size()) {
				pn=Q.top().second;
				Q.pop();
				nextId=pid[pn];
				Q.push({nums[pn][nextId],pn});
				start=Q.top().first;
				end=max(end,nums[pn][nextId]);
				if(ansEnd-ansStart>end-start)
					ansEnd=end,ansStart=start;
			}
			return {ansStart,ansEnd};
		}
};

//multiset或multimap方法
class Solution {
	public:
		vector<int> smallestRange(vector<vector<int>>& nums) {
			vector<int>pid(nums.size(),0);
			multiset<pair<int,int>>ms;
			int ansStart,ansEnd,start,end=INT_MIN;
			int i,pn,nextId;

			for(i=0; i<nums.size(); ++i)
				ms.insert({nums[i][0],i});

			ansStart=start=ms.begin()->first;
			ansEnd=end=(--ms.end())->first;
			while(++pid[ms.begin()->second]<nums[ms.begin()->second].size()) {
				pn=ms.begin()->second;
				ms.erase(ms.begin());
				nextId=pid[pn];
				ms.insert({nums[pn][nextId],pn});
				start=ms.begin()->first;
				end=(--ms.end())->first;
				if(ansEnd-ansStart>end-start)
					ansEnd=end,ansStart=start;
			}
			return {ansStart,ansEnd};
		}
};
