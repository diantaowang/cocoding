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
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        if (n == 2)
            return 91;
        int result = 91, pre = 81;
        for (int i = 3, j = 8; i <= min(n, 10); ++i, --j) {
            pre *= j;
            result += pre;
        }
        return result;
    }
};

int main()
{
    return 0;
}
