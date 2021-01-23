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
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int minval = INT32_MIN, maxval = INT32_MAX;
        int result = 0, inc = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                maxval = min(maxval, nums[i]);
                minval = max(minval, nums[i - 1]);
            } else {
                maxval = min(maxval, nums[i - 1]);
                minval = max(minval, nums[i]);
            }
            result += abs(nums[i] - nums[i - 1]);
        }
        if (minval > maxval)
            inc = 2 * (minval - maxval);
        for (int i = 0; i < n - 1; ++i) {
            int v0 = abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]);
            int v1 = abs(nums[n - 1] - nums[i]) - abs(nums[i + 1] - nums[i]);
            inc = max(inc, max(v0, v1));
        }
        return result + inc;
    }
};

int main()
{
    return 0;
}
