/*
	��Ŀ���壺����С����ʹ�ð���k�����������е�����һ��Ԫ�ء�

	�����Ŀ���������ر��ѵ���Ŀ�����ǽ���һ��Сʱ��û����������
	ԭ��
		1. ��̬��ǰ�����Ƚ�˳�����еćNɪ�������������Ժ�ܶྺ�����ܶ����У���ʱ���Ҫ�����Լ��������ˣ�Ŭ������������̬������Ϻõ�����״̬��ƽ���ġ�
		2. ��ʵ�����Ŀ���Ĵ����Լ���ʱ����һ�£������Լ�����û��ȥ���֣���Ϊ��ʱ��ǰ������һ��deque��ص���Ŀ��һֱ������ط��򿿣������ӡ�����
			��ס��ѧ����ǰ������Ŀ��˼��ͷ�������Ҫ�ģ����������հ����Ҫ��ĳЩ�����ľɷ������������������ϣ�����������������

	����������k��ȡֵΪ[1:3500],�������������㷨�ĸ��Ӷ�һ��ΪO(n^2)��O(logn)�������������ж��Ԫ�أ��ؼ����������Ի�������nlog��ء��������ȶ��л�������
	 �ٽ���һ�²����ǣ�ÿһ�������ж������һ�������Խ�����뵽���ȶ��л���������ʼʱ����һ����ʼ�⣬ÿ���ó���С���������Ԫ�أ�ֱ��ĳ������Ϊ�ա�
*/

//����˼·һ����ʵ�ַ�ʽ��ͬ��

//���ȶ��з���
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

//multiset��multimap����
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
