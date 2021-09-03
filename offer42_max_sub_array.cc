#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
	    int ret = nums[0], sum = nums[0], n = nums.size();
        for (unsigned i = 1; i < n; ++i) {
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            ret = max(ret, sum);
        }
        return ret;
    }
};
