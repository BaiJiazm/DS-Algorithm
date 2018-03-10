#include<map>
using namespace std;

//堆+贪心
//己版	time:56ms
class Solution {
	public:
		int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
			multimap<int,int>can;
			multimap<int,int>notCan;

			int i;
			for (i=0; i<Profits.size(); ++i) {
				if(Capital[i]<=W)
					can.insert({Profits[i],Capital[i]});
				else
					notCan.insert({Capital[i],Profits[i]});
			}
			k=min(i,k);
			if (k==0||can.size()==0)
				return W;
			for(i=0; i<k; ++i) {
				multimap<int,int>::iterator &pend=--can.end();
				W+=pend->first;
				can.erase(pend);
				while(!notCan.empty()) {
					multimap<int,int>::iterator it=notCan.begin();
					if (it->first<=W) {
						can.insert({it->second,it->first});
						notCan.erase(it);
					} else
						break;
				}
			}
			return W;
		}
};

//思维一样，优化简洁了一下  time:48ms
class Solution {
	public:
		int findMaximizedCapital(int k, int W, vector<int>& P, vector<int>& C) {
			priority_queue<int> low;      // P[i]'s within current W
			multiset<pair<int,int>> high; // (C[i],P[i])'s' outside current W

			for (int i = 0; i < P.size(); ++i) // initialize low and high
				if(P[i] > 0)
					if (C[i] <= W)
						low.push(P[i]);
					else
						high.emplace(C[i], P[i]);

			while (k-- && low.size()) {
				W += low.top(), low.pop(); // greedy to work on most profitable first
				for (auto i = high.begin(); high.size() && i->first <= W; i = high.erase(i))
					low.push(i->second);
			}
			return W;
		}
};
