class Solution {
	public:
		int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
			long long total=0,ans;
			vector<pair<int,int>>dis;
			for(auto a:nuts) {
				int d1=abs(a[0]-tree[0])+abs(a[1]-tree[1]);
				int d2=abs(a[0]-squirrel[0])+abs(a[1]-squirrel[1]);
				dis.push_back({d1,d2});
				total+=d1<<1;
			}
			ans=total+INT_MAX;
			for(auto &a:dis) {
				ans=min(ans,total-a.first+a.second);
			}
			return ans;
		}
};

