/*	Discuss ��ȷ��

��Ŀ���壺�����ɴ�д��ĸ����������ж�������ظ�����ͬ���������n������ִ�У��п����ڣ�����С�����������ִ�С�

	��һ��Ӧ����������Ӧ���� Greedy Algorithm �����Ǵ���ԭ�����£�
	1.	̰���㷨Ӧ�����Զ����£����������ӽṹ��̰��ѡ�����ʣ�����ʵ��ʱҲӦ����ˣ��������
	2.	����˼·���¶ԣ�����û����ѭ̰��ѡ�����ʣ���������ڵ��������������̰��ѡ���޷���֤��ȷ��
	3.	OJ����һ���ؼ�����Ϣ�ǲ������������кܴ���������ú͹������á� 
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
