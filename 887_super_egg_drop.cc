#include <vector>
#include <string>
#include <iostream>

using namespace::std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int> (N + 1, 10010));
        for (int k = 0; k < K + 1; ++k)
            dp[k][0] = 0;
        for (int k = 1; k < K + 1; ++k) {
            for (int n = 1; n < N + 1; ++n) {
                int l = 0, r = n - 1;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (dp[k - 1][mid] >= dp[k][n - 1 - mid])
                        r = mid;
                    else
                        l = mid + 1;
                }
                dp[k][n] = 1 + max(dp[k - 1][l], dp[k][n - 1 - l]);
                if (l > 0)
                    dp[k][n] = min(dp[k][n], 1 + max(dp[k - 1][l - 1], dp[k][n - l]));
            }
        }
        return dp[K][N];
    }
};

class Solution_slow {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int> (N + 1, 10010));
        for (int k = 0; k < K + 1; ++k)
            dp[k][0] = 0;
        for (int k = 1; k < K + 1; ++k) {
            for (int n = 1; n < N + 1; ++n) {
                for (int x = 1; x <= n; ++x) {
                    int tmp = 1 + max(dp[k - 1][x - 1], dp[k][n - x]);
                    dp[k][n] = min(dp[k][n], tmp);
                } 
            }
        }
        return dp[K][N];
    }
};

int main()
{
    int k, n;
    cin >> k >> n;
    Solution solu;
    cout << solu.superEggDrop(k, n) << endl;
    return 0;
}
