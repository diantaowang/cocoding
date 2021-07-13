#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> prefix(30001, 0);
        prefix[0] = 1;
        int sum = 0, ret = 0;
        for (unsigned i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum >= goal) {
                ret += prefix[sum - goal];
            }
            ++prefix[sum];
        }
        return ret;
    }
};
