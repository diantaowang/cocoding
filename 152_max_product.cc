#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        int pre_maxval = 0, pre_minval = 0;
        int maxval = 0, minval = 0;
        int result = nums[0];
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                maxval = minval = 0;
            } else if (nums[i] < 0) {
                minval = min(pre_maxval * nums[i], nums[i]);
                maxval = pre_minval * nums[i];
            } else {
                minval = pre_minval * nums[i];
                maxval = max(pre_maxval * nums[i], nums[i]);
            }
            pre_minval = minval;
            pre_maxval = maxval;
            if (result < pre_maxval)
                result = pre_maxval;
        }
        return result; 
    }
};
