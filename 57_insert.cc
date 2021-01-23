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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int n = intervals.size();
        vector<vector<int>> result;
        if (newInterval.empty())
            return intervals;
        if (n == 0) {
            result.push_back(newInterval);
            return result;
        }
        bool has_insert = false;
        int lower = newInterval[0], upper = newInterval[1];
        for (int i = 0; i < n; ++i) {
            if (has_insert) {
                result.push_back(intervals[i]);
            } else if (upper < intervals[i][0]) {
                result.push_back({lower, upper});
                has_insert = true;
                result.push_back(intervals[i]);
            } else if (lower > intervals[i][1]) {
                result.push_back(intervals[i]);
            } else {
                lower = min(lower, intervals[i][0]);
                upper = max(upper, intervals[i][1]);
            }
        }
        if (!has_insert)
            result.push_back({lower, upper});
        return result;
    }
};

int main()
{
    return 0;
}
