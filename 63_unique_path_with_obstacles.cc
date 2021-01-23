#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if (n == 0)
            return 0;
        vector<int> pre(n + 1, -1), dp(n + 1, -1);
        pre[1] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (obstacleGrid[i][j - 1])
                    dp[j] = -1;
                else if (dp[j - 1] == -1)
                    dp[j] = pre[j];
                else if (pre[j] == -1)
                    dp[j] = dp[j - 1];
                else
                    dp[j] = dp[j - 1] + pre[j];
            }
            pre = dp;
        }
        if (pre[n] == -1)
            return 0;
        else
            return pre[n];
    }
};
