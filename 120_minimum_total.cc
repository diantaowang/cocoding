#include <cstdint>
#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0)
            return 0;
        vector<int> pre(n + 1, INT32_MAX), dp(n + 1, INT32_MAX);
        pre[1] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < i + 2; ++j)
                dp[j] = min(pre[j - 1], pre[j]) + triangle[i][j - 1];
            pre = dp;
        }
        int minval = pre[0];
        for (int i = 0; i < n + 1; ++i) {
            if (minval > pre[i])
                minval = pre[i];
        }

        return minval;
    }
};
