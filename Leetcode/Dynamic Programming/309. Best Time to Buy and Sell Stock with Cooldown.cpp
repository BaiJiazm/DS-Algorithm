/*	�ǳ��õ�DP��Ŀ������DP��Ŀ����Ҫ�����ɼ򵥵�һЩ�����ɼ򵽷��Ľ��з�����
    ��׼״̬���ͷ�����������⣨�Ƿ��к�Ч�ԣ�����״̬�����д�ǰ����ĵ������ƻ��ߴӺ�ǰ�ķ�����
    ����״̬����ʲô��һ������ֵ���ṹ�塢�ַ��������ϵȣ������ж��״̬������һ��Ҫ������׼״̬����
    
*/

//�ⷨһ��
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
�����ڵ�i����һ֧��Ʊ����ʣ�µ����󣽵�(i-2)�������ܹ�ʣ������󣭵�i���Ʊ�ļ�Ǯ��

�����ڵ�i����һ֧��Ʊ�ܵ����󣽵�(i-1)�����Ʊʣ�µ�������󣫵�ǰ��Ʊ�ļ۸�

Ҳ����˵��Ҫά������״̬����Ϣ��һ�������Ʊ���õ���ʣ���������һ����������Ʊ֮��õ�������������ǻ��������Է�����Ϣ��

������һ���������ά��һ����������

��������˵�������Ƿ���ȡ��������֮���Ƿ��֮ǰ����ʣ�������󣬼�״̬ת�Ʒ���Ϊ��

buy[i] = max(buy[i-1], sell[i-2] - prices[i-1]);

��������˵��ͬ�������Ƿ���ֻ��Ʊ����ȡ���������ܷ��ø��������״̬ת�Ʒ���Ϊ��

sell[i] = max(sell[i-1], sell[i-1] + prices[i-1]);

*/
