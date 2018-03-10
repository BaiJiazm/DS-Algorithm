/*
算是比较简单的题目，开始把题目读错了，以为树未砍掉前是不能经过的。
*/
class node {
	public:
		int x;
		int y;
		int h;
		node(int xx,int yy, int hh):x(xx), y(yy), h(hh) {}
		bool operator <(const node& n)const {
			return h<n.h;
		}
};

class Solution {
	public:
		const int dir[4][2]= {{1, 0}, {-1 ,0}, {0, 1}, {0, -1}};
		int cutOffTree(vector<vector<int>>& forest) {
			int row=forest.size();
			int col=forest[0].size();
			int i,j;
			vector<node>vn;
			for(i=0;i<row;++i){
				for(j=0;j<col;++j){
					if(forest[i][j]>0)
						vn.push_back(node(j, i, forest[i][j]));
				}
			}
			sort(vn.begin(), vn.end());
			int ans=0;
			node pre(0, 0, forest[0][0]);
			for(i=0;i<vn.size();++i){
				int step=findMinStep(forest, pre, vn[i]);
				if(step<0)
					return -1;
				ans+=step;
				pre=vn[i];
			}
			return ans;
		}

		int findMinStep(vector<vector<int>> forest, node start, node end) {
			int row=forest.size();
			int col=forest[0].size();
			
			queue<node>que;
			que.push(start);
			forest[start.y][start.x]=0;
			int step=0;
			int incnt=1;
			int i;
			while(!que.empty()) {
				incnt=que.size();
				while(incnt--) {
					node top=que.front();
					que.pop();
					int x=top.x,y=top.y;
					if(x==end.x&&y==end.y)
						return step;
					for(i=0; i<4; ++i) {
						int nx=top.x+dir[i][0];
						int ny=top.y+dir[i][1];
						if(nx>=0&&nx<col&&ny>=0&&ny<row&&forest[ny][nx]>0) {
							forest[ny][nx]=0;
							que.push(node(nx, ny, forest[ny][nx]));
						}
					}
				}
				++step;
			}
			return -1;
		}
};
