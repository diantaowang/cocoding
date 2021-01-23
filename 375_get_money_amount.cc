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
    int getMoneyAmount(int n) {
        int dp[201][201];
        for (int i = 0; i < 201; ++i)
            dp[i][i] = 0;
        for (int j = 2; j <= n; ++j) {
            for (int i = j - 1; i > 0; --i) {
                int tmp = j + dp[i][j - 1];
                for (int k = (i + j) / 2; k < j; ++k)
                    tmp = min(tmp, k + max(dp[i][k - 1], dp[k + 1][j]));
                dp[i][j] = tmp;
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount2(int n) {
        vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0));
        for (int len = 1; len <= n - 1; ++len) {
            for (int i = 1; i + len <= n; ++i) {
                int j = i + len;
                int tmp = INT32_MAX;
                for (int k = i; k <= j; ++k)
                    tmp = min(tmp, k + max(dp[i][k - 1], dp[k + 1][j]));
                dp[i][j] = tmp;
            }
        }
        return dp[1][n];
    }
};

int main()
{
    return 0;
}
