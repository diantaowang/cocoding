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
    bool checkValidString(string s) {
        vector<int> stk;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                stk.push_back(i);
            } else if (s[i] == ')') {
                if (!stk.empty() && s[stk.back()] == '(') {
                    stk.pop_back();
                } else {
                    stk.push_back(i);
                }
            }
        }
        if (stk.empty())
            return true;
        int i = 0, j = 0;
        while (i < n && j < (int)stk.size()) {
            if (s[stk[j]] == ')') {
                while (i < stk[j] && s[i] != '*')
                    ++i;
                if (i == stk[j])
                    return false;
                ++i;
                ++j;
            } else {
                i = max(i, stk[j] + 1);
                while (i < n && s[i] != '*')
                    ++i;
                if (i == n)
                    return false;
                ++i;
                ++j;
            }
        }
        return j == (int)stk.size();
    }
};

int main()
{
    return 0;
}
