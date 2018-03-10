#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
	public:
		bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
			if(p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
				return false;
			}
			vector<vector<int>> points = {p1, p2, p3, p4};
			sort(points.begin(), points.end());
			if(dis_square(points[0], points[1]) == dis_square(points[1], points[3]) // check four sides
			        && dis_square(points[1], points[3]) == dis_square(points[3], points[2])
			        && dis_square(points[3], points[2]) == dis_square(points[2], points[0])
			        && dis_square(points[2], points[0]) == dis_square(points[0], points[1])
			        // check the diagonals
			        && dis_square(points[0], points[3]) == dis_square(points[1], points[2])) {
				return true;
			}
			return false;
		}
	private:
		int dis_square(vector<int> p1, vector<int> p2) {
			return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
		}
};

class Solution {
	public:
		int d(vector<int>& p1, vector<int>& p2) {
			return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
		}
		bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
			unordered_set<int> s({ d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4) });
			return !s.count(0) && s.size() == 2;
		}
};

void test() {
	vector<int>p1= {1,2};
	vector<int>p2= {1,2,3};
	vector<int>p3= {1,2,1};
	vector<int>p4= {2};
	vector<int>p5= {1,2};
	vector<vector<int>>vp= {p1,p2,p3,p4,p5};
	sort(vp.begin(),vp.end());
	for(auto&a:vp) {
		for(auto &b:a)
			cout<<b<<" ";
		cout<<endl;
	}

	cout<<"p1==p5?"<<(p1==p5)<<endl;
}

int main() {
	test();
	vector<int>p1= {0,0};
	vector<int>p2= {1,1};
	vector<int>p3= {1,0};
	vector<int>p4= {0,1};
	Solution s;
	cout<<s.validSquare(p1,p2,p3,p4);
	return 0;
}

