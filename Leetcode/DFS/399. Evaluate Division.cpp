class Solution {
	public:
		vector<double> calcEquation(vector<pair<string, string>> equations,
		                            vector<double>& values, vector<pair<string, string>> query) {
			unordered_map<string,unordered_map<string, double>> m;
			vector<double> res;
			for (int i = 0; i < values.size(); ++i) {
				m[equations[i].first].insert(make_pair(equations[i].second,values[i]));
				if(values[i]!=0)
					m[equations[i].second].insert(make_pair(equations[i].first,1/values[i]));
			}

			for (auto i : query) {
				unordered_set<string> s;
				double tmp = check(i.first,i.second,m,s);
				if(tmp) res.push_back(tmp);
				else res.push_back(-1);
			}
			return res;
		}

		double check(string up, string down,
		             unordered_map<string,unordered_map<string, double>> &m,
		             unordered_set<string> &s) {
			if(m[up].find(down) != m[up].end()) return m[up][down];
			for (auto i : m[up]) {
				if(s.find(i.first) == s.end()) {
					s.insert(i.first);
					double tmp = check(i.first,down,m,s);
					if(tmp) return i.second*tmp;
				}
			}
			return 0;
		}
};
