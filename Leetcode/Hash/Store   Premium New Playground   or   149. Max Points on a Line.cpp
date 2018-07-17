/*
//下面这种做法是有问题的，不会通过精度测试。
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& pts) {
        int maxPts = 0;
        for (auto& i:pts) {
          map<Point, int, Comp> count; int dup = 0;
          for (auto& j:pts) {
              int curMax = (i.x==j.x && i.y==j.y)? ++dup : ++count[Point(i.x-j.x,i.y-j.y)]+dup;
              maxPts = max(maxPts, curMax);
          }
        }
        return maxPts;
    }
        
    struct Comp { // comparator for key (slope) in map
        bool operator()(const Point& a, const Point& b) 
        { 
          int64_t diff = (int64_t)a.x*b.y - (int64_t)a.y*b.x; // convert to 64bit int for int overflow
          return (int64_t)a.y*b.y>0? diff > 0 : diff < 0;
        } 
    };
};
*/

//异曲同工的正确做法：Beats 99.7%
//https://leetcode.com/problems/max-points-on-a-line/discuss/47101/7-line-C++-concise-solution-NO-double-hash-key-or-GCD-for-slope

class Solution
{
  public:
    int maxPoints(vector<Point> &pts)
    {
        int maxPts = 0;

        for (int i = 0; i < pts.size(); ++i)
        {
            map<Point, int, Comp> count;
            int dup = 0;
            int curr_max = 0;
            for (int j = i; j < pts.size(); ++j)
            {
                if (pts[i].x == pts[j].x && pts[i].y == pts[j].y)
                {
                    ++dup;
                }
                else
                { // key(0,0) is not allowed
                    curr_max = max(curr_max, ++count[Point(pts[i].x - pts[j].x, pts[i].y - pts[j].y)]);
                }
                maxPts = max(maxPts, curr_max + dup);
            }
        }
        return maxPts;
    }

    struct Comp
    {
        bool operator()(const Point &a, const Point &b)
        {
            int64_t diff = (int64_t)a.x * b.y - (int64_t)a.y * b.x;
            return (int64_t)a.y * b.y > 0 ? diff > 0 : diff < 0;
        }
    };
};
