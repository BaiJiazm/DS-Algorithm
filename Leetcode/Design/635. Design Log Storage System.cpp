//还是我写的方法简单。19ms。 因为题目测试数据量不大。 
class LogSystem {
		vector<pair<int,string>>data;
	public:
		LogSystem() {
			data.clear();
		}

		void put(int id, string timestamp) {
			data.push_back({id,timestamp});
		}

		vector<int> retrieve(string s, string e, string gra) {
			int len=0;
			if(gra=="Year")
				len=4;
			else if(gra=="Month")
				len=7;
			else if(gra=="Day")
				len=10;
			else if(gra=="Hour")
				len=13;
			else if(gra=="Minute")
				len=16;
			else
				len=19;
			vector<int>ans;
			string ss=s.substr(0,len);
			string es=e.substr(0,len);
			for(int i=0; i<data.size(); ++i) {
				string substr=data[i].second.substr(0,len);
				if(substr>=ss&&substr<=es)
					ans.push_back(data[i].first);
			}
			return ans;
		}
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */



class LogSystem {
	public:
		unordered_map<string, int> mp;
		unordered_map<string, int> mapping;

		LogSystem() {
			mapping["Year"] = 0;
			mapping["Month"] = 1;
			mapping["Day"] = 2;
			mapping["Hour"] = 3;
			mapping["Minute"] = 4;
			mapping["Second"] = 5;
		}

		void put(int id, string timestamp) {
			mp[timestamp] = id;
		}

		vector<int> retrieve(string s, string e, string gra) {
			vector<int> result;
			for (auto p : mp) {
				string tp = p.first;
				if (bigger(tp, s, gra) && smaller(tp, e, gra)) result.push_back(p.second);
			}
			return result;
		}
		bool smaller(string t1, string t2, string grad) {
			auto w1 = split(t1);
			auto w2 = split(t2);
			for (int i = 0; i <= mapping[grad]; i++) {
				if (w1[i] > w2[i]) return false;
				else if (w1[i] < w2[i]) return true;
			}
			return true;
		}

		bool bigger(string t1, string t2, string grad) {
			auto w1 = split(t1);
			auto w2 = split(t2);
			for (int i = 0; i <= mapping[grad]; i++) {
				if (w1[i] < w2[i]) return false;
				else if (w1[i] > w2[i]) return true;
			}
			return true;
		}

		vector<int> split(string t) {
			vector<int> words;
			istringstream iss(t);
			string s;
			while (getline(iss, s, ':')) {
				words.push_back(stoi(s));
			}
			return words;
		}
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
