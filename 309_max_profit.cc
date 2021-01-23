#include <vector>

using namespace::std;

// 0: 一天交易结束后持有股票
// 1: 一天交易开始前持有股票，一天交易结束后不持有股票
// 2: 一天交易开始前不持有股票，一天交易结束后不持有股票　

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int> (3));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }
        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};
