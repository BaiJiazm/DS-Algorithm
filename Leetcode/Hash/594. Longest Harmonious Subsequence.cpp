class Solution {
	public:
		int findLHS(vector<int>& nums) {

			unordered_map<int, int> map;
			auto max = 0;

			for(auto element : nums) {

				map[element]++;
				if (map.count(element-1) > 0) {
					max = std::max(max, map[element-1] + map[element] );
				}
				if (map.count(element+1) > 0) {
					max = std::max(max, map[element+1] + map[element] );
				}
			}
			return max;
		}
};
