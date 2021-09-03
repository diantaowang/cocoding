#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long ret = 1;
        sort(nums.begin(), nums.end());
        vector<long long> sum(1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sum.emplace_back(sum.back() + nums[i]);
        }
        for (int l = 0, r = 1; r <= nums.size(); ) {
            long long cnt = r - l;
            if (cnt * nums[r - 1] <= sum[r] - sum[l] + k) {
                ret = max(ret, cnt);
                ++r;
            } else {
                ++l;
            }
        }
        return ret;
    }
};
