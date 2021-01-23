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
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size(), res = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] += dp[j];
                    break;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    return 0;
}
