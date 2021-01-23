#include <vector>
#include <math.h>
#include <string>
#include <iostream>

using namespace::std;

class Solution {
public:
    int minSteps(int n) {
        if (n == 1)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int> (n, 0));
        vector<int> minimum(n + 1, INT32_MAX);
        dp[1][1] = 1;
        minimum[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            for (int j = 1; j <= i / 2; ++j) {
                if (dp[i - j][j]) {
                    dp[i][j] = dp[i - j][j] + 1;
                    minimum[i] = min(minimum[i], dp[i][j]);
                }
            }
            if (i != 2 && (i & 0x1) == 0) {
                int half = i / 2;
                dp[i][half] = minimum[half] + 2;
            }
        }
        return minimum[n];
    }

    int minSteps_fast(int n) {
        if (n == 1)
            return 0;
        int cnt = 0, factor = 2;
        while (n > 1) {
            if (n % factor == 0) {
                cnt += factor;
                n /= factor;
            } else {
                ++factor;
            }
        }
        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution solu;
    cout << solu.minSteps(n) << endl;
    return 0;
}
