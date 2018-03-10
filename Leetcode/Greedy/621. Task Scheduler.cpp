/*	Discuss 正确答案

题目大义：给定由大写字母代表的任务有多个且有重复，相同任务间必须隔n个周期执行，有空周期，求最小周期完成任务执行。

	第一反应，调度问题应该是 Greedy Algorithm 。但是错误原因如下：
	1.	贪心算法应该是自顶向下，符合最优子结构和贪心选择性质，具体实现时也应该如此，否则错误。
	2.	本题思路大致对，但是没有遵循贪心选择性质，对最多周期的任务进行了整体贪心选择，无法保证正确。
	3.	OJ比赛一个关键的信息是测试数据量，有很大的启发作用和估计作用。 
*/
class Solution {
	public:
		int leastInterval(vector<char>& tasks, int n) {
			unordered_map<char, int> counts;
			for (char t : tasks) {
				counts[t]++;
			}
			priority_queue<int> pq;
			for (pair<char, int> count : counts) {
				pq.push(count.second);
			}
			int alltime = 0;
			int cycle = n + 1;
			while (!pq.empty()) {
				int time = 0;
				vector<int> tmp;
				for (int i = 0; i < cycle; i++) {
					if (!pq.empty()) {
						tmp.push_back(pq.top());
						pq.pop();
						time++;
					}
				}
				for (int cnt : tmp) {
					if (--cnt) {
						pq.push(cnt);
					}
				}
				alltime += !pq.empty() ? cycle : time;
			}
			return alltime;
		}
};


//My Error Code
class Solution {
	public:
		int leastInterval(vector<char>& tasks, int n) {
			if(n==0)
				return tasks.size();
			int  countChar[128]= {0};
			for(auto &a:tasks)
				++countChar[a];
			priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>>q;
			for(int i='A'; i<='Z'; ++i)
				if(countChar[i])
					q.push({countChar[i],i});
			int ans=0;
			int leave,insert,canHold;
			while(!q.empty()) {
				pair<int,int>p=q.top();
				q.pop();
				ans+=(p.first-1)*(n+1);
				canHold=(p.first-1 )*n;
				vector<pair<int,int>>temv;
				if(p.first>1)
					temv.push_back({1,p.second});
				else
					++ans;
				while(canHold>0&&!q.empty()) {
					pair<int,int>tp=q.top();
					q.pop();

					if(tp.first==p.first) {
						leave=1;
						insert=tp.first-1;
					} else if(tp.first>canHold) {
						leave=tp.first-canHold;
						insert=canHold;
					} else {
						leave=0;
						insert=tp.first;
					}

					if(leave)
						temv.push_back({leave,tp.second});
					canHold-=insert;
				}
				for(auto &a:temv)
					q.push(a);
			}
			return ans;
		}
};
