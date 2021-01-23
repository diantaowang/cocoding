#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            int j = 1;
            dp[i] = INT32_MAX;
            while (1) {
                int val = j * j;
                if (val > i)
                    break;
                dp[i] = min(dp[i], dp[i - val] + 1);
                ++j;
            }
        }
        return dp[n];
    }
};
