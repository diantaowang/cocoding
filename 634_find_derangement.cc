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
    int findDerangement(int n) {
		int mod = 1e9 + 7;
        if (n == 1)
            return 0;
        if (n == 2)
            return 1;
        int a = 0, b = 1, c = 0;
        for (int i = 3; i <= n; ++i) {
            c = (long long)(i - 1) * (b + a) % mod;
            a = b;
            b = c;
        }
        return c;
    }
};

int main()
{
    return 0;
}
