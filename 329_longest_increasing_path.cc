#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>

using namespace::std;

class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int row, int col,
            vector<vector<int>>& dp) {
        int m = matrix.size(), n = matrix[0].size();
       
        if (dp[row][col] != -1)
            return dp[row][col];

        int maxval = 1;
        if (row - 1 >= 0 && matrix[row][col] < matrix[row - 1][col])
            maxval = max(maxval, dfs(matrix, row - 1, col, dp) + 1);
        if (row + 1 < m && matrix[row][col] < matrix[row + 1][col])
            maxval = max(maxval, dfs(matrix, row + 1, col, dp) + 1);
        if (col - 1 >= 0 && matrix[row][col] < matrix[row][col - 1])
            maxval = max(maxval, dfs(matrix, row, col - 1, dp) + 1);
        if (col + 1 < n && matrix[row][col] < matrix[row][col + 1])
            maxval = max(maxval, dfs(matrix, row, col + 1, dp) + 1);

        dp[row][col] = maxval;
        return dp[row][col];
    };

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int result = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == -1)
                    result = max(result, dfs(matrix, i, j, dp));
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
