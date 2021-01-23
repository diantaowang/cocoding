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
    double calc(double x, long long n) {
        if (n == 1)
            return x;
        auto val = calc(x, n / 2);
        val *= val;
        if (n & 0x1)
            val *= x;
        return val;
    }

    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        double res = calc(x, abs(n));
        if (n < 0)
            return 1 / res;
        else
            return res;
    }
};

int main()
{
    return 0;
}
