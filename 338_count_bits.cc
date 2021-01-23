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
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        int cnt = 1, n = 1;
        for (int i = 0; i < n && cnt <= num; ) {
            dp[cnt] = dp[i] + 1;
            ++cnt;
            ++i;
            if (i == n) {
                n *= 2;
                i = 0;
            }
        }
        return dp;
    }
};

int main()
{
    return 0;
}
