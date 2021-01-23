#include <vector>

using namespace::std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        int minval = prices[0], profit = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] - minval > profit)
                profit = prices[i] - minval;
            if (prices[i] < minval)
                minval = prices[i];
        }
        return profit;
    }
};
