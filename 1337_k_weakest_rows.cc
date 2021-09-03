#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unsigned m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> val(m, {0, 0});
        vector<int> ret;
        for (unsigned i = 0; i < m; ++i) {
            val[i].second = i; 
            for (unsigned j = 0; j < n; ++j) {
                if (!mat[i][j]) {
                    break;
                }
                ++val[i].first; 
            }
        }
        sort(val.begin(), val.end());
        for (unsigned i = 0; i < k; ++i) {
            ret.emplace_back(val[i].second);
        }
        return ret;
    }
};
