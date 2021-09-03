#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int calc(int val) {
        int width = -1, ret = 0;
        for (int i = val; i > 0; i /= 10) {
            ++width;
        }
        if (width == -1) {
            return 0;
        }
        if (width == 0) {
            return 1;
        }
        
        int high = val / base[width];
        int res = val % base[width];
        ret += high * cnts[width - 1];
        if (high == 1) {
            ret += res + 1;
        } else {
            ret += base[width];
        }
        return ret + calc(res);
    }
    
    int countDigitOne(int n) {
        for (int i = 1, base = 10; i < 10; ++i, base *= 10) {
            cnts[i] = base + cnts[i - 1] * 10;
        }
        return calc(n);
    }

private:
    vector<int> cnts = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> base = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
};
