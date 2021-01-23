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
    int dfs(vector<vector<int>>& edges, vector<int>& visited, 
            vector<int>& result, vector<int>& quiet, int src) {
        int n = visited.size();
        int idx = src;
        for (int i = 0; i < n; ++i) {
            if (edges[src][i]) {
                if (visited[i] && quiet[result[i]] < quiet[idx]) {
                    idx = result[i];
                } else if (!visited[i]) {
                    visited[i] = 1;
                    int next_idx = dfs(edges, visited, result, quiet, i);
                    if (quiet[next_idx] < quiet[idx])
                        idx = next_idx;
                }
            }
        }
        result[src] = idx;
        return idx;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> result(n, -1);
        vector<int> visited(n, 0);
        vector<vector<int>> edges(n, vector<int> (n, 0));
        for (const auto& e : richer)
            edges[e[1]][e[0]] = 1;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                visited[i] = 1;
                dfs(edges, visited, result, quiet, i);
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
