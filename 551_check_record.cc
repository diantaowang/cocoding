#include "bits/stdc++.h"

using namespace::std;

class Solution {
public:
    bool checkRecord(string s) {
        int cnt = 0, n = s.size(), k = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A') {
                ++cnt;
            } else if (s[i] == 'L' && i >= 2 && s[i - 1] == 'L' && s[i - 2] == 'L') {\
                k = 1;
            }
            if (k || cnt == 2) {
                return false;
            }
        }
        return true;
    }
};
