#include <string>
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    bool isMatchSlow(string s, string p) {
        s.push_back('a');
        p.push_back('a');
        vector<vector<int>> dp(p.size());
        int alpha = 1;
        if (p[0] == '*') {
            dp[0].push_back(0);
            alpha = 0;
        } else if (p[0] == '?' || p[0] == s[0]) {
            dp[0].push_back(0);
            alpha = 1;
        } else
            return 0;
        for (unsigned i = 1; i < p.size(); ++i) {
            alpha = 1;
            if (p[i] == '*') {
                dp[i].push_back(dp[i - 1][0] + alpha);
                alpha = 0;
            } else if (p[i] == '?' && alpha == 0) {
                for (unsigned j = dp[i - 1][0]; j < s.size(); ++j)
                    dp[i].push_back(j);
            } else if (p[i] == '?' && alpha == 1) {
                for (const auto &item : dp[i - 1]) {
                    if (item < s.size() - 1)
                        dp[i].push_back(item + 1);
                    }
            } else if (alpha == 0) {
                for (unsigned j = dp[i - 1][0]; j < s.size(); ++j) {
                    if (p[i] == s[j])
                        dp[i].push_back(j);
                }
            } else {
                for (const auto &item : dp[i - 1]) {
                    if (item < s.size() - 1 && p[i] == s[item + 1])
                        dp[i].push_back(item + 1);
                }
            }
            if (dp[i].empty())
                return 0;
        }
        if (dp[p.size() - 1].back() == s.size() - 1)
            return 1;
        else 
            return 0;
    }

    bool isMatch(string s, string p) {
        unsigned i = 0, j = 0, s_begin = -1, p_begin = -1, s_size = s.size(), p_size = p.size();
        while (i < s_size) {
            if (j < p_size && (p[j] == '?' || p[j] == s[i])) {
                ++i;
                ++j;
            } else if (j < p_size && p[j] == '*') {
                s_begin = i; 
                p_begin = ++j;
            } else if (s_begin >= 0) {
                i = ++s_begin;
                j = p_begin;
            } else
                return 0;
        }
        while (j < p_size && p[j] == '*')
            ++j;
        return j == p_size;
    }
};

int main()
{
    string s, p;
    Solution solu;
    cin >> s >> p;
    cout << solu.isMatch(s, p) << endl;
    return 0;
}

