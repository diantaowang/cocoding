#include <cstring>
#include <iterator>
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
    int getNextStatus(string& evil, int p, char c)
    {
        --p;
        if (p == evil.size() - 1)
            p = next[p];
        while (p >= 0 && evil[p + 1] != c)
            p = next[p];
        if (evil[p + 1] == c)
            ++p;
        return p + 1;
    }

    int dfs(int pos, int stats, int bound, string& s1, string& s2, string& evil) {
        if (stats == evil.size())
            return 0;
        if (pos == s1.size())
            return 1;
        
        if (dp[pos][stats][bound] != -1)
            return dp[pos][stats][bound];

        dp[pos][stats][bound] = 0;
        
        char lower = 'a', upper = 'z';
        if (bound & 0x1)
            lower = s1[pos];
        if (bound & 0x2)
            upper = s2[pos];

        for (char c = lower; c <= upper; ++c) {
            int next_stats = getNextStatus(evil, stats, c);
            int v0 = c == lower;
            int v1 = (c == upper) << 1;
            int next_bound = bound & (v0 | v1);
            dp[pos][stats][bound] += dfs(pos + 1, next_stats, next_bound, s1, s2, evil);
            dp[pos][stats][bound] %= mod;
        }
        return dp[pos][stats][bound];
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        int m = evil.size();
        next.resize(m);
        next[0] = -1;
        for (int i = 1, j = -1; i < m; ++i) {
            while (j >= 0 && evil[j + 1] != evil[i])
                j = next[j];
            if (evil[j + 1] == evil[i])
                ++j;
            next[i] = j;
        }
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, 3, s1, s2, evil);
    }
private:
    vector<int> next;
    int dp[501][50][4];
    int mod = 1e9 + 7;
};

int main()
{
    return 0;
}
