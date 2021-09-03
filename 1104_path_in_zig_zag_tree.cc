#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ret;
        while (label != 1) {
            ret.emplace_back(label);
            int original = label / 2;
            int n = log2(original);
            int sum = pow(2, n) + pow(2, n + 1) - 1;
            label = sum - original;
        }
        ret.push_back(1);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
