#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices, int fee){
        int i0=0, i1=-prices.front();
        int n0, n1;
        for(int i=1; i<prices.size(); ++i){
            n0=max(i0, i1+prices[i]-fee);
            n1=max(i1, n0-prices[i]);
            i0=n0;
            i1=n1;
        }
        return max(i0, i1);
    }
};