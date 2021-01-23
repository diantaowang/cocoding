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
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (const auto& e : nums)
            sum += e;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (int j = 0; j < n; j += 1) {
            for (int i = j; i >= 0; --i) {
                if (i == j) {
                    dp[i][j] = nums[i];
                } else if (i == j - 1) {
                    if (n % 2)
                        dp[i][j] = min(nums[i], nums[j]);
                    else 
                        dp[i][j] = max(nums[i], nums[j]);
                } else {
                    int v0 = min(dp[i + 1][j - 1], dp[i][j - 2]) + nums[j];
                    int v1 = min(dp[i + 1][j - 1], dp[i + 2][j]) + nums[i];
                    dp[i][j] = max(v0, v1);
                }
            }
        }
        return sum <= 2 * dp[0][n - 1];
    }
};

int main()
{
    return 0;
}
