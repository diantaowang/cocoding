#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int compress(vector<char>& chars) {
		int n = chars.size(), cnt = 1, pos = 0;
        char c = chars[0];
        for (int i = 1; i <= n; ++i) {
            if (i != n && c == chars[i]) {
                ++cnt;
                continue;
            }
            
            chars[pos++] = c;
            if (cnt > 1) {
                string num = to_string(cnt);
                for (const auto &e : num) {
                    chars[pos++] = e;
                }
            }

            if (i != n) {
                c = chars[i];
                cnt = 1;
            }
        }
        for (int i = pos + 1; i < n; ++i) {
            chars[i] = '\0';
        }
        return pos;
    }
};
