#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> cnts(n);
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1];
            for (int j = 0; j < i; ++j) {
                long long diff = (long long) nums[i] - nums[j];
                auto iter = cnts[j].find(diff);
                if (iter != cnts[j].end()) {
                    dp[i] += cnts[j][diff];
                    cnts[i][diff] += cnts[j][diff];
                }
                cnts[i][diff] += 1;
            } 
        }
        return dp[n - 1];
    }
};
