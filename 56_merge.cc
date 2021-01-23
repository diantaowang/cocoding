#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace::std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        sort(intervals.begin(), intervals.end());
        intervals.push_back({-1, -1});
        int n = intervals.size();
        for (int i = 0; i < n - 1; ++i) {
            if (intervals[i + 1][0] >= intervals[i][0] && intervals[i + 1][0] <= intervals[i][1]) {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
            }
            else
                results.push_back(intervals[i]); 
        }
        return results;
    }
};

int main()
{
    return 0;
}
