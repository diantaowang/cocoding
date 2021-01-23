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
    bool judge(string pattern, string value, int x, int y) {
        string s1, s2;
        int start = 0, ok1 = 0, ok2 = 0;
        for (const auto & c : pattern) {
            if (c == 'a') {
                if (ok1 == 0) {
                    ok1 = 1;
                    s1 = value.substr(start, x);
                    start += x;
                } else if (s1 == value.substr(start, x)) {
                    start += x;
                } else {
                    return false;
                }
            } else if (c == 'b') {
                if (ok2 == 0) {
                    ok2 = 1;
                    s2 = value.substr(start, y);
                    start += y;
                } else if (s2 == value.substr(start, y)) {
                    start += y;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    bool patternMatching(string pattern, string value) {
        int lens = value.size(), a = 0, b = 0;
        for (const auto& e : pattern) {
            if (e == 'a')
                ++a;
            if (e == 'b')
                ++b;
        }
        if (lens == 0) {
            if (a == 0 || b == 0)
                return true;
            else
                return false;
        }
        if (a == 0 && b == 0) {
            return false;
        } else if (a == 0) {
            if (lens % b)
                return false;
            return judge(pattern, value, 0, lens / b);
        } else if (b == 0) {
            if (lens % a)
                return false;
            return judge(pattern, value, lens / a, 0);
        }
        for (int x = 0; x <= lens / a; ++x) {
            int res = lens - a * x;
            if (res % b == 0) {
                int y = res / b;
                if (judge(pattern, value, x, y))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}
