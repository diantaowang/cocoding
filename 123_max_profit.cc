#include <cerrno>
#include <pthread.h>
#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        vector<int> dp(n, 0);
        int minval = prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1], prices[i] - minval);
            minval = min(minval, prices[i]);
        }
        int maxval = prices[n - 1], result = dp[n - 1];
        for (int i = n - 2; i > 0; --i) {
            result = max(result, dp[i - 1] + maxval - prices[i]);
            maxval = max(maxval, prices[i]);
        }
        return result;
    }

    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)
            return 0;
        int pre_hold[3] = {0, -prices[0], INT32_MIN};
        int pre_unhold[3] = {0, 0, 0};
        int hold[3], unhold[3];
        for (int i = 1; i < n; ++i) {
            hold[1] = max(-prices[i], pre_hold[1]);
            hold[2] = max(pre_unhold[1] - prices[i], pre_hold[2]);
            unhold[1] = max(hold[1] + prices[i], pre_unhold[1]);
            unhold[2] = max(hold[2] + prices[i], pre_unhold[2]);
            pre_hold[1] = hold[1];
            pre_hold[2] = hold[2];
            pre_unhold[1] = unhold[1];
            pre_unhold[2] = unhold[2];
        }
        int maxval = max(pre_unhold[1], pre_unhold[2]);
        return max(0, maxval);
    }
};
