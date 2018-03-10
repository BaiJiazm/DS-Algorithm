/*
	对于很多贪心算法，运用贪心算法前都需要使序列某种性质“有序”，按照怎样的顺序排列很关键。差不多有以下几种：
	1.对于单纯int,这种一般很简单，“有序”只有増或减，不难想出。
	2.pair<int,int>类型，有按first或second大小、first+second、first<&second>、second>&frist<序列等。
	3.pari<string,string>类型，典型有first连接second.
	反复强调：双向思维。有一种思维，一定伴随着另一种逆向的方法。 
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
