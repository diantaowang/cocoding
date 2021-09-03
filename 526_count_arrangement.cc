#include <bits/stdc++.h>
#include <vector>

using namespace::std;

class Solution2 {
public:
    int dfs(vector<bool> &visited, int n, int pos) {
        int ret = 0;
        if (pos > n) {
            return 1;
        }
        for (int val = 1; val <= n; ++val) {
            if (!visited[val] && (val % pos == 0 || pos % val == 0)) {
                visited[val] = true;
                ret += dfs(visited, n, pos + 1);
                visited[val] = false;
            }
        }
        return ret;
    }

    int countArrangement(int n) {
        vector<bool> visited(n + 1, false);
        return dfs(visited, n, 1);
    }
};


class Solution {
public:
    int dfs(vector<int> &cnts, int used, int n, int pos) {
        if (pos > n) {
            return 1;
        }
        
        int res = (~used) & ((1 << n) - 1);
        if (cnts[res] != -1) {
            return cnts[res];
        }
        
        int ret = 0;
        for (int i = 1, mask = 1; i <= n; ++i, mask <<= 1) {
            if (!(used & mask) && (i % pos == 0 || pos % i == 0)) {
                ret += dfs(cnts, used | mask, n, pos + 1);
            }
        }

        cnts[res] = ret;
        return ret;
    }

    int countArrangement(int n) {
        vector<int> cnts(1 << n, -1);
        return dfs(cnts, 0, n, 1);
    }
};

