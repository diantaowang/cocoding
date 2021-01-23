#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace::std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int n = s.size(), maxlen = 1;
        if (!n) return 0;

        unordered_set<char> dict;
        int begin = 0;
        dict.insert(s[0]);
        for (int i = 1; i < n; ++i) {
            if (dict.find(s[i]) != dict.end()) {
                if (i - begin > maxlen)
                    maxlen = i - begin;
                while (s[begin] != s[i]) {
                    dict.erase(s[begin]);
                    ++begin;
                }
                ++begin;
            } else if (i == n - 1) {
                maxlen = max(maxlen, n - begin);
            } else {
                dict.insert(s[i]);
            }
        }
        return maxlen;
    }
};
