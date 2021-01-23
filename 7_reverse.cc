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
    int reverse(int x) {
        long long a = abs(x);
        long long result = 0;
        while (a) {
            result *= 10;
            result += a % 10;
            a /= 10;
        }
        if (x < 0)
            result = -result;
        if (result < INT32_MIN || result > INT32_MAX)
            return 0;
        else
            return result;
    }
};

int main()
{
    return 0;
}
