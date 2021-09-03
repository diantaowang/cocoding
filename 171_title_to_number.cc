#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ret = 0;
        for (const auto &e : columnTitle) {
            ret = ret * 26 + e - 'A' + 1;
        }
        return ret;
    }
};
