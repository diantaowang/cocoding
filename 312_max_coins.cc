#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> mynums(1, 1);
        for (const auto& e : nums)
            mynums.push_back(e);
        mynums.push_back(1);
        auto size = mynums.size();
        vector<vector<int>> dp(size, vector<int> (size, 0));
        for (int step = 2; step < size; ++step) {
            for (int i = 0; i + step < size; ++i) {
                int maxval = -1;
                for (int k = i + 1; k < i + step; ++k) {
                    int newval = mynums[i] * mynums[i + step] * mynums[k] + dp[i][k] + dp[k][i + step];
                    if (newval > maxval)
                        maxval = newval;
                }
                dp[i][i + step] = maxval;
            }
        }
        return dp[0][size - 1];
    }
};

int main()
{
    vector<int> nums;
    int t;
    while (cin >> t)
        nums.push_back(t);
    Solution solu;
    cout << solu.maxCoins(nums) << endl;
    return 0;
}
