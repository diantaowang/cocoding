#include <vector>

using namespace::std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit = 0;
        if (n == 0)
            return 0;
        int pre_hold = -prices[0], pre_unhold = 0;
        for (int i = 1; i < n; ++i) {
            int hold = max(pre_hold, pre_unhold - prices[i]);
            int unhold = max(pre_hold + prices[i], pre_unhold);
            pre_hold = hold;
            pre_unhold = unhold;
        }
        return pre_unhold;
    }
    
    int maxProfit2(vector<int>& prices) 
    {
        int n = prices.size(), profit = 0;
        if (n == 0)
            return 0;
        int last = prices[0];
        for (int i = 1; i < n; ++i) {
            if (prices[i] > last)
                profit += prices[i] - last;
            last = prices[i];
        }
        return profit;
    }

    int maxProfit3(vector<int>& prices) {
        int n = prices.size(), profit = 0;
        if (n == 0)
            return 0;
        int minval = prices[0], maxval = prices[0];
        for (int i = 1; i < n; ++i) {
            if (prices[i] > maxval)
                maxval = prices[i];
            if (prices[i] < maxval || i == n - 1) {
                profit += maxval - minval;
                maxval = minval = prices[i];
            }
        }
        return profit;
    }
};
