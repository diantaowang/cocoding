#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int pre = nums[0];
        int maxval = nums[0];
        for (int i = 1; i < n; ++i) {
            pre = max(pre + nums[i], nums[i]);
            maxval = max(maxval, pre);
        }
        return maxval;
    }
};
