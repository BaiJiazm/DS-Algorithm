/*	非常好的DP题目，对于DP题目最重要的是由简单的一些例子由简到繁的进行分析，
    找准状态量和分析清楚子问题（是否有后效性），对状态量进行从前到后的迭代递推或者从后到前的分析。
    无论状态量是什么（一个整型值、结构体、字符串、集合等，或者有多个状态量），一定要分析找准状态量。
    
*/

//解法一：
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() ==0) return 0;
        int len = prices.size();
        vector<int> buy(len+1, 0), sell(len+1, 0);
        buy[1] = -prices[0];
        for(int i = 2; i <= len; i++)
        {
            buy[i] = max(sell[i-2]- prices[i-1], buy[i-1]);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i-1]);
        }
        return sell[len];
    }
};

int maxProfit(vector<int> &prices) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
        prev_buy = buy;
        buy = max(prev_sell - price, buy);
        prev_sell = sell;
        sell = max(prev_buy + price, sell);
    }
    return sell;
}

/*
１．在第i天买一支股票还能剩下的利润＝第(i-2)天销售能够剩余的利润－第i天股票的价钱．

２．在第i天卖一支股票总的利润＝第(i-1)天买股票剩下的最大利润＋当前股票的价格．

也就是说需要维护两个状态的信息，一个是买股票所得到的剩余最大利润，一个是卖出股票之后得到的最大利润，他们互相依赖对方的信息．

再来进一步分析如何维持一个最大的利润．

对于买来说，当天是否买取决于买了之后是否比之前买所剩余的利润大，即状态转移方程为：

buy[i] = max(buy[i-1], sell[i-2] - prices[i-1]);

对于卖来说，同样当天是否将这只股票卖掉取决于卖掉能否获得更大的利润，状态转移方程为：

sell[i] = max(sell[i-1], sell[i-1] + prices[i-1]);

*/
