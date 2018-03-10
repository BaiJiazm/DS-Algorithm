/*
    编程技巧：我们可以把后来可能用到的数据通过容器保存起来，可以使得程序简洁，效率高
*/
class Solution {
	public:
		vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
			deque< pair<int,int> >q({ {click[0],click[1]} });
			if (board[click[0]][click[1]]=='M') {
				board[click[0]][click[1]]='X';
				return board;
			}

			int maxr=board.size();
			int maxc=board[0].size();
			while(!q.empty()) {
				int r=q.front().first,c=q.front().second;
				q.pop_front();

				vector< pair<int,int> >neighbours;
				int mines=0;
				for(int i=-1; i<=1; ++i) {
					for (int j=-1; j<=1; ++j) {
						int pr=r+i,pc=c+j;
						if (pr>=0&&pr<maxr&&pc>=0&&pc<maxc)
							if (board[pr][pc]=='M')
								mines++;
							else if (board[pr][pc]=='E')
								neighbours.push_back({pr,pc});
					}
				}

				if (mines)
					board[r][c]='0'+mines;
				else {
					for (int i=0; i<neighbours.size(); ++i) {
						board[neighbours[i].first][neighbours[i].second]='B';
						q.push_back(neighbours[i]);
					}
				}
			}
			return board;
		}
};
