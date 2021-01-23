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
    static bool cmp (const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] <= b[1] : a[0] < b[0]; 
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(), result = 0;
        sort(points.begin(), points.end(), cmp);
        for (int i = 0; i < n; ) {
            int l = points[i][0], r = points[i][1];
            ++i;
            while (i != n && points[i][0] <= r) {
                r = min(r, points[i][1]);
                ++i;
            }
            ++result;
        }
        return result;
    }
};

int main()
{
    return 0;
}
