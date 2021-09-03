#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    string decodeString(string s) {
        int n = s.size(), num = 0;
        stack<char> stk;
        string ret, part;
        for (unsigned i = 0; i < n; ++i) {
            if (s[i] == ']') {
                while (!isdigit(stk.top())) {
                    part.push_back(stk.top());
                    stk.pop();
                }
                part.pop_back();
                int base = 1;
                while (!stk.empty() && isdigit(stk.top())) {
                    num += (stk.top() - '0') * base;
                    base *= 10;
                    stk.pop();
                }
                while (num-- > 0) {
                    for (int j = part.size() - 1; j >= 0; --j) {
                        stk.push(part[j]);
                    }
                }      
                part.clear();
                num = 0;;
            } else {
                stk.push(s[i]);
            }
        }
        while (!stk.empty()) {
            ret.push_back(stk.top());
            stk.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main()
{
    return 0;
}
