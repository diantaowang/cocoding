#include <iostream>
#include <vector>
#include <string>

using namespace::std;

// NOTE: make sure that knight has one HP at least in any position;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        if (n == 0)
            return 0;
        int m = dungeon[0].size();
        if (m == 0)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, INT32_MAX));
        dp[n][m - 1] = dp[n - 1][m] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int minval = min(dp[i + 1][j], dp[i][j + 1]);
                if (dungeon[i][j] >= minval)
                    dp[i][j] = 1;
                else
                    dp[i][j] = minval - dungeon[i][j];
            }
        }
        return dp[0][0]; 
    }
};

