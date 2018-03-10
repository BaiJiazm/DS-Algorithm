#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

/*
 *  自己写的，通过32/40个case，TLE错误！
*/
struct pos {
	int x;
	int y;
	int height;
};

class posGreaterCmp {
	public:
		bool operator ()(const pos &p1,const pos &p2) const {
			return p1.height>p2.height;
		}
};

class posSort {
	public:
		bool operator ()(const pos &p1,const pos &p2) const {
			if(p1.x!=p2.x)
				return p1.x<p2.x;
			else
				return p1.y<p2.y;
		}
};

class Solution {
	public:
		int trapRainWater(vector<vector<int> >& heightMap) {
			if (heightMap.size()==0||heightMap[0].size()==0)
				return 0;
			priority_queue< pos,vector<pos>,posGreaterCmp >priq;
			int row=heightMap.size();
			int col=heightMap[0].size();
			for (int i=1; i<row-1; ++i)
				for (int j=1; j<col-1; ++j) {
					priq.push({i,j,heightMap[i][j]});
				}

			int trapWater=0;
			while(!priq.empty()) {
				pos searchPos=priq.top();
				priq.pop();
				if (searchPos.height==heightMap[searchPos.x][searchPos.y]) {
					set<pos,posSort>visitedSet;
					queue<pos>temq;
					temq.push(searchPos);
					int flag=0;
					int dir[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};
					int minHeight=INT_MAX;

					while(!temq.empty()) {
						pos ps=temq.front();
						temq.pop();
						visitedSet.insert(ps);
						for (int i=0; i<4; ++i)
							for (int j=0; j<2; ++j) {
								int px=ps.x+dir[i][0];
								int py=ps.y+dir[i][1];
								pos nextPos= {px,py,heightMap[px][py]};
								if (visitedSet.count(nextPos)==0) {
									if (nextPos.height<ps.height||nextPos.height==ps.height&&(nextPos.x==0||nextPos.x==row-1||nextPos.y==0||nextPos.y==col-1)) {
										flag=1;
										break;
									} else if (nextPos.height==ps.height) {
										temq.push(nextPos);
									} else if (nextPos.height>ps.height)
										minHeight=min(minHeight,nextPos.height);
								}
							}
						if (flag)
							break;
					}
					if (!flag) {
						trapWater+=(minHeight-searchPos.height)*visitedSet.size();
						set<pos,posSort>::iterator it;
						for (it=visitedSet.begin(); it!=visitedSet.end(); ++it) {
							heightMap[it->x][it->y]=minHeight;
						}
						priq.push({searchPos.x,searchPos.y,minHeight});
					}
				}
			}
			return trapWater;
		}
};

int main() {
	vector<int>v0 {1,4,3,1,3,2};
	vector<int>v1({3,2,1,3,2,4});
	vector<int>v2({2,3,3,2,3,1});

	vector<vector<int> > heightMap(3);
	heightMap[0]=v0;
	heightMap[1]=v1;
	heightMap[2]= v2;
	Solution s;
	cout<<s.trapRainWater(heightMap)<<endl;
	return 0;
}



class Solution {
	public:
		int trapRainWater(vector<vector<int>>& heightMap) {
			if(heightMap.size()==0) return 0;
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
			int row = heightMap.size(), col = heightMap[0].size();
			vector<vector<int>> visited(row, vector<int>(col, 0));
			int ans = 0, Max = INT_MIN;
			for(int i = 0; i < row; i++) {
				for(int j = 0; j < col; j++) {
					if(!(i==0 || i==row-1 || j==0 || j==col-1)) continue;
					que.push(make_pair(heightMap[i][j], i*col+j));
					visited[i][j] = 1;
				}
			}
			vector<vector<int>> dir {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
			while(!que.empty()) {
				auto val = que.top();
				que.pop();
				int height = val.first, x = val.second/col, y = val.second%col;
				Max = max(Max, height);
				for(auto d: dir) {
					int x2 = x + d[0], y2 = y + d[1];
					if(x2>=row || x2<0 || y2<0 || y2>=col || visited[x2][y2]) continue;
					visited[x2][y2] = 1;
					if(heightMap[x2][y2] < Max) ans += Max - heightMap[x2][y2];
					que.push(make_pair(heightMap[x2][y2], x2*col+y2));
				}
			}
			return ans;
		}
};
