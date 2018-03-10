/*
	题目大义：给定一些课程时间长度和截至日期，求能无冲突的上课的最大课程数量

	大概是很久没有刷题了，几道贪心都没有做出来。
	这道题目想到用贪心算法来求解应该是比较显而易见的，类似有活动安排问题的最大安排数，但是就是这一点被误导了，
	活动安排问题给定了活动起止时间，而此问题给出的是截至和长度时间，恰恰忽视了一个最为重要的性质：
		1.只要在活动结束前安排都是可以的，若已经安排好的课程，去掉其中某种课程，仍然满足安排。
		2.要使能够安排更多课程，当然是上完一个接着另一个，中途没有空闲间隔时间。

	思考方法：
		1.尽可能的发现具体问题的具体性质，一般从最简单的一些例子中寻找；
		2.分析问题的关键信息，即解题关键。本题来说，关键量无非课程长度、开始时间、结束时间。如何利用，怎样利用都是突破口。
*/

class Solution {
	public:
		int scheduleCourse(vector<vector<int>>& courses) {
			// sort courses by the end date
			sort(courses.begin(),courses.end(),
			[](vector<int> a, vector<int> b) {
				return a.back()<b.back();
			});

			multiset<int> cls; // store lengths of each course we take (could be duplicates!)
			int cursum=0;

			for (int i=0; i<courses.size(); i++) {

				// if we have enough time, we will take this course
				if (cursum+courses[i].front()<=courses[i].back()) {
					cls.insert(courses[i].front());
					cursum+=courses[i].front();
				} else if (*cls.rbegin()>courses[i].front()) {
					// if we don't have enough time, we switch out a longer course
					cursum+=courses[i].front()-*cls.rbegin();
					cls.erase(--cls.end());
					cls.insert(courses[i].front());
				} // if we don't have enough time for course[i],
				//and it's longer than any courses taken, then we ignore it
			}

			return cls.size();
		}
};
