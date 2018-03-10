
/* 这道题目本来是应该做的出来的，就差最后一步了！
	首先想到了 用cut[j]表示子串s[0,j]所需要的最小分割数，但是差了一步向前逐次判断！
	千万不要拘束于时间复杂度什么的
*/
class Solution {
	public:
		int minCut(string s) {
			int size = s.size();
			if(size == 0) {
				return 0;
			}//if
			// isPal[i][j]表示字符串s的子串s[i,j]是否为回文串
			bool isPal[size][size];
			memset(isPal,0,sizeof(isPal));
			// cut[j]表示子串s[0,j]所需要的最小分割数
			int cut[size];
			// cut[0,i]
			for(int i = 0; i < size; ++i) {
				// [0,i]最多分割i次
				cut[i] = i;
				// 判断s[j,i]是否是回文串
				for(int j = 0; j <= i; ++j) {
					// s[j,i]是回文串
					if(s[j] == s[i] && (i - j <= 1 || isPal[j+1][i-1])) {
						isPal[j][i] = true;
						// s[0,i]是回文串
						if(j == 0) {
							cut[i] = 0;
						}//if
						else {
							cut[i] = min(cut[i],cut[j-1]+1);
						}//else
					}//if
				}//for
			}//for
			return cut[size-1];
		}
};
