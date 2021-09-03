#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, multiset<string>> records;
        for (const auto& s : strs) {
            auto tmp = s;
            sort(tmp.begin(), tmp.end());
            records[tmp].insert(s);
        }
        vector<vector<string>> ret;
        for (const auto& e : records) {
            vector<string> tmp;
            for (const auto& e2 : e.second) {
                tmp.push_back(e2);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
