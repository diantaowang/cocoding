#include <vector>

using namespace::std;

class Solution {
public:
    int find(int* nums, int n, int k) {
        if (n == 1)
            return nums[0];
        int minval = nums[0], maxval = nums[0];
        for (int i = 1; i < n; ++i) {
            if (minval > nums[i])
                minval = nums[i];
            else if (maxval < nums[i])
                maxval = nums[i];
        }
        int midval = (minval + maxval) / 2;
        if (minval == maxval)
            return midval;
        else if (minval + 1 == maxval)
            midval = minval;
        int l = 0, r = n - 1;
        while (l <= r) {
            if (nums[l] <= midval)
                ++l;
            else if (nums[l] > midval) {
                int t = nums[l];
                nums[l] = nums[r];
                nums[r] = t;
                --r;
            }
        }
        if (l >= k)
            return find(nums, l, k);
        else
            return find(nums + l, n - l, k - l);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int vec[nums.size()];
        for (unsigned i = 0; i < nums.size(); ++i)
            vec[i] = nums[i];
        return find(vec, nums.size(), nums.size() - k + 1);
    }
};
