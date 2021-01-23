#include <utility>
#include <vector>

using namespace::std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty())
            return 0;
        int pre_hold = - prices[0] - fee;
        int pre_unhold = 0;
        for (unsigned i = 1; i < prices.size(); ++i) {
            int hold = max(pre_hold, pre_unhold - prices[i] - fee);
            int unhold = max(pre_unhold, pre_hold + prices[i]);
            pre_hold = hold;
            pre_unhold = unhold;
        }
        return pre_unhold;
    }
};

