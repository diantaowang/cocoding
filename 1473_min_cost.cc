#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>

using namespace::std;

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int inf = 1000010;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>> (target + 1, vector<int> (n + 1, inf)));
        for (int k = 1; k <= n; ++k)
            dp[0][0][k] = 0;
        for (int i = 1; i <= m; ++i) {
            int color = houses[i - 1];
            for (int j = 1; j <= min(target, i); ++j) {
                if (color) {
                    dp[i][j][color] = dp[i - 1][j][color];
                    for (int k = 1; k <= n; ++k) {
                        if (k != color)
                            dp[i][j][color] = min(dp[i][j][color], dp[i - 1][j - 1][k]);
                    } 
                    continue;
                }

                for (int k = 1; k <= n; ++k) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    for (int z = 1; z <= n; ++z) {
                        if (z != k)
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][z]);
                    }
                    dp[i][j][k] += cost[i - 1][k - 1];
                }
            }
        }
        int res = inf;
        for (int i = 1; i <= n; ++i)
            res = min(res, dp[m][target][i]);
        return res < inf ? res : -1;
    }
};

int main()
{
    return 0;
}
