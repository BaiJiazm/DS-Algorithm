class Solution {
	public:
		int maxDistance(vector<vector<int>>& arrays) {
			vector<pair<int,int>>ap;
			for(int i=0; i<arrays.size(); ++i) {
				ap.push_back({arrays[i].front(),i});
				ap.push_back({arrays[i].back(),i});
			}
			sort(ap.begin(),ap.end());
			return ap.front().second!=ap.back().second?ap.back().first-ap.front().first:
			       max(ap.back().first-app[1].first,ap[ap.size()-2].first-ap.front().first);
		}
};

class Solution {
	public:
		int maxDistance(vector<vector<int>>& arrays) {
			int m=arrays.size() ;
			int m1=arrays[0][0] ;
			int m2=arrays[0][arrays[0].size()-1] ;
			int ans=0 ;
			for(int i=1; i<m; i++) {
				ans=max(ans,abs(m1-arrays[i][arrays[i].size()-1])) ;
				ans=max(ans,abs(m2-arrays[i][0])) ;
				m1=min(m1,arrays[i][0]) ;
				m2=max(m2,arrays[i][arrays[i].size()-1]) ;
			}
			return ans ;
		}
};
