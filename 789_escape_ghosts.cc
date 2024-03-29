#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int len = abs(target[0]) + abs(target[1]);
        for (int i = 0; i < ghosts.size(); ++i) {
            int val = abs(ghosts[i][0] - target[0]) + abs(ghosts[i][1] - target[1]);
            if (val <= len) {
                return false;
            }
        }
        return true;
    }
};
