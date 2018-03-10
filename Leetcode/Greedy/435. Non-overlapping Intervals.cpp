/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool operator <(const Interval &I1,const Interval &I2) {
	return I1.start<I2.start?true:I1.start==I2.start?I1.end<I2.end:false;
}

class Solution {
	public:
		int eraseOverlapIntervals(vector<Interval>& intervals) {
			sort(intervals.begin(),intervals.end());
			int ans=0;
			int i,r;
			r=intervals.size()>0?intervals[0].end:0;
			for(i=1; i<intervals.size(); ++i) {
				if(r>intervals[i].start) {
					++ans;
					r=min(r,intervals[i].end);
				} else
					r=intervals[i].end;
			}
			return ans;
		}
};
