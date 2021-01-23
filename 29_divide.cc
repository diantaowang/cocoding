#include <cstdint>
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
    int divide(int dividend, int divisor) {
		long long a = abs(dividend), b = abs(divisor);
        long long res = 0;
        while (a >= b) {
            long long n = 1;
            long long t = b;
            while (a >= t) {
                n <<= 1;
                t <<= 1; 
            }
            res += (n >> 1);
            a -= (t >> 1);
        }
        long long symbal = (long long) dividend * divisor;
        if (symbal < 0)
            return -res;
        else 
            return res > INT32_MAX ? INT32_MAX : res;
    }
};

int main()
{
    return 0;
}
