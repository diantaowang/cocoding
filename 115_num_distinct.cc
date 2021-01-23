#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace::std;

class Solution {
public:
    int numDistinct(string s, string t) {
 		int n = s.size(), m = t.size();	
        if (!n && !m)
            return 1;
        if (!n)
            return 0;
        set<char> elem;
        for (const auto& c : t)
            elem.insert(c);
        vector<long long> dp(m + 1, 0), next_dp(m + 1, 0);
        dp[0] = next_dp[0] = 1;
        for (int i = 1; i < n + 1; ++i) {
            if (elem.find(s[i - 1]) != elem.end()) {
                for (int j = 1; j < m + 1; ++j) {
                    if (s[i - 1] == t[j - 1])
                        next_dp[j] += dp[j - 1]; 
                }
            }
            dp = next_dp;
        }
        return dp[m];
    }
};
