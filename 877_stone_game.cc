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
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(), sum = 0;
        for (const auto& e : piles)
            sum += e;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (int j = 1; j < n; j += 1) {
            int lower = (j + 1) % 2;
            for (int i = j - 1; i >= lower; i -= 2) {
                if (i == j - 1)
                    dp[i][j] = max(piles[i], piles[j]);
                else {
                    int v0 = min(dp[i + 1][j - 1], dp[i][j - 2]) + piles[j];
                    int v1 = min(dp[i + 1][j - 1], dp[i + 2][j]) + piles[i];
                    dp[i][j] = max(v0, v1);
                }
            }
        }
        return sum < 2 * dp[0][n - 1];
    }
    
    bool stoneGame2(vector<int>& piles) {
        return true;
    }
};

int main()
{
    return 0;
}
