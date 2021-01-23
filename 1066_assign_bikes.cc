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
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        int result = INT32_MAX;
        vector<int> dp(1 << m, INT32_MAX);
        vector<vector<int>> dist(n + 1, vector<int> (m + 1, 0));
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j)
                dist[i][j] = abs(workers[i - 1][0] - bikes[j - 1][0]) + abs(workers[i - 1][1] - bikes[j - 1][1]);
        }
        
        dp[0] = 0;
        for (int i = 1; i < (1 << m); ++i) {
            int cnt = 0;
            for (int j = i; j != 0; j >>= 1) {
                if (j & 0x1)
                    ++cnt;
            }
            if (cnt > n)
                continue;
            for (int mask = 1, pos = 1; mask <= i; mask <<= 1, ++pos) {
                if (mask & i) {
                    int idx = i & (~mask);
                    dp[i] = min(dp[i], dp[idx] + dist[cnt][pos]);
                }                
            }
            if (cnt == n)
                result = min(result, dp[i]);
        }
        return result;
    }
};

int main()
{
    return 0;
}
