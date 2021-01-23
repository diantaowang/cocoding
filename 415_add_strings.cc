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
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        int acc = 0;
        string res, res2;
        while (i >= 0 && j >= 0) {
            int val1 = num1[i] - '0';
            int val2 = num2[j] - '0';
            int val = val1 + val2 + acc;
            acc = val / 10;
            res.push_back(val % 10 + '0');
            --i;
            --j;
        }
        while (i >= 0) {
            int val = num1[i] - '0' + acc;
            acc = val / 10;
            res.push_back(val % 10 + '0');
            --i;
        }
        while (j >= 0) {
            int val = num2[j] - '0' + acc;
            acc = val / 10;
            res.push_back(val % 10 + '0');
            --j;
        }
        if (acc)
            res2.push_back('1');
        for (int i = res.size(); i-- > 0; )
            res2.push_back(res[i]);
        return res2;
    }
};

int main()
{
    return 0;
}
