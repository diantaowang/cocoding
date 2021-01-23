#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, INT32_MAX));
        vector<int> sums(n + 1, 0);
        for (int i = 1; i < n + 1; ++i)
            sums[i] += sums[i - 1] + nums[i - 1];
        dp[0][1] = 0;
        for (int i = 1; i < n + 1; ++i) {
            int upper = min(i, m);
            for (int j = 2; j <= upper; ++j) {
                for (int k = i; k > j - 1; --k) {
                    int tmp = max(dp[k - 1][j - 1], sums[i] - sums[k - 1]);
                    dp[i][j] = min(dp[i][j], tmp);
                }
            }
            dp[i][1] = sums[i];
        }
        return dp[n][m];
    }
};
