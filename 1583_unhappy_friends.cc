#include "bits/stdc++.h"

using namespace::std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int ret = 0;
        vector<bool> unhappy(n, false);
        vector<vector<int>> relation(n, vector<int> (n, 0));
        for (int i = 0; i < n; ++i) {
            int val = n;
            for (int j = 0; j < n - 1; ++j, --val) {
                relation[i][preferences[i][j]] = val;
            }
        }
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i + 1; j < n / 2; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int x = pairs[i][dx[k]], y = pairs[i][1 - dx[k]];
                    int u = pairs[j][du[k]], v = pairs[j][1 - du[k]];
                    if (relation[x][u] > relation[x][y] && relation[u][x] > relation[u][v]) {
                        unhappy[x] = true;
                        unhappy[u] = true;
                    }
                } 
            }
        }
        for (const auto &e : unhappy) {
            if (e) {
                ++ret;
            }
        }
        return ret;
    }
private:
    int dx[4] = {0, 0, 1, 1};
    int du[4] = {0, 1, 0, 1};
};
