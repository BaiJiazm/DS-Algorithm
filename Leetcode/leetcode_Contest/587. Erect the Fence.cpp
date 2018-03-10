/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#define INF 1e9

bool cmp(const struct Point& p1,const struct Point&p2) {
	return p1.x<p2.x?true:p1.x==p2.x?p1.y<p2.y:false;
}

double krate(const Point &p1,const Point &p2) {
	if(p1.x==p2.x)
		return INF;
	return (p2.y-p1.y)*1.0/(p2.x-p1.x);
}

class Solution {
	public:
		vector<Point> outerTrees(vector<Point>& points) {
			if(points.size()==1)
				return points;
			sort(points.begin(),points.end(),cmp);
			points.push_back(*(points.end()-1));
			vector<Point>res;
			Point &op=points[0];
			double ok=INF,nk;
			res.push_back(op);
			int i,ni;
			for(i=0,ni=1; ni<points.size()-1; ++i) {
				ok=krate(points[i],points[ni]);
				for(++ni;ni<points.size()&&krate(po;++ni)
					
			}
		}
};
