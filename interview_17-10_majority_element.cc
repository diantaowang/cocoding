#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unsigned cnt = 0;
        int majority = 0;
        for (const auto& elem : nums) {
            if (cnt == 0) {
                majority = elem;
                ++cnt;
            } else if (elem == majority) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        cnt = 0;
        for (const auto& elem : nums) {
            if (elem == majority)
                ++cnt;
        }
        return cnt > nums.size() / 2 ? majority : -1;
    }
};
