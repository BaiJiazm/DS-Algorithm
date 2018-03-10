class Solution {
	public:
		int maxCount(int m, int n, vector<vector<int>>& ops) {
			if(ops.empty())
				return m*n;
			int minRow=INT_MAX,minCol=INT_MAX;
			for(int i=0; i<ops.size(); ++i) {
				minRow=min(minRow,ops[i][0]);
				minCol=min(minCol,ops[i][1]);
			}
			return minRow*minCol;
		}
};

class Solution {
	public:
		int maxCount(int m, int n, vector<vector<int>>& ops) {
			for (auto op : ops) {
				m = min(op[0], m);
				n = min(op[1], n);
			}
			return m * n;
		}
};
