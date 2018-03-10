class Solution {
	public:
		// vector<int> topKFrequent(vector<int>& nums, int k) {
		//     unordered_map<int, int>count;
		//     vector<int>res;
		//     for (auto e:nums) count[e]++;
		//     priority_queue<pair<int, int>>q;
		//     for (auto e:count) q.push({e.second, e.first});
		//     for(int i = 0; i < k; i++){
		//         res.push_back(q.top().second);
		//         q.pop();
		//     }
		//     return res;
		// }

		vector<int> topKFrequent(vector<int>& nums, int k) {
			unordered_map<int, int> m;
			vector<vector<int>> bucket(nums.size() + 1);
			vector<int> res;
			for (auto a : nums) ++m[a];
			for (auto it : m) {
				bucket[it.second].push_back(it.first);
			}
			for (int i = nums.size(); i >= 0; --i) {
				for (int j = 0; j < bucket[i].size(); ++j) {
					res.push_back(bucket[i][j]);
					if (res.size() == k) return res;
				}
			}
			return res;
		}
};
