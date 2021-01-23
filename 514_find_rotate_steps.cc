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
    int findRotateSteps(string ring, string key) {
		int n = ring.size(), m = key.size();
        int result = INT32_MAX;
        int dp[m][n];
        vector<vector<int>> pos(26);
        
        for (int i = 0; i < n; ++i)
            pos[ring[i] - 'a'].push_back(i);
        
        for (int i = 0; i < pos[key[0] - 'a'].size(); ++i) {
            int idx = pos[key[0] - 'a'][i];
            dp[0][idx] = min(idx, n - idx) + 1;
        }

        for (int i = 1; i < m; ++i) {
            int idx = key[i] - 'a';
            for (int j = 0; j < pos[idx].size(); ++j) {
                int ii = pos[idx][j];
                int idx2 = key[i - 1] - 'a';
                dp[i][ii] = INT32_MAX;
                for (int k = 0; k < pos[idx2].size(); ++k) {
                    int kk = pos[idx2][k];
                    int val = dp[i - 1][kk] + min(abs(ii - kk), n - abs(ii - kk)) + 1;
                    dp[i][ii] = min(dp[i][ii], val);
                }
            }
        }
        
        for (int i = 0; i < pos[key[m - 1] - 'a'].size(); ++i) {
            int idx = pos[key[m - 1] - 'a'][i];
            result = min(result, dp[m - 1][idx]);
        }
        
        return result;
    }
};

int main()
{
    return 0;
}
