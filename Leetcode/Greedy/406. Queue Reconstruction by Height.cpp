/*
	���ںܶ�̰���㷨������̰���㷨ǰ����Ҫʹ����ĳ�����ʡ����򡱣�����������˳�����кܹؼ�����������¼��֣�
	1.���ڵ���int,����һ��ܼ򵥣�������ֻ�Љ���������������
	2.pair<int,int>���ͣ��а�first��second��С��first+second��first<&second>��second>&frist<���еȡ�
	3.pari<string,string>���ͣ�������first����second.
	����ǿ����˫��˼ά����һ��˼ά��һ����������һ������ķ����� 
*/
bool cmp(const pair<int,int>&p1,const pair<int,int>&p2) {
	return p1.first>p2.first?true:p1.first==p2.first?p1.second<p2.second:false;
}
class Solution {
	public:
		vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
			sort(people.begin(),people.end(),cmp);
			vector<pair<int,int>>ans;
			for(auto &p:people)
				ans.insert(ans.begin()+p.second,p);
			return ans;
		}
};
