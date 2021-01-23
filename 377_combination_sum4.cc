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
    int dfs(vector<int>& dp, vector<int>& nums, int target) {
        if (dp[target] != -1)
            return dp[target];
        
        dp[target] = 0;
        for (const auto& e : nums) {
            if (e > target)
                break;
            dp[target] += dfs(dp, nums, target - e);
        }
        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        return dfs(dp, nums, target);
    }
    
    /*int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; ++i) {
            for (const auto& e : nums) {
                if (e <= i)
                    dp[i] += dp[i - e];
                else
                    break;
            }
        }
        return dp[target];
    }*/
};

int main()
{
    return 0;
}
