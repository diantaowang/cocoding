#include <string>
#include <iostream>

using namespace::std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty())
            return 0;
        int left = 0, right = 0, max = 0, new_max = 0;
        unsigned last_start = 0;
        for (unsigned i = 0; i < s.size(); ++i) {
            auto c = s[i];
            if (left == 0) {
                last_start = i;
                if (new_max > max)
                    max = new_max;
                if (c == '(')
                    ++left;
                else
                    new_max = 0;
            } else {
                if (c == '(')
                    ++left;
                else {
                    --left;
                    ++new_max;
                }
            }
        }
        if (left == 0)
            max = new_max > max ? new_max : max;
        else {
            new_max = 0;
            for (unsigned i = s.size(); i-- > last_start; ) {
                auto c = s[i];
                if (right == 0) {
                    if (new_max > max)
                        max = new_max;
                    if (c == ')')
                        ++right;
                    else
                        new_max = 0;
                } else {
                    if (c == ')')
                        ++right;
                    else {
                        --right;
                        ++new_max;
                    }
                }
            }
            if (right == 0)
                max = new_max > max ? new_max : max;
        }
        return 2 * max;
    }
};

int main()
{
    // string s("(()");
    // string s(")()())");
    // string s(")()(((())))(");
    string s;
    cin >> s;
    Solution solu;
    cout << solu.longestValidParentheses(s) << endl;
    return 0;
}
