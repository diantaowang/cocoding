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
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), all = 0;
        for (const auto& e : nums)
            all += e;
        sort(nums.begin(), nums.end());
        int target = all / k;
        if (all % k || nums[n - 1] > target)
            return false;
        vector<bool> dp(1 << n, false);
        vector<int> sums(1 << n, 0);
        dp[0] = true;
        for (int i = 0; i < (1 << n) - 1; ++i) {
            if (!dp[i])
                continue;
            for (int j = 0; j < n; ++j) {
                int next = i | (1 << j);
                if (i != next && !dp[next]) {
                    if (nums[j] <= target - (sums[i] % target)) {
                        dp[next] = true;
                        sums[next] = sums[i] + nums[j];
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};

int main()
{
    return 0;
}
