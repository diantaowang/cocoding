#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace::std;

class Solution {
public:
    bool wordBreak_139(string s, vector<string>& wordDict) {
        unordered_set<string> dirs;
        int maxlen = 0;
        for (const auto& e : wordDict) {
            int len = e.size();
            if (!len)
                continue;
            dirs.insert(e);
            if (len > maxlen)
                maxlen = len;
        }
        vector<int> pos(1, 0);
        for (int i = 0; i < s.size(); ++i) {
            int j = pos.size();
            while (j-- > 0) {
                int n = i + 1 - pos[j];
                if (n > maxlen)
                    break;
                if (dirs.find(s.substr(pos[j], n)) != dirs.end()) {
                    pos.push_back(i + 1);
                    break;
                }
            }
        }
        return pos.back() == s.size();
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (!wordBreak_139(s, wordDict))
            return vector<string> ();
        int n = s.size(), maxlen = -1;
        unordered_set<string> dicts;
        for (const auto& e : wordDict) {
            maxlen = max(maxlen, (int) e.size());
            dicts.insert(e);
        }
        vector<int> dp(1, 0);
        vector<string> results;
        vector<int> last_pos;
        for (int i = 0; i < n; ++i) {
            int idx = dp.size(), not_push = 1;
            while (idx-- > 0) {
                int start = dp[idx];
                int len = i + 1 - start;
                if (len > maxlen)
                    break;
                auto substring = s.substr(start, len);
                if (dicts.find(substring) != dicts.end()) {
                    if (not_push) {
                        dp.push_back(i + 1);
                        not_push = 0;
                    }
                    
                    if (!start) {
                        results.push_back(substring);
                        last_pos.push_back(i + 1);
                        break;
                    }

                    int j = last_pos.size();
                    while (j-- > 0) {
                        if (start == last_pos[j]) {
                            results.push_back(results[j] + ' ' + substring);
                            last_pos.push_back(i + 1);
                        }
                    }
                }
            }  
        }
        vector<string> real_result;
        for (int i = 0; i < (int)last_pos.size(); ++i) {
            if (last_pos[i] == n)
                real_result.push_back(results[i]);
        }
        return real_result;
    }
};
