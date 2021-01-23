#include <vector>

using namespace::std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int sum = nums[0], maxval = nums[0];
        for (int i = 1; i < n; ++i) {
            if (sum < 0)
                sum = nums[i];
            else
                sum += nums[i];
            if (maxval < sum)
                maxval = sum;
        }
        return maxval;
    }
};
