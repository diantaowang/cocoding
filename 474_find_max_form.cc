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
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        int len = strs.size();
        vector<pair<int, int>> cnts(len);
        for (int i = 0; i < len; ++i) {
            for (const auto& c : strs[i]) {
                if (c == '0')
                    ++cnts[i].first;
                if (c == '1')
                    ++cnts[i].second;
            }
        }

        for (int k = 0; k < len; ++k) {
            for (int i = m; i >= 0; --i) {
                for (int j = n; j >= 0; --j) {
                    if (cnts[k].first <= i && cnts[k].second <= j)
                        dp[i][j] = max(1 + dp[i - cnts[k].first][j - cnts[k].second], dp[i][j]);            
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    return 0;
}
