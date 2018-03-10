class Solution {
	public:
		int findMinArrowShots(vector<pair<int, int>>& points) {
			sort(points.begin(),points.end());
			int cnt=0;
			int i,j,r;
			for(i=0; i<points.size(); i=j,++cnt) {
				r=points[i].second;
				for(j=i+1; j<points.size()&&points[j].first<=r; ++j)
					r=min(r,points[j].second);	//第一次提交少了这一句，考虑不周到。
			}
			return cnt;
		}
};
