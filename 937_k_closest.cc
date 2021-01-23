#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <queue>

using namespace::std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> que;
        for (int i = 0; i < K; ++i)
            que.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
        for (int i = K; i < points.size(); ++i) {
            int val = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (val < que.top().first) {
                que.pop();
                que.emplace(val, i);
            }
        }
        vector<vector<int>> result;
        while (!que.empty()) {
            result.push_back(points[que.top().second]);
            que.pop();
        }
        return result;
    }
};

int main()
{
    return 0;
}
