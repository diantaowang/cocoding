#include <vector>

using namespace::std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 3; i <= n; ++i) {
            int l = 1, r = i - 1;
            while (l <= r) {
                int t0 = max(l * r, dp[l] * dp[r]);
                int t1 = max(t0, l * dp[r]);
                int t2 = max(t1, dp[l] * r);
                dp[i] = max(dp[i], t2);
                ++l;
                --r;
            }
        }
        return dp[n];
    }
};
