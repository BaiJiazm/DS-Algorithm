/*
	我们首先从i站点出发，若走到当前站点cur我们的油量<0，那么只需要从cur+1继续出发试探即可。
	在此不进行证明，但是我们可以宏观的想一下，前面的任意的前缀站点段的油量和肯定是>0的，
	那么去掉任意一个前缀，只会使油量变得更少，所以我们只能尝试从cur+1重新开始。
*/

//自己写的原始代码，o(n)
class Solution {
	public:
		int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
			if(gas.empty())
				return -1;
			int i,j,cur,l,n=gas.size();
			vector<int>leave(n);
			for(i=0; i<n; ++i)
				leave[i]=gas[i]-cost[i];
			for(i=0; i<n;) {
				for(cur=i,l=leave[i],j=0; j!=n&&l>=0; ++j)
					l+=leave[++cur%n];
				if(l>=0)
					break;
				i=cur+1;
			}
			return l>=0?i:-1;
		}
};

//上述代码的优化写法
class Solution {
	public:
		int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
			int totalGas = 0;
			int totalCost = 0;
			int tank = 0;
			int begin = 0;
			for (int i = 0; i < gas.size(); i++) {
				totalGas += gas[i];
				totalCost += cost[i];
				tank += (gas[i] - cost[i]);
				if (tank < 0) {
					begin = i + 1;
					tank = 0;
				}
			}

			return (totalGas >= totalCost ? begin : -1);
		}
};


class Solution {
	public:
		int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
			int n = gas.size();
			int total(0), subsum(INT_MAX), start(0);
			for(int i = 0; i < n; ++i) {
				total += gas[i] - cost[i];
				if(total < subsum) {
					subsum = total;
					start = i + 1;
				}
			}
			return (total < 0) ?  -1 : (start%n);
		}
};
