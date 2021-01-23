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
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(), maxlen = 0;
        vector<int> dp(n + 1, 0), next_dp(n + 1, 0);
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    next_dp[j] = dp[j - 1] + 1;
                    maxlen = max(next_dp[j], maxlen);
                } else {
                    next_dp[j] = 0;
                }
            }
            swap(dp, next_dp);
        }
        return maxlen;
    }
};

int main()
{
    return 0;
}
