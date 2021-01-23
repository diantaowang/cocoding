#include <cstdio>
#include <ios>
#include <utility>
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
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> nodes;
        vector<int> result;
        int n = intervals.size();
        for (int i = 0; i < n; ++i)
            nodes.push_back({intervals[i][0], i});
        sort(nodes.begin(), nodes.end());
        for (int i = 0; i < n; ++i) {
            pair<int, int> tmp(intervals[i][1], 0);
            auto pos = lower_bound(nodes.begin(), nodes.end(), tmp, cmp);
            if (pos == nodes.end())
                result.push_back(-1);
            else 
                result.push_back(pos->second);
        }
        return result;
    }
};

int main()
{
    return 0;
}
