/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Cmp {
	public:
		bool operator () (const Interval& v1, const Interval& v2) {
			return v1.start<v2.start;
		}
};

class Solution {
	public:
		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
			int s=newInterval.start, e=newInterval.end;
			Interval v1(s, 0);
			Interval v2(e, 0);
			auto a1=upper_bound(intervals.begin(), intervals.end(), v1, Cmp());
			vector<Interval>ans(intervals.begin(), a1);
			if(a1==intervals.begin()||(a1-1)->end<s) {
				ans.push_back(Interval(s, 0));
			}
			auto a2=upper_bound(intervals.begin(), intervals.end(), v2, Cmp());
			if(a2==intervals.begin()||(a2-1)->end<e) {
				ans.back().end=e;
			} else {
				ans.back().end=(a2-1)->end;
			}

			ans.insert(ans.end(), a2, intervals.end());
			return ans;
		}
};
