#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace::std;

class Solution {
public:
	inline int getpos(vector<int>& cnt) {
        int val = 0, base = 1;
        for (int i = cnt.size() - 1; i >= 0; --i) {
            val += cnt[i] * base;
            base *= width;
        }
        return val;
    } 

    int dfs(vector<int>& dp, vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int idx = getpos(needs);
        if (dp[idx] != -1)
            return dp[idx];

        dp[idx] = 0;
        for (int i = 0; i < needs.size(); ++i)
            dp[idx] += needs[i] * price[i];
        
        vector<int> res(needs.size());
        for (int i = 0; i < special.size(); ++i) {
            int finded = 1;
            for (int j = 0; j < needs.size(); ++j) {
                if (needs[j] < special[i][j]) {
                    finded = 0;
                    break;
                }
                res[j] = needs[j] - special[i][j];
            }
            if (finded)
                dp[idx] = min(dp[idx], special[i].back() + dfs(dp, price, special, res));
        }
        return dp[idx];
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        for (const auto& e : needs)
            width = max(width, e);
        width += 1;
        int last = getpos(needs);
        vector<int> dp(last + 1, -1);
        return dfs(dp, price, special, needs);
    }
private:
    int width = 0;
};

int main()
{
    return 0;
}
