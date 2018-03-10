/*
	sweep line���͵���Ŀ�����öѻ���������һ���Ծ�����Ŀ��
	���־���ƽ�ж�ż��Ϣ����Ŀ��һ�㶼���м�¼�Ͳ�����¼�Ĺ��̡���������еõ���Ӧ�𰸡�
	ͨ��x������������ɨ�裬�Ⱥ󽫾��θ߶ȼ��뵽һ������ṹ��multset��heap��mutlimap�ȣ��ʹ�����ɾ���� 
*/
class Solution {
	public:
		vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
			vector<pair<int,int>>height;
			for(auto &b:buildings) {
				height.push_back({b[0],-b[2]});
				height.push_back({b[1],b[2]});
			}
			sort(height.begin(),height.end());
			vector<pair<int,int>>ans;
			multiset<int>mset;
			mset.insert(0);
			int pre=0,cur=0;
			for(auto &b:height) {
				if(b.second<0)
					mset.insert(-b.second);
				else
					mset.erase(mset.find(b.second));
				cur=*mset.rbegin();
				if(cur!=pre) {
					ans.push_back({b.first,cur});
					pre=cur;
				}
			}
			return ans;
		}
};
