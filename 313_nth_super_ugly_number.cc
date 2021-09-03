#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int nthSuperUglyNumber2(int n, vector<int>& primes) {
        int size = primes.size();
        priority_queue<int, vector<int>, greater<int>> que;
        que.push(1);
        unordered_set<int> ugly;
        ugly.insert(1);
        while (--n) {
            long long minval = que.top();
            que.pop();
            for (int i = 0; i < size; ++i) {
                if (minval * primes[i] > INT32_MAX) {
                    break;
                }
                if (ugly.find(minval * primes[i]) == ugly.end()) {
                    que.push(minval * primes[i]);
                    ugly.insert(minval * primes[i]);
                }
            }
        }
        return que.top();
    }
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size = primes.size();
        vector<int> pointer(size + 1, 1);
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            long long minval = INT64_MAX;
            for (int j = 0; j < size; ++j) {
                minval = min(minval, ((long long)dp[pointer[j]]) * primes[j]); 
            }
            dp[i] = minval;
            for (int j = 0; j < size; ++j) {
                if (minval == ((long long)dp[pointer[j]]) * primes[j]) {
                    ++pointer[j];
                }
            }
        }
        return dp[n];
    }
};
