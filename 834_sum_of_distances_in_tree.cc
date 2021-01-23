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
    void dfs(vector<vector<int>>& graph, vector<pair<int, int>>& nodes, 
            vector<int>& visited, int idx) {
        visited[idx] = 1;
        for (int i = 0; i < (int)graph[idx].size(); ++i) {
            int next = graph[idx][i];
            if (!visited[next]) {
                dfs(graph, nodes, visited, next);
                nodes[idx].first += nodes[next].first; 
                nodes[idx].second += nodes[next].second + nodes[next].first;
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> graph(N);
        for (const auto& e: edges) {
            graph[e[1]].push_back(e[0]);
            graph[e[0]].push_back(e[1]);
        }
        
        vector<pair<int, int>> nodes(N, {1, 0});
        vector<int> result(N), visited(N, 0);
        queue<int> que;
        
        dfs(graph, nodes, visited, 0);
        for (int i = 0; i < N; ++i)
            visited[i] = 0;
        visited[0] = 1;
        result[0] = nodes[0].second;
        que.push(0);
        while (!que.empty()) {
            int idx = que.front();
            que.pop();
            for (int i = 0; i < (int)graph[idx].size(); ++i) {
                int next = graph[idx][i];
                if (!visited[next]) {
                    visited[next] = 1;
                    que.push(next);
                    int res = nodes[idx].second - nodes[next].second - nodes[next].first;
                    int cnt = N - nodes[next].first;
                    nodes[next].second += cnt + res;
                    result[next] = nodes[next].second;
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
