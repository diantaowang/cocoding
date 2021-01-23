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
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        string prefix;
        int idx = 0, n = strs[0].size();
        for (int i = 1; i < strs.size(); ++i)
            n = min(n, (int)strs[i].size());
        while (idx != n) {
            char c = strs[0][idx];
            bool equl = true;
            for (int i = 1; i < strs.size(); ++i) {
                if (c != strs[i][idx]) {
                    equl = false;
                    break;
                }
            }
            if (equl)
                prefix.push_back(c);
            else
                break;
            ++idx;
        }
        return prefix;
    }
};

int main()
{
    return 0;
}
