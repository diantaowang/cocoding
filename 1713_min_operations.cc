#include <algorithm>
#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        unordered_map<int, int> pos;
        for (unsigned i = 0; i < n; ++i) {
            pos[target[i]] = i;
        }
        vector<int> dp;
        for (const auto &e : arr) {
            if (pos.find(e) != pos.end()) {
                auto val = pos[e];
                auto pos = lower_bound(dp.begin(), dp.end(), val);
                if (pos == dp.end()) {
                    dp.emplace_back(val);
                } else {
                    *pos = val;
                }
            }
        }
        return n - dp.size();
    }
};

