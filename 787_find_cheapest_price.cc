#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto &e : flights) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        vector<int> sourecs(1, src);
        vector<int> dist(n, INT32_MAX / 2);
        dist[src] = 0;
        for (int i = 0; i <= k; ++i) {
            if (sourecs.empty()) {
                break;
            }
            vector<int> next_src;
            vector<int> next_dist(dist);
            for (const auto &s : sourecs) {
                for (const auto &d : graph[s]) {
                    if (next_dist[d.first] > dist[s] + d.second) {
                        next_dist[d.first] = dist[s] + d.second;
                        next_src.push_back(d.first);
                    }
                }
            }
            sourecs = move(next_src);
            dist = move(next_dist);
        }
        return dist[dst] == INT32_MAX / 2 ? -1 : dist[dst];
    }
};

