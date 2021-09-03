#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (nums.size() == 1 || sum % 2) {
            return false;
        }
        int n = sum / 2;
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j >= nums[i]) {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
            }
        }
        return dp[n];
    }
};
