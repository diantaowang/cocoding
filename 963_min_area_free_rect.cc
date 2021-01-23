#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        unsigned long long area = UINT64_MAX;
        unordered_map<unsigned, unordered_map<long long,vector<pair<int, int>>>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                unsigned len = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
                long long pos = (long long)(points[i][0] + points[j][0]) << 32 | (points[i][1] + points[j][1]);
                edges[len][pos].push_back({i, j});
            }
        }
        for (auto iter = edges.begin(); iter != edges.end(); ++iter) {
            auto end2 = iter->second.end();
            for (auto iter2 = iter->second.begin(); iter2 != end2; ++iter2) {
                int size = iter2->second.size();
                for (int i = 0; i < size; ++i) {
                    for (int j = i + 1; j < size; ++j) {
                        int x = iter2->second[i].first;
                        int y = iter2->second[i].second;
                        int z = iter2->second[j].first;
                        unsigned long long v0 = pow(points[x][0] - points[z][0], 2) + pow(points[x][1] - points[z][1], 2);
                        unsigned long long v1 = pow(points[y][0] - points[z][0], 2) + pow(points[y][1] - points[z][1], 2);
                        area = min(area, v0 * v1);
                    }
                }
            }
        }
        if (area == UINT64_MAX)
            return 0.0;
        else 
            return sqrt(area);
    }
};

int main()
{
    return 0;
}
