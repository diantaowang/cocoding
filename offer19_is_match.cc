#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    bool isMatch(string s, string p) {
        s.push_back('a');
        p.push_back('a');
        int m = p.size(), n = s.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));        
        dp[0][0] = 1;
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (p[i - 1] == '.' || p[i - 1] == s[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 2][j];
                    dp[i][j] |= dp[i - 1][j];
                    if (p[i - 2] == '.' || p[i - 2] == s[j - 1])
                        dp[i][j] |= dp[i][j - 1];
                }
            }
            dp[i][0] = (p[i - 1] == '*') && dp[i - 2][0];
        }
        return dp[m][n];
    }
};
