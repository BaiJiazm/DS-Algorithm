#include "headFile"

/*	其实做了这么多得DP问题，很多题其实都是特别的简单，
	而核心思维就在于“自顶向下，逆向思维”，
	关键词在于“子问题，子结构，子性质，无后效性，状态量，初始量”
*/
class Solution {
	public:
		int maxProfit(int k, vector<int>& prices) {
			const int minINF=-0x3f3f3f3f;
			k=min(k,(int)prices.size()/2);
			vector<int>hold(k+1,minINF);
			vector<int>sell(k+1,0);
			for(auto a:prices) {
				for (int i=k; i; --i) {
					int tem=hold[i];
					hold[i]=max(hold[i],sell[i-1]-a);
					sell[i]=max(sell[i],hold[i]+a);
				}
			}
			return max(sell[k],0);
		}
};

/*	另一种思维：Leetcode区，利用数据结构	C++ Solution with O(n + klgn) time using Max Heap and Stack
	详见：https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/?tab=Solutions
*/

class Solution {
	public:
		int maxProfit(int k, vector<int> &prices) {
			int n = (int)prices.size(), ret = 0, v, p = 0;
			priority_queue<int> profits;
			stack<pair<int, int> > vp_pairs;
			while (p < n) {
				// find next valley/peak pair
				for (v = p; v < n - 1 && prices[v] >= prices[v+1]; v++);
				for (p = v + 1; p < n && prices[p] >= prices[p-1]; p++);
				// save profit of 1 transaction at last v/p pair, if current v is lower than last v
				while (!vp_pairs.empty() && prices[v] < prices[vp_pairs.top().first]) {
					profits.push(prices[vp_pairs.top().second-1] - prices[vp_pairs.top().first]);
					vp_pairs.pop();
				}
				// save profit difference between 1 transaction (last v and current p) and 2 transactions (last v/p + current v/p),
				// if current v is higher than last v and current p is higher than last p
				while (!vp_pairs.empty() && prices[p-1] >= prices[vp_pairs.top().second-1]) {
					profits.push(prices[vp_pairs.top().second-1] - prices[v]);
					v = vp_pairs.top().first;
					vp_pairs.pop();
				}
				vp_pairs.push(pair<int, int>(v, p));
			}
			// save profits of the rest v/p pairs
			while (!vp_pairs.empty()) {
				profits.push(prices[vp_pairs.top().second-1] - prices[vp_pairs.top().first]);
				vp_pairs.pop();
			}
			// sum up first k highest profits
			for (int i = 0; i < k && !profits.empty(); i++) {
				ret += profits.top();
				profits.pop();
			}
			return ret;
		}
};

int main() {
	vector<int>prices({10000,2});
	Solution s;
	cout<<s.maxProfit(1000000,prices);
	return 0;
}
