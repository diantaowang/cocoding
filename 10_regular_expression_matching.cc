#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace::std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // s.push_back('a');
        // s.push_back('a');
        // p.push_back('a');
        // p.push_back('a');
        auto s_size = s.size(), p_size = p.size();
        if (p_size == 0) {
            return s_size == 0 ? true : false;
        } else if (p_size == 1) {
            if (s_size == 1) {
                if (p[0] == '.' || p[0] == s[0])
                    return true;
            }
            return false;
        } else {
            if (s_size == 0) {
                for (unsigned i = 0; i < p_size; ) {
                    if (p[i] == '*')
                        ++i;
                    else if (i == p_size - 1 || p[i + 1] != '*')
                        return false;
                    else
                        i += 2;
                }
                return true;
            } else {
                vector<vector<int>> dp(p_size, vector<int> (s_size + 1, 0));
                for (unsigned i = 0; i < p_size; ) {
                    if (i == p_size - 1) {
                        // cout << "---------------------- last" << endl;
                        if ((p[i] == '.' || p[i] == s[s_size - 1]) && dp[i - 1][s_size - 1])
                            return true;
                        return false;
                    } else {
                        if (p[i] == '.' && p[i + 1] == '*') {
                            // cout << "---------------------- 1" << endl;
                            if (i == 0) {
                                for (int j = 0; j < (int)s_size + 1; ++j)
                                    dp[i + 1][j] = 1;
                            } else {
                                int pre_match = 0;
                                for (int j = 0; j < (int)s_size + 1; ++j) {
                                    if (dp[i - 1][j])
                                        pre_match = 1; 
                                    if (pre_match)
                                        dp[i + 1][j] = 1;
                                }
                            }
                            i += 2;
                        } else if (p[i + 1] == '*') {
                            // cout << "---------------------- 2" << endl;
                            if (i == 0) {
                                dp[i + 1][0] = 1;
                                for (unsigned k = 0; k < s_size && p[i] == s[k]; ++k)
                                    dp[i + 1][k + 1] = 1;
                            } else {
                                int pre_match = 0;
                                for (unsigned j = 0; j < s_size + 1; ) {
                                    if (dp[i - 1][j])
                                        pre_match = 1;
                                    if (pre_match) {
                                        dp[i + 1][j++] = 1;
                                        for (; j < s_size + 1 && p[i] == s[j - 1]; ++j)
                                           dp[i + 1][j] = 1;
                                        pre_match = 0;
                                    } else 
                                        ++j; 
                                }
                            }
                            i += 2;
                        } else if (p[i] == '.') {
                            // cout << "---------------------- 3" << endl;
                            if (i == 0)
                                dp[i][1] = 1;
                            else {
                                for (unsigned j = 0; j < s_size; ++j) {
                                    if (dp[i - 1][j])
                                        dp[i][j + 1] = 1;
                                }
                            }
                            ++i;
                        } else {
                            // cout << "---------------------- 4" << endl;
                            if (i == 0) {
                                if (p[0] != s[0])
                                    return false;
                                else 
                                    dp[0][1] = 1;
                            }
                            else {
                                for (unsigned j = 0; j < s_size; ++j) {
                                    if (dp[i - 1][j] && p[i] == s[j] )
                                        dp[i][j + 1] = 1;
                                }
                            }
                            ++i;
                        }
                    }
                }
                if (dp[p_size - 1][s_size])
                    return true;
                else 
                    return false;
            }
        }
    }
};

int main()
{
    Solution solu;
    string s, p;
    cin >> s >> p;
    cout << solu.isMatch(s, p) << endl;
    return 0;
}
