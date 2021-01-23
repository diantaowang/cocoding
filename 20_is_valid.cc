#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <stack>

using namespace::std;

class Solution {
public:
    bool isValid(string s) {
		int n = s.size();
        if (!n) return true;
        stack<char> stk;
        for (int i = 0; i < n; ++i) {
            if (stk.empty()) {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                    stk.push(s[i]);
                else
                    return false;
            } else if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                char last = stk.top();
                stk.pop();
                if (last == '(' && s[i] != ')')
                    return false;
                if (last == '[' && s[i] != ']')
                    return false;
                if (last == '{' && s[i] != '}')
                    return false;
            }
        }
        if (stk.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    return 0;
}
