#include <cstdint>
#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, INT32_MAX));
        dp[0][1] = dp[1][0] = 0;
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) 
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        }
        return dp[m][n];
    }
};
