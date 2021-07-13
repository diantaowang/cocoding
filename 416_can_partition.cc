#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    bool canPartition2(vector<int>& nums) {
        int sum = 0;
        for (unsigned i = 0; i < nums.size(); ++i)
            sum += nums[i];
        if (sum % 2 || nums.size() == 1)
            return false;
        int half = sum >> 1;
        vector<int> dp(half + 1, 0);
        for (unsigned i = 0; i < nums.size(); ++i) {
            for (unsigned j = half + 1; --j > 0;) {
                if (dp[j] != 0) {
                    int idx = nums[i] + j;
                    if (idx <= half) 
                        dp[idx] = 1;
                }
            }
            if (nums[i] <= half)
                dp[nums[i]] = 1;
        }
        return dp[half];
    }
   
    int calc(vector<int>& nums, vector<vector<int>>& dp, int n, int target) {
        if (!n || dp[n][target]) 
            return dp[n][target];
        
        if (nums[n] > target)
            dp[n][target] = calc(nums, dp, n - 1, target);
        else if (calc(nums, dp, n - 1, target - nums[n]) || calc(nums, dp, n - 1, target))
            dp[n][target] = 1; 
        
        return dp[n][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.cbegin(), nums.cend(), 0);
        if (sum & 0x1 || nums.size() == 1)
            return false;
        vector<vector<int>> dp(nums.size(), vector<int> (sum / 2 + 1, 0));
        if (nums[0] <= sum / 2)
            dp[0][nums[0]] = 1;
        for (int i = 0; i < nums.size(); ++i)
            dp[i][0] = 1;
        return calc(nums, dp, nums.size() - 1, sum / 2);
    }
};

int main() 
{
    vector<int> nums{9, 5};
    Solution solu;
    cout << solu.canPartition(nums) << endl;;
    return 0;
}
