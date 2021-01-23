#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <tuple>

using namespace::std;

class Solution {
public:
    pair<int, int> getnum(string& s, int& start) {
        int n = s.size();
        int v0 = 0, v1 = 0;
        while (s[start] != '/') {
            v0 *= 10;
            v0 += s[start++] - '0';
        }
        ++start;
        while (start != n && isdigit(s[start])) {
            v1 *= 10;
            v1 += s[start++] - '0';
        }
        return {v0, v1};
    }

    string fractionAddition(string expression) {
        int n = expression.size(), a, b;
        int symbal = expression[0] == '-' ? -1 : 1;
        int idx = expression[0] == '-' ? 1 : 0;
        tie(a, b) = getnum(expression, idx);
        a *= symbal; 
        
        while (idx < n) {
            int c, d;
            symbal = expression[idx] == '-' ? -1 : 1;
            ++idx;
            tie(c, d) = getnum(expression, idx);
            c *= symbal;
            if (a == 0) {
                a = c;
                b = d;
            } else {
                long long v0 = (long long)a * d + (long long)c * b;
                long long v1 = (long long)b * d;
                long long v2 = __gcd(v0, v1);
                a = v0 / v2;
                b = v1 / v2;
                if (b < 0) {
                    a = -a;
                    b = -b;
                }
            }
        }
        return to_string(a) + '/' + to_string(b);
    }
};

int main()
{
    return 0;
}
