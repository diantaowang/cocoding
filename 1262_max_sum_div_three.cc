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
    int maxSumDivThree(vector<int>& nums) {
		vector<int> dp(3, 0), next(3, 0);
        for (int i = 0; i < nums.size(); ++i) {
            switch(nums[i] % 3) {
                case 0:
                    next[0] = dp[0] + nums[i];
                    if (dp[1]) next[1] = dp[1] + nums[i];
                    if (dp[2]) next[2] = dp[2] + nums[i];
                    break;
                case 1:
                    if (dp[2]) next[0] = max(dp[0], dp[2] + nums[i]);
                    next[1] = max(dp[1], dp[0] + nums[i]);
                    if (dp[1]) next[2] = max(dp[2], dp[1] + nums[i]);
                    break;
                case 2:
                    if (dp[1]) next[0] = max(dp[0], dp[1] + nums[i]);
                    if (dp[2]) next[1] = max(dp[1], dp[2] + nums[i]);
                    next[2] = max(dp[2], dp[0] + nums[i]);
                    break;
            }
            dp = next;
        }
        return dp[0];
    }
};

int main()
{
    return 0;
}
