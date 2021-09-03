#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) {
            return 0;
        } 
        if (n == 1) {
            return 1;
        }
        vector<int> nums(n + 1, 0);
        nums[1] = 1;
        int ret = 1;
        for (int  i = 2; i <= n; ++i) {
            nums[i] = nums[i / 2];
            if (i & 0x1) {
                nums[i] += nums[i / 2 + 1];
            }
            ret = max(ret, nums[i]);
        }
        return ret;
    }
};
