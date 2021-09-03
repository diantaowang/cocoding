#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end(), [] (const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
        int l = ranges[0][0], r = ranges[0][1];
        if (l > left)
            return false;
        for (int i = 1; i < ranges.size(); ++i) {
            if (r >= right)
                return true;
            if (ranges[i][0] > r + 1 && (left > r && left < ranges[i][0] 
                        || right > r && right < ranges[i][0]) || left <= r && right >= ranges[i][0])
                return false;
            r = max(r, ranges[i][1]);
        }
        return r >= right; 
    }
};
