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
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = workers.size(), n = bikes.size();
        if (!m) return {};
        
        vector<int> result(m, -1), visited(n, 0), visited2(n, 0);
        map<int, vector<pair<int, int>>> dist;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]); 
                dist[val].push_back({i, j});
            }
        }

        for (auto iter = dist.begin(); iter != dist.end(); ++iter) {
            for (const auto& e : iter->second) {
                if (!visited[e.first] && !visited2[e.second]) {
                    visited[e.first] = 1;
                    visited2[e.second] = 1;
                    result[e.first] = e.second;
                }
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
