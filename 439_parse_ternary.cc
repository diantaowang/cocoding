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
    string parseTernary(string expression) {
        int n = expression.size();
        stack<char> res;
        stack<char> symbal;
        for (int i = n - 1; i >= 0; --i) {
            if (expression[i] == '?') {
                char e = expression[--i];
                char c1 = res.top();
                res.pop();
                char c2 = res.top();
                res.pop();
                if (e == 'T')
                    res.push(c1);
                else 
                    res.push(c2);
            } else if (expression[i] != ':'){
                res.push(expression[i]);
            }
        }
        return {res.top()};
    }
};

int main()
{
    return 0;
}
