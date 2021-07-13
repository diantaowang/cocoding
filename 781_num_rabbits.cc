#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> robbits(1000, 0);
        int ret = 0;
        for (const auto& iter : answers)
            ++robbits[iter];
        for (int i = 1; i < 1000; ++i) {
            int cnt = robbits[i] / (i + 1);
            if (robbits[i] % (i + 1))
                ++cnt;
            ret += cnt * (i + 1);
        }
        return ret + robbits[0];
    }
};
