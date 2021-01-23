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
    int lengthOfLongestSubstring(string s) {
        vector<int> cnts(128, -1);
        int maxlen = 0, start = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (cnts[s[i]] == -1 || cnts[s[i]] < start)
                cnts[s[i]] = i;
            else {
                maxlen = max(maxlen, i - start);
                start = cnts[s[i]] + 1;
                cnts[s[i]] = i;
            }
            
        }
        return max(maxlen, n - start);
    }
};

int main()
{
    return 0;
}
