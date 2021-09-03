#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> cand(nums1);
        sort(cand.begin(), cand.end());
        unsigned long long ret = 0;
        auto n = nums1.size();
        int maxval = 0;
        for (int i = 0; i < n; ++i) {
            auto diff = abs(nums1[i] - nums2[i]);
            auto iter = upper_bound(cand.begin(), cand.end(), nums2[i]);
            if (iter == cand.end()) {
                maxval = max(maxval, diff - (nums2[i] - cand.back()));
            } else if (iter == cand.begin()) {
                maxval = max(maxval, diff - (cand[0] - nums2[i]));
            } else {
                auto v1 = *iter - nums2[i]; 
                auto v2 = nums2[i] - *(iter - 1);
                maxval = max(maxval, diff - min(v1, v2));
            }
            ret += diff;
        }
        return (ret - maxval) % 1000000007;
    }
};
