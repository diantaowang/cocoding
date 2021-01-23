#include <vector>
#include <iostream>

using namespace::std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
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
};

int main() 
{
    vector<int> nums{2, 2, 3, 5};
    Solution solu;
    solu.canPartition(nums);
    return 0;
}
