class Solution {
	public:
		int maxProduct(vector<string>& words) {
			vector<pair<int,int>>wd;
			int i,j,k,t;
			int ans=0;
			for(i=0; i<words.size(); ++i) {
				for(t=0,j=0; j<words[i].length(); ++j)
					t|=1<<words[i][j]-'a';
				wd.push_back({words[i].length(),t});
			}
			for(i=0; i<wd.size(); ++i)
				for(j=i+1; j<wd.size(); ++j) {
					for(k=0; k<26; ++k)
						//if(wd[i].second>>k&1|wd[j].second>>k&1&&!(wd[i].second>>k&1^wd[j].second>>k&1))
						if(wd[i].second>>k&1 && wd[j].second>>k&1)
							break;
					if(k>=26)
						ans=max(ans,wd[i].first*wd[j].first);
				}
			return ans;
		}
};

class Solution {
	public:
		int maxProduct(vector<string>& words) {
			vector<int>mask(words.size(),0);
			int res=0;
			for (int i =0; i<words.size(); i++) {
				for (char c:words[i])
					mask[i]|=1<<(c-'a');
				for (int j=0; j<i; j++)
					if (!(mask[i]&mask[j]))
						res=max(res,int(words[i].size()*words[j].size()));
			}
			return res;
		}
};
