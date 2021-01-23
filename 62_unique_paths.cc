#include <vector>

using namespace::std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> dp(m, vector<int> (n + 1, 0));
        for (int i = 0; i < n + 1; ++i)
            dp[0][i] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n + 1; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        return dp[m - 1][n];
    }
};
