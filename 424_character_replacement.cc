#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>

using namespace::std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.empty())
            return 0;
        vector<int> cnts(128, 0);
        int result = 0, l = 0, r = 0, maxlen = 0;
        while (r < s.size()) {
            ++cnts[s[r]];
            maxlen = max(maxlen, cnts[s[r]]);
            if (r - l + 1 > maxlen + k) {
                --cnts[s[l]];
                ++l;
            }
            ++r;
        }
        return r - l;
    }

    int characterReplacement2(string s, int k) {
		if (s.empty())
            return 0;
        vector<int> cnts(26, 0);
        int result = 0, l = 0, r = -1;
        while (r < (int)s.size()) {
            int maxval = 0;
            for (int i = 0; i < 26; ++i)
                maxval = max(maxval, cnts[i]);
            if (r - l + 1 <= maxval + k) {
                ++r;
                if (r != (int)s.size())
                    ++cnts[s[r] - 'a'];
                result = max(result, r - l);
            } else {
                --cnts[s[l] - 'a'];
                ++l;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
