/*
	不错的想法，不要被字符串忽悠，决定时间的更重要的是算法复杂度，而不是一些优化技巧！
    从每个节点的最小邻接点进行遍历，并进行去掉边，最后加入该节点，逆序为答案
*/
class Solution {
	public:
		vector<string> findItinerary(vector<pair<string, string>> tickets) {
			for (auto ticket : tickets)
				targets[ticket.first].insert(ticket.second);
			visit("JFK");
			return vector<string>(route.rbegin(), route.rend());
		}

		map<string, multiset<string>> targets;
		vector<string> route;

		void visit(string airport) {
			while (targets[airport].size()) {
				string next = *targets[airport].begin();
				targets[airport].erase(targets[airport].begin());
				visit(next);
			}
			route.push_back(airport);
		}
};
