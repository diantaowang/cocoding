#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    inline int calc(int a) {
        return a >= 1000000007 ? a - 1000000007 : a;
    }

    int numberOfCombinations(string num) {
        int n = num.size();
        vector<vector<int>> lcp(n + 1, vector<int> (n + 1 , 0));
        vector<vector<int>> dp(n, vector<int> (n, 0));
        vector<vector<int>> prefix(n, vector<int> (n, 0));
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= i; --j) {
                lcp[i][j] = num[i] == num[j] ? lcp[i + 1][j + 1] + 1 : 0;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int head = 0; head <= i; ++head) {
                if (num[head] == '0') {
                    if (head != 0) {
                        prefix[i][head] = prefix[i][head - 1];
                    }
                } else if (head == 0) {
                    dp[i][head] = 1;
                    prefix[i][head] = 1;
                } else {
                    int l = max(0, 2 * head - i - 1);
                    if (l == 2 * head - i - 1) {
                        int len = i - head + 1;
                        int lcp_len = lcp[l][head];
                        if (lcp_len < len && num[l + lcp_len] > num[head + lcp_len]) {
                            ++l;
                        }
                    }
                    if (l == 0) {
                        dp[i][head] = prefix[head - 1][head - 1];
                    } else {
                        dp[i][head] = calc(prefix[head - 1][head - 1] - prefix[head - 1][l - 1] + 1000000007);
                    }
                    prefix[i][head] = calc(prefix[i][head - 1] + dp[i][head]);
                }
            }
        }

        return prefix[n - 1][n - 1];
    }
};
