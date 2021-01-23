#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <map>

using namespace::std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 0, maxlen = 0;
        vector<int> dp(n, 0);
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; ++i) {
            int len = 0, maxcnt = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    if (dp[j] == len) {
                        maxcnt += cnt[j];
                    } else if (dp[j] > len) {
                        len = dp[j];
                        maxcnt = cnt[j];
                    }
                }
            }
            dp[i] = len + 1;
            cnt[i] = maxcnt == 0 ? 1 : maxcnt;
            maxlen = max(dp[i], maxlen);
        }
        for (int i = n - 1; i >= 0; --i) {
            if (maxlen == dp[i])
                res += cnt[i];
        }
        return res;
    }
};

int main()
{
    return 0;
}
