#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        if (s[0] == '0')
            return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1; 
        for (int i = 2; i < n + 1; ++i) {
            if (s[i - 1] == '0' && (s[i - 2] == '0' || s[i - 2] > '2'))
                return 0;
            if (s[i - 1] == '0')
                dp[i] = dp[i - 2];
            else if (s[i - 2] == '0' || s[i - 2] > '2' || (s[i - 2] == '2' && s[i - 1] > '6'))
                dp[i] = dp[i - 1];
            else
                dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
