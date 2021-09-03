#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), ret = 0, l = 0;
        sort(nums.begin(), nums.end());
        nums.emplace_back(20001);
        while (!nums[l++]) {}
        for (int i = l; i < n - 2; ++i) {
            for (int j = i + 1, r = j + 1; j < n - 1; ++j) {
                while (nums[r] < nums[i] + nums[j]) {
                    ++r;
                }
                ret += r - j - 1;
            }
        }
        return ret;
    } 
};


