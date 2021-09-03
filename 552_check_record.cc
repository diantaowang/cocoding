#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int checkRecord(int n) {
        long long mod = 1000000007;
        long long dp[2][3][2];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 2; ++j) {
                dp[0][i][j] = 0;
            }
        }
        dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = 1;
        for (int i = 1; i < n; ++i) {
            int now = i & 0x1, old = 1 - now;
            dp[now][0][0] = (dp[old][0][0] + dp[old][1][0] + dp[old][2][0]) % mod;
            dp[now][0][1] = (dp[old][0][0] + dp[old][1][0] + dp[old][2][0] + dp[old][0][1] + dp[old][1][1] + dp[old][2][1]) % mod;
            dp[now][1][0] = dp[old][0][0];
            dp[now][1][1] = dp[old][0][1];
            dp[now][2][0] = dp[old][1][0];
            dp[now][2][1] = dp[old][1][1];
        }
        int id = (n - 1) & 0x1;
        return (dp[id][0][0] + dp[id][0][1] + dp[id][1][0] + dp[id][1][1] + dp[id][2][0] + dp[id][2][1]) % mod;
    }
};
