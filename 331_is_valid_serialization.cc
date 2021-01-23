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
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        stack<char> stk;
        for (int i = 0; i < n; ++i) {
            string symbol;
            while (i != n && preorder[i] != ',') {
                symbol += preorder[i];
                ++i;
            }
            char c = symbol == "#" ? '#' : 'a';
            if (stk.empty()) {
                stk.push(c);
                continue;
            }
            if (c == '#' && stk.top() == '#') {
                while (!stk.empty() && c == '#' && stk.top() == '#') {
                    stk.pop();
                    if (stk.empty())
                        return false;
                    char tmp = stk.top();
                    if (tmp == '#')
                        return false;
                    stk.pop();
                }
                stk.push('#');
            } else {
                stk.push(c);
            }
        }
        return stk.empty() || (stk.size() == 1 && stk.top() == '#');
    }
};

int main()
{
    return 0;
}
