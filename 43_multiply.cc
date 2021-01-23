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
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        if (!n1 || !n2)
            return "";
        string ans(n1 + n2, '0');
        int acc = 0;
        for (int i = n1 - 1; i >= 0; --i) {
            acc = 0;
            for (int j = n2 - 1; j >= 0; --j) {
                int v0 = ans[i + j + 1] - '0';
                int v1 = num1[i] - '0';
                int v2 = num2[j] - '0';
                int v = v1 * v2 + acc + v0;
                ans[i + j + 1] = v % 10 + '0';
                acc = v / 10;
            }
             ans[i] = acc + '0';
        }
        auto pos = ans.find_first_not_of("0");
        return pos == string::npos ? "0" : ans.erase(0, pos);
    }
};

int main()
{
    return 0;
}
