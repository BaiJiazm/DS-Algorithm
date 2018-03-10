class Solution {
	public:
		int minDistance(string word1, string word2) {
			int len1=word1.length();
			int len2=word2.length();
			vector<vector<int>>dif(len1+1,vector<int>(len2+1));
			for (int i=0; i<=len1; ++i)
				dif[i][0]=i;
			for (int j=0; j<=len2; ++j)
				dif[0][j]=j;
			for (int i=1; i<=len1; ++i) {
				for (int j=1; j<=len2; ++j) {
					int tm=min(dif[i-1][j],dif[i][j-1]);
					if (word1[i-1]==word2[j-1])
						dif[i][j]=min(tm+1,dif[i-1][j-1]);
					else
						dif[i][j]=min(tm,dif[i-1][j-1])+1;
				}
			}
			return dif[len1][len2];
		}
};
