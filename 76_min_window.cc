#include <string>
#include <vector>
#include <iostream>

using namespace::std;

class Solution {
public:
    bool compvec(vector<int>& a, vector<int>& b) {
        for (unsigned i = 0; i < a.size(); ++i) {
            if (a[i] < b[i])
                return false;
        }
        return true;
    }
    string minWindowSlow(string s, string t) {
        vector<int> substr_cnts(128, 0), cnts(128, 0);
        unsigned begin = 0, end = UINT32_MAX;
        for (const auto& e : t)
            ++substr_cnts[e];
        for (unsigned l = 0, r = 0; r < s.size(); ++r) {
            if (substr_cnts[s[r]] != 0) {
                ++cnts[s[r]];
                while (compvec(cnts, substr_cnts)) {
                    while (substr_cnts[s[l]] == 0) 
                        ++l;
                    if (r - l < end - begin) {
                       end = r;
                       begin = l;
                    }
                    --cnts[s[l]];
                    ++l;
                }
            }
        }
        if (end == UINT32_MAX)
            return string();
        return s.substr(begin, end - begin + 1);
    }
    string minWindow(string s, string t) {
        vector<int> cnts(128, 0);
        unsigned start = 0, lens = UINT32_MAX, nums = t.size();
        for (const auto& e : t)
            ++cnts[e];
        for (unsigned l = 0, r = 0; r < s.size(); ++r) {
            if (cnts[s[r]]-- > 0) 
                --nums;
            while (nums == 0) {
                if (r - l < lens - 1) {
                    start = l;
                    lens = r - l + 1;
                }
                if (cnts[s[l++]]++ == 0)
                    ++nums;
            }
        }
        return lens == UINT32_MAX ? "" : s.substr(start, lens);
    }
};


int main()
{
    string s, t;
    cin >> s >> t;
    Solution solu;
    cout << solu.minWindow(s, t) << endl;
    return 0;
}
