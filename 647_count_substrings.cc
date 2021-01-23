#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (!n)
            return 0;
        vector<int> dp(n, 1);
        vector<int> pos(1, 0);
        for (int i = 1; i < n; ++i) {
            vector<int> new_pos;
            new_pos.push_back(i);
            new_pos.push_back(i - 1);
            dp[i] = 1 + dp[i - 1];
            for (const auto& idx : pos) {
                if (s[i] == s[idx]) {
                    ++dp[i];
                    if (idx > 0)
                        new_pos.push_back(idx - 1);
                }
            }
            pos = new_pos;
        }
        return dp[n - 1];
    }
};
