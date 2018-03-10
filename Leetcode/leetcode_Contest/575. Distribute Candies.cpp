class Solution {
	public:
		int distributeCandies(vector<int>& candies) {
			sort(candies.begin(),candies.end());
			int diff=0;
			int pre=INT_MIN;
			for(auto &a:candies)
				if(a!=pre) {
					pre=a;
					++diff;
				}
			return min(diff,(int)candies.size()/2);
		}
};
