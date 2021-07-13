#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int isValid(vector<int> &used, int n, int m) {
        auto a = idxmap[n - 1], b = idxmap[m - 1];
        if (a.first == b.first && abs(a.second - b.second) == 2 ||
                a.second == b.second && abs(a.first - b.first) == 2 ||
                abs(a.first - b.first) == 2 && abs(a.second - b.second) == 2) {
            return used[(n + m) / 2];
        }
        return 1;
    }

    int dfs(vector<int> &used, int n, int last) {
        int ret = 0;
        if (n == 0)
            return 1;
        for (int i = 1; i <= 9; ++i) {
            if (!used[i] && isValid(used, last, i)) {
                used[i] = 1;
                ret += dfs(used, n - 1, i);
                used[i] = 0;
            } 
        }
        return ret;
    }
    
    int calc(vector<int> &used, int n) {
        int ret = 0;
        used[1] = 1;
        ret += 4 * dfs(used, n - 1, 1);
        used[1] = 0;
        used[2] = 1;
        ret += 4 * dfs(used, n - 1, 2);
        used[2] = 0;
        used[5] = 1;
        ret += dfs(used, n - 1, 5);
        used[5] = 0;
        return ret;
    }

    int numberOfPatterns(int m, int n) {
        int ret = 0;
        vector<int> used(10, 0);
        for (int i = m; i <= n; ++i) {
            ret += calc(used, i); 
        }
        return ret;
    }
private:
    vector<pair<int, int>> idxmap{{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
};

