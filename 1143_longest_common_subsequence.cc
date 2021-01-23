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
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<int> dp(n2 + 1, 0), next_dp(n2 + 1, 0);
        for (int i = 1; i < n1 + 1; ++i) {
            for (int j = 1; j < n2 + 1; ++j) {
                if (text2[j - 1] == text1[i - 1])
                    next_dp[j] = dp[j - 1] + 1;
                else
                    next_dp[j] = max(next_dp[j - 1], dp[j]);
            }
            swap(dp, next_dp);
        }
        return dp[n2];
    }
};

int main()
{
    return 0;
}
