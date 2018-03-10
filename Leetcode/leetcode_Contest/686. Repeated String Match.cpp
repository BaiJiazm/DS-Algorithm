class Solution {
	public:
		int repeatedStringMatch(string A, string B) {
			int alen=A.length();
			int blen=B.length();
			int i,j,k,ans;
			for(i=0; i<alen; ++i) {
				if(A[i]==B[0]) {
					ans=1;
					for(j=0, k=i; j<blen; ++j, ++k) {
						ans+=(k==alen);
						k=k%alen;
						if(A[k]!=B[j])
							break;
					}
					if(j==blen)
						return ans;
				}
			}
			return -1;
		}
};
