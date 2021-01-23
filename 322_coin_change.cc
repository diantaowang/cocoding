#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace::std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, INT32_MAX - 1);
        dp[0] = 0;
        int val = coins[0], cnt = 1;
        while (val <= amount) {
            dp[val] = cnt++;
            val += coins[0];
        }
        
        for (int i = 1; i < coins.size() && coins[i] <= amount; ++i) {
            for (int j = coins[i]; j <= amount; ++j) 
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
        return dp[amount] == INT32_MAX - 1 ? -1 : dp[amount];
    }
};

int main()
{
    Solution solu;
    vector<int> coins{1, 2, 5};
    solu.coinChange(coins, 100);
    return 0;
}
