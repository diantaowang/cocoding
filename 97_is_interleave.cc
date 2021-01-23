#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size())
            return false;
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        dp[0][0] = 1;
        for (int j = 1; j < m + 1; ++j)
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        for (int i = 1; i < n + 1; ++i)
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                int idx = i + j - 1;
                if (s3[idx] == s1[i - 1])
                    dp[i][j] |= dp[i - 1][j];
                if (s3[idx] == s2[j - 1])
                    dp[i][j] |= dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};

