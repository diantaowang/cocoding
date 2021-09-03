#include <bits/stdc++.h>

using namespace::std;

class Solution {
public:
    int is_unsafe(int s, vector<vector<int>> &graph, vector<int> &unsafe, vector<bool> &visited) {
        if (unsafe[s] != -1) {
            return unsafe[s]; 
        }
        if (visited[s]) {
            return 1;
        }

        used[s] = true;
        visited[s] = true; 
        int state  = 0;
        for (unsigned i = 0; i < graph[s].size(); ++i) {
            state |= is_unsafe(graph[s][i], graph, unsafe, visited);   
        }
        unsafe[s] = state;
        visited[s] = false;
        return unsafe[s];
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unsigned n = graph.size();
        vector<bool> visited(n, false);
        vector<int> ret;
        vector<int> unsafe(n, -1); // -1: unvisited, 0: safe, 1: unsafe.
        used.resize(n, false);
        
        for (unsigned i = 0; i < n; ++i) {
            if (!used[i]) {
                unsafe[i] = is_unsafe(i, graph, unsafe, visited);
            }
        }
        for (unsigned i = 0; i < n; ++i) {
            if (!unsafe[i]) {
                ret.emplace_back(i);
            }
        }
        return ret;
    }
private:
    vector<bool> used;
};
