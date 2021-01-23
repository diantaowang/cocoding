#include <cmath>
#include <cstdio>
#include <pthread.h>
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
    int countPrimes(int n) {
        vector<bool> dp(n + 1, true);
        int res = 0, end = sqrt(n) + 1;
        for (int prime = 2; prime < n; ++prime) {
            if (dp[prime]) {
                ++res;
                if (prime <= end) {
                    for (long i = prime * prime; i < n; i += prime)
                        dp[i] = false;
                }
            }
        }
        return res;
    }
};


int main()
{
    return 0;
}
