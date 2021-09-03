#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) { 
        int ret = 0;
        vector<int> cnts(m * n, 0), nexts(m * n, 0);
        cnts[startRow * n + startColumn] = 1;
        for (int i = 0; i < maxMove; ++i) {
            for (int j = 0; j < m * n; ++j) {
                int row = j / n, col = j % n;
                for (int k = 0; k < 4; ++k) {
                    int new_row = row + dr[k];
                    int new_col = col + dc[k];
                    if (new_row < 0 || new_row >= m || new_col < 0 || new_col >= n) {
                        ret = (ret + cnts[j]) % 1000000007;
                    } else {
                        int idx = new_row * n + new_col;
                        nexts[idx] = (nexts[idx] + cnts[j]) % 1000000007;
                    }
                }
            } 
            swap(cnts, nexts);
            fill_n(nexts.begin(), m * n, 0);
        } 
        return ret;
    }

    int findPaths2(int m, int n, int maxMove, int startRow, int startColumn) { 
        unsigned long long ret = 0;
        unordered_map<int, unsigned long long> cnts, nexts;
        cnts.insert({startRow << 16 | startColumn, 1});
        for (int i = 0; i < maxMove; ++i) {
            for (const auto &e : cnts) {
                int row = e.first >> 16;
                int col = e.first & 0x0000ffff;
                for (int k = 0; k < 4; ++k) {
                    int new_row = row + dr[k];
                    int new_col = col + dc[k];
                    if (new_row < 0 || new_row >= m || new_col < 0 || new_col >= n) {
                        ret = (ret + e.second) % 1000000007;
                    } else {
                        int idx = new_row << 16 | new_col;
                        nexts[idx] = (nexts[idx] + e.second) % 1000000007;
                    }
                }
            } 
            swap(cnts, nexts);
            nexts.clear();
        } 
        return ret;
    }
private:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
};
