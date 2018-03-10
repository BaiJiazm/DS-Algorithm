/*
	�������ȴ�iվ����������ߵ���ǰվ��cur���ǵ�����<0����ôֻ��Ҫ��cur+1����������̽���ɡ�
	�ڴ˲�����֤�����������ǿ��Ժ�۵���һ�£�ǰ��������ǰ׺վ��ε������Ϳ϶���>0�ģ�
	��ôȥ������һ��ǰ׺��ֻ��ʹ������ø��٣���������ֻ�ܳ��Դ�cur+1���¿�ʼ��
*/

//�Լ�д��ԭʼ���룬o(n)
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

//����������Ż�д��
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
