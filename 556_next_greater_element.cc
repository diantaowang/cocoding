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
    int nextGreaterElement(int n) {
		string s = to_string(n);
        stack<int> stk;
        int l = -1, r = -1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (stk.empty()) {
                stk.push(i);
            } else if (s[i] > s[stk.top()]) {
                stk.push(i);
            } else if (s[i] < s[stk.top()]) {
                l = i;
                while (!stk.empty() && s[i] < s[stk.top()]) {
                    r = stk.top();
                    stk.pop();
                }
                break;
            }
        }
        if (l == -1)
            return -1;
        swap(s[l], s[r]);
        sort(s.begin() + l + 1, s.end());
        long long res = stoll(s, NULL, 10);
        if (res > INT32_MAX)
            return -1;
        else
            return res;
    }
};

int main()
{
    return 0;
}
