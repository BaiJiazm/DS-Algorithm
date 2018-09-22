class Solution {
	public:
		vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
			unordered_map<string,int>hash;
			for(int i=0; i<list1.size(); ++i)
				hash[list1[i]]=i;
			int count=INT_MAX;
			vector<string>ans;
			for(int i=0; i<list2.size(); ++i)
				if(hash.count(list2[i])) {
					int index=hash[list2[i]];
					if(index+i<count) {
						count=index+i;
						ans= {list2[i]};
					} else if(index+i==count)
						ans.push_back(list2[i]);
				}
			return ans;
		}
};
