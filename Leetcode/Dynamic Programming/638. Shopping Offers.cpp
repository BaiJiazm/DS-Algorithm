class Solution {
		unordered_map<int,int>dp;
		int shoppingOffers(vector<int>&price,vector<vector<int>>&special,int nds) {
			if(dp.count(nds))
				return dp[nds];
			int i,j;
			int nd,sp;
			int nnds;
			int cost=0,tcost=0;
			for(i=0; i<price.size(); ++i)
				cost+=price[i]*(nds>>3*i&7);
			for(i=0; i<special.size(); ++i) {
				for(nnds=0,j=0; j<special[i].size()-1; ++j) {
					nd=nds>>3*j&7;
					sp=special[i][j];
					if(nd<sp)
						break;
					nnds|=(nd-sp)<<3*j;
				}
				if(nd>=sp) {
					tcost=shoppingOffers(price,special,nnds)+special[i].back();
					cost=min(cost,tcost);
				}
			}
			return dp[nds]=cost;
		}
	public:
		int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
			int nds=0;
			int i;
			for(i=0; i<needs.size(); ++i)
				nds|=(needs[i]&7)<<3*i;
			return shoppingOffers(price,special,nds);
		}
};
