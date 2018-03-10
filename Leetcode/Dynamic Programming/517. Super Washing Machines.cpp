#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

#include<algorithm>
#include<functional>
#include<numeric>
#include<bitset>
#include<cmath>
using namespace std;

class Solution {
	public:
		int findMinMoves(vector<int>& machines) {
			int sum=accumulate(machines.begin(),machines.end(),0);
			int size=machines.size();
			if (sum%size)
				return -1;
			int avr=sum/size;
			int move=0,acu=0,gap=0;
			int i;
			for (i=0; i<size; ++i) {
				gap=machines[i]-avr;
				acu+=gap;
				move=max(move,max(gap,abs(acu)));
			}
			return move;
		}
};

int main() {
	vector<int>machines({1,0,5});
	Solution s;
	cout<<s.findMinMoves(machines)<<endl;
	return 0;
}
