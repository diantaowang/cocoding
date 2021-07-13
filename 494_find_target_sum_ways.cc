#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.cbegin(), nums.cend(), 0);
        int tmp = sum - target;
        if (tmp < 0 || tmp & 0x1)
            return 0;
        int neg = tmp / 2;
        vector<int> dp(neg + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = neg; j >= nums[i]; --j) 
                dp[j] += dp[j - nums[i]];
        }
        return dp[neg];
    }

    int findTargetSumWays2(vector<int>& nums, int target) {
        vector<vector<int>> dp(2, vector<int> (20001, 0));
        dp[0][nums[0] + 10000] = 1;
        dp[0][-nums[0] + 10000] += 1;
        for (int i = 1; i < nums.size(); ++i) {
            int now = i & 0x1, prev = 1 - now;
            for (int j = 0; j < 20001; ++j)
                dp[now][j] = 0;
            for (int j = 0; j < 20001; ++j) {
                if (dp[prev][j] && j + nums[i] <= 20000)
                    dp[now][j + nums[i]] += dp[prev][j];
                if (dp[prev][j] && j - nums[i] >= 0)
                    dp[now][j - nums[i]] += dp[prev][j];
            }
        }
        return dp[(nums.size() - 1) & 0x1][target + 10000];
    }
    
    int findTargetSumWays3(vector<int>& nums, int target) {
        int sum = accumulate(nums.cbegin(), nums.cend(), 0);
        int tmp = sum - target;
        if (tmp < 0 || tmp & 0x1)
            return 0;
        int neg = tmp / 2;
        vector<vector<int>> dp(2, vector<int> (neg + 1, 0));
        dp[0][0] = 1;
        if (nums[0] <= neg)
            dp[0][nums[0]] += 1;
        for (int i = 1; i < nums.size(); ++i) {
            int now = i & 0x1, prev = 1 - now;
            for (int j = 0; j <= neg; ++j)
                dp[now][j] = dp[prev][j];
            for (int j = 0; j <= neg; ++j) {
                if (dp[prev][j] && nums[i] + j <= neg)
                    dp[now][j + nums[i]] += dp[prev][j];
            }
        }
        return dp[(nums.size() - 1) & 0x1][neg];
    }
};
