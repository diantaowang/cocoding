#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int numTrees(int n) {
        if (n == 1 || n == 2)
            return n;
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            for (int j = i - 1, k = 0; j >= 0; --j, ++k)
                dp[i] += dp[j] * dp[k];
        }
        return dp[n];
    }
};


