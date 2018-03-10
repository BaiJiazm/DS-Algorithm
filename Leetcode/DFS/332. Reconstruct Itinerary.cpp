/*
	������뷨����Ҫ���ַ������ƣ�����ʱ��ĸ���Ҫ�����㷨���Ӷȣ�������һЩ�Ż����ɣ�
    ��ÿ���ڵ����С�ڽӵ���б�����������ȥ���ߣ�������ýڵ㣬����Ϊ��
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
