/*
    也没认真思考，直接就上了，O(nlogn)  time:79ms
*/
class Solution {
	public:
		int candy(vector<int>& ratings) {
			multimap<int,int>mulmap;
			int miniCandy=ratings.size();
			int size=ratings.size();
			vector<int>candies(size,1);
			for (int i=0; i<size; ++i)
				mulmap.insert({ratings[i],i});
			for (multimap<int,int>::iterator it=mulmap.begin(); it!=mulmap.end(); ++it) {
				int tem=1;
				if (it->second>0&&it->first>ratings[it->second-1])
					tem=max(tem,candies[it->second-1]+1);
				if (it->second<size-1&&it->first>ratings[it->second+1])
					tem=max(tem,candies[it->second+1]+1);
				miniCandy+=(candies[it->second]=tem)-1;
			}
			return miniCandy;
		}
};

//O(nlogn)  time:26ms
class Solution {
	public:
		int candy(vector<int> &ratings) {
			vector<int> cd(ratings.size(), 1);
			int sum = 0;
			for (int i = 1; i < ratings.size(); i++) {
				if (ratings[i] > ratings[i-1])
					cd[i] = cd[i-1] + 1;
			}
			for (int i = ratings.size() - 2; i >= 0; i--) {
				if (ratings[i] > ratings[i+1])
					cd[i] = max(cd[i], cd[i+1] + 1);
			}
			for (int i = 0; i < cd.size(); i++) {
				sum += cd[i];
			}
			return sum;
		}

};
