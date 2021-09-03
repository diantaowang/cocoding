#include <bits/stdc++.h>

using namespace::std;

#define INF INT32_MAX / 2

class Solution {
public:
    void floyd_warshall(vector<vector<int>>& dist) {
        int n = dist.size();
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
                }
            }
        }
    }        

    int shortestPathLength2(vector<vector<int>>& graph) {
        int n = graph.size(), ret = INF;
        vector<vector<int>> dist(n, vector<int> (n, INF));
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
            for (const auto &e : graph[i]) {
                dist[i][e] = 1;
            }
        }
        floyd_warshall(dist);
        
        vector<vector<int>> mydist(1 << n, vector<int> (n, INF));
        for (unsigned i = 1, j = 0; j < n; i <<= 1, ++j) {
            mydist[i][j] = 0;
        }
        for (unsigned i = 1; i < 1 << n; ++i) {
            for (unsigned mask = 1, s = 0; mask <= i; mask <<= 1, ++s) {
                if (i & mask) {
                    unsigned prev = i & (~mask);
                    for (unsigned k = 0; k < n; ++k) {
                        mydist[i][s] = min(mydist[prev][k] + dist[s][k], mydist[i][s]);
                    }
                }
            }
        }
        for (int i = 0, last = (1 << n) - 1; i < n; ++i) {
            ret = min(mydist[last][i], ret);
        }
        return ret;
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple<int, int, int>> que;
        vector<vector<bool>> visited(n, vector<bool> (1 << n, false));
        for (int i = 0; i < n; ++i) {
            int mask = 1 << i;
            que.push({i, mask, 0});
            visited[i][mask] = true;
        }
        while (!que.empty()) {
            auto [s, mask, dist] = que.front();
            que.pop();
            for (const auto &e : graph[s]) {
                int new_mask = mask | (1 << e);
                if (!visited[e][new_mask]) {
                    visited[e][new_mask] = true;
                    que.push({e, new_mask, dist + 1});
                    if (new_mask == (1 << n) - 1) {
                        return dist + 1;
                    }
                }  
            }
        }
        return 0;
    }
};

