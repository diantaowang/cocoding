#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size(), ret = 0;
        vector<int> cnts(26, 0);
        for (const auto &e : s) {
            int idx = e - 'a';
            int next = 1;
            for (int i = 0; i < 26; ++i) {
                next = (next + cnts[i]) % 1000000007;
            }
            cnts[idx] = next;
        }
        for (int i = 0; i < 26; ++i) {
            ret = (ret + cnts[i]) % 1000000007;
        }
        return ret;
    }
};
