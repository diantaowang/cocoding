#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k == 0 || n < 2)
            return 0;
        if (k >= n / 2) {
            int prev_unhold = 0, prev_hold = -prices[0];
            for (int i = 1; i < n; ++i) {
                int unhold = max(prev_hold + prices[i], prev_unhold);
                int hold = max(prev_unhold - prices[i], prev_hold);
                prev_unhold = unhold;
                prev_hold = hold;
            }
            return prev_unhold;
        }

        vector<int> prev_unhold(k + 1, 0), prev_hold(k + 1, INT32_MIN);
        vector<int> unhold(k + 1, 0), hold(k + 1, 0);
        prev_hold[1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < k + 1; ++j)
                hold[j] = max(prev_unhold[j - 1] - prices[i], prev_hold[j]);
            for (int j = 1; j < k + 1; ++j)
                unhold[j] = max(prev_hold[j] + prices[i], prev_unhold[j]);
            for (int j = 1; j < k + 1; ++j) {
                prev_hold[j] = hold[j];
                prev_unhold[j] = unhold[j];
            }
        }
        int maxval = 0;
        for (int i = 0; i < k + 1; ++i) {
            if (maxval < prev_unhold[i])
                maxval = prev_unhold[i];
        }
        return maxval;
    }
};


