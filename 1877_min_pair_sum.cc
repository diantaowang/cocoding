#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
        int ret = 0;
        auto n = nums.size();
        for (unsigned i = 0; i < n / 2; ++i) {
            ret = max(ret, nums[i] + nums[n - 1 - i]);
        }
        return ret;
    }
};

