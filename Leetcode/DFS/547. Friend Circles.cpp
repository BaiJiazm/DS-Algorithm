class Solution {
	public:
		vector<bool>visited;
		int findCircleNum(vector<vector<int>>& M) {
			visited.resize(M.size(),false);
			int circleNum=0;
			for(int i=0; i<M.size(); ++i)
				if(!visited[i])	{
					++circleNum;
					dfs(M,i);
				}
			return circleNum;
		}
		void dfs(vector<vector<int>>&M,int i) {
			if(visited[i])
				return ;
			visited[i]=true;
			for(int j=0; j<M[i].size()/2; ++j)
				if(M[i][j])
					dfs(j);
		}
};
