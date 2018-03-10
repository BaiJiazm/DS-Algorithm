class Solution {
	public:
		vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
			int row=board.size();
			vector<string>ans;
			if (!row||words.empty())
				return ans;
			int col=board[0].size();
			vector<bool>visited(row*col,false);
			vector<vector<int>>sPos(26);
			int i,j;
			for (i=0; i<row; ++i)
				for(j=0; j<col; ++j)
					sPos[board[i][j]-'a'].push_back(i*row+j);

			for (i=0; i<words.size(); ++i)
				if (words[i].length()==0)
					ans.push_back(words[i]);
				else
					for (j=0; j<sPos[words[i][0]-'a'].size(); ++j)
						if (dfs(words[i],0))
							ans.push_back(words[i]);
		}
		bool dfs(vector<vector<char>>&board,vector<bool>&visited,string&word,const int &row,const int &col,int index,int pos) {
			if (index==word.length())
				return true;
			int x=
			    if (word[index]==
		}

};
