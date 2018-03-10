/*
	第二次做这种设计或者模拟题目，这种题目一般不在算法上过多较劲，但是需要熟练的语言知识及数据结构运用。
	其次是读题要谨慎，题目明确的规则下有什么会是考点，逻辑考虑完全。本题第一次就没有考虑到一个单元格可以有多个父亲，父亲可以作为父亲的父亲，需要递归更新。
*/
class Excel {
	private:
		int excel[26][26];
		vector<vector<unordered_multiset<int> >>toSum;
		vector<vector<unordered_multiset<int> >>fromSum;
		void clearSumInfo(int r,char c) {
			int rc=(r-1)*26+c-'A';
			for(auto &a:fromSum[r-1][c-'A']) {
				int tr=a/26;
				int tc=a%26;
				toSum[tr][tc].erase(rc);
			}
			fromSum[r-1][c-'A'].clear();
		}
		void update(int r,int c,int gap) {
			for(auto &a:toSum[r][c]) {
				int tr=a/26;
				int tc=a%26;
				excel[tr][tc]+=gap;
				update(tr,tc,gap);
			}
		}
	public:
		Excel(int H, char W) {
			for(int i=0; i<H; ++i)
				for(int j=0; j<=W-'A'; ++j)
					excel[i][j]=0;
			toSum=vector<vector<unordered_multiset<int> >>(H,vector<unordered_multiset<int>>(W));
			fromSum=vector<vector<unordered_multiset<int> >>(H,vector<unordered_multiset<int>>(W));
		}

		void set(int r, char c, int v) {
			int gap=v-excel[r-1][c-'A'];
			excel[r-1][c-'A']=v;
			clearSumInfo(r,c);
			update(r-1,c-'A',gap);
		}

		int get(int r, char c) {
			return excel[r-1][c-'A'];
		}

		int sum(int r, char c, vector<string> strs) {
			clearSumInfo(r,c);
			int rr=r-1;
			int cc=c-'A';

			int r1,r2,c1,c2,rc;
			excel[rr][cc]=0;
			for(auto &str:strs) {
				int posD=str.find(':');
				if(posD==string::npos) {
					r1=r2=stoi(str.substr(1))-1;
					c1=c2=str[0]-'A';
				} else {
					r1=stoi(str.substr(1,posD-1))-1;
					c1=str[0]-'A';
					r2=stoi(str.substr(posD+2))-1;
					c2=str[posD+1]-'A';
				}
				for(int i=r1; i<=r2; ++i)
					for(int j=c1; j<=c2; ++j) {
						fromSum[rr][cc].insert(i*26+j);
						toSum[i][j].insert(rr*26+cc);
						excel[rr][cc]+=excel[i][j];
					}
			}
			return excel[rr][cc];
		}
};
