#include <string>
#include <vector>

using namespace::std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        if (!n)
            return 1;
        if (t.empty())
            return 0;
        int idx = 0;
        for (const auto& e : t) {
            if (e == s[idx])
                ++idx;
            if (idx == n)
                return 1;
        }
        return 0;
    }
};
