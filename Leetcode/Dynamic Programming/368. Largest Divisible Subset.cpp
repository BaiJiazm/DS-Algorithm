#include "headFile"

class Solution {
	public:
		vector<int> largestDivisibleSubset(vector<int>& nums) {
			vector<int> num(nums);
			int size=num.size();
			sort(num.begin(),num.end());
			vector<int>sn(size,1);
			vector<int>parent(size,-1);

			int ansn=0,ansp=-1;
			for(int i=0; i<size; ++i) {
				for (int j=i-1; j>=0; --j) {
					if (num[i]%num[j]==0&&sn[j]+1>sn[i]) {
						sn[i]=sn[j]+1;
						parent[i]=j;
					}
				}
				if(ansn<sn[i]) {
					ansn=sn[i];
					ansp=i;
				}
			}

			vector<int>rev(ansn);
			while(ansp!=-1) {
				rev[--ansn]=num[ansp];
				ansp=parent[ansp];
			}
			return rev;
		}
};
