class Solution {
	public:
		int findMinArrowShots(vector<pair<int, int>>& points) {
			sort(points.begin(),points.end());
			int cnt=0;
			int i,j,r;
			for(i=0; i<points.size(); i=j,++cnt) {
				r=points[i].second;
				for(j=i+1; j<points.size()&&points[j].first<=r; ++j)
					r=min(r,points[j].second);	//��һ���ύ������һ�䣬���ǲ��ܵ���
			}
			return cnt;
		}
};
