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
    string removeKdigits(string num, int k) {
        if (num.empty() || k == 0)
            return num;
        stack<int> stk;
        stk.push(num[0]);
        int cnt = 0, finished = 0, i;
        for (i = 1; i < (int)num.size(); ++i) {
            while (!stk.empty() && num[i] < stk.top()) {
                ++cnt;
                stk.pop();
                if (cnt == k) {
                    finished = 1;
                    break;
                }
            }
            stk.push(num[i]);
            if (finished) {
                ++i;
                break;
            }
        }
        while (cnt < k) {
            stk.pop();
            ++cnt;
        }
        string revstr, result;
        while (!stk.empty()) {
            revstr.push_back(stk.top());
            stk.pop();
        }
        for (int j = revstr.size(); j-- > 0;)
            result.push_back(revstr[j]);
        while (i < (int)num.size())
            result.push_back(num[i++]);
        int start = 0;
        while (start != result.size() && result[start] == '0')
            ++start;
        string real_result = result.substr(start, result.size() - start); 
        if (real_result.empty())
            return "0";
        else
            return real_result;
    }
};

int main()
{
    return 0;
}
