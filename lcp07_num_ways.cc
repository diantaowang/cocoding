#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int dfs(vector<vector<int>>& graph, int k, int n, int deep, int src) {
        if (deep == k - 1 && graph[src][n])
            return 1;
        else if (deep == k - 1)
            return 0;

        int cnt = 0;
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[src][i])
                cnt += dfs(graph, k, n, deep + 1, i);
        }
        return cnt;
    }
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> graph(n, vector<int> (n, 0));
        for (const auto& e : relation)
            graph[e[0]][e[1]] = 1;
        return dfs(graph, k, n - 1, 0, 0); 
    }
};

