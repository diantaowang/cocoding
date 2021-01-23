#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 2, 10010));
        for (int i = 1; i < n + 1; ++i) {
            int find = 0;
            for (int j = 1; j < m + 1; ++j) {
                if (matrix[i - 1][j - 1] == 0) {
                    find = 1;
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
            
            if (!find)
                continue;
            
            for (int j = m; j > 0; --j) {
                int minval = min(dp[i][j - 1], dp[i][j + 1]) + 1;
                if (minval < dp[i][j])
                    dp[i][j] = minval;
            }
            for (int ii = i - 1; ii > 0; --ii) {
                int change = 0;
                for (int j = m; j > 0; --j) {
                    int minval = min(min(dp[ii][j - 1], dp[ii][j + 1]),
                            min(dp[ii - 1][j], dp[ii + 1][j])) + 1;
                    if (minval < dp[ii][j]) {
                        change = 1;
                        dp[ii][j] = minval;
                    }
                }
                if (!change)
                    break;
            }
        }
        vector<vector<int>> results(n, vector<int> (m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                results[i][j] = dp[i + 1][j + 1];
        }
        return results;
    }
};
