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
    double dfs(vector<vector<vector<double>>>& dp, int r, int c, int k) {
        int n = dp.size();
        if (r < 0 || r >= n || c < 0 || c >= n)
            return 1.0;
        if (k == 0) {
            dp[r][c][k] = 0.0;
            return 0.0;
        }
        if (dp[r][c][k] != -1)
            return dp[r][c][k];

        dp[r][c][k] = 0.0;
        for (int i = 0; i < 8; ++i)
            dp[r][c][k] += dfs(dp, r + dr[i], c + dc[i], k - 1);
        dp[r][c][k] *= (1 / 8.0);
        return dp[r][c][k];
    }

    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N, vector<vector<double>> (N, vector<double> (K + 1, -1)));
        return 1.0 - dfs(dp, r, c, K); 
    }
private:
    int dr[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dc[8] = {1, -1, 1, -1, 2, -2, 2, -2};
};

int main()
{
    return 0;
}
