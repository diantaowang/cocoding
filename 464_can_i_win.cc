#include <iterator>
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
    int dfs(vector<int>& dp, int state, int n, int target) {
        if (dp[state] != -1)
            return dp[state];

        for (int i = 1; i <= n; ++i) {
            int cur = 1 << (i - 1);
            if ((state & cur) == 0) {
                if (target <= i || !dfs(dp, state | cur, n, target - i)) {
                    dp[state] = 1;
                    return 1;
                }
            }               
        }
        dp[state] = 0;
        return 0;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int n = maxChoosableInteger, target = desiredTotal;
        if (target > (1 + n) * n / 2)
            return false;
        vector<int> dp(1 << n, -1);
        return dfs(dp, 0, n, target); 
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    Solution solu;
    solu.canIWin(m, n);
    return 0;
}
