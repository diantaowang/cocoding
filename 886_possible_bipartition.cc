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
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int n = dislikes.size();
        if (!n) return true;
        vector<vector<int>> graph(N + 1);
        vector<int> visited(N + 1, 0);
        stack<int> stk;
        for (const auto& e : dislikes) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        for (int i = 1; i < N + 1; ++i) {
            if (!visited[i]) {
                stk.push(i);
                visited[i] = 1;
            }
            while (!stk.empty()) {
                int idx = stk.top(), color = visited[idx];
                stk.pop();
                for (const auto& j : graph[idx]) {
                    if (visited[j] == 0) {
                        visited[j] = -color;
                        stk.push(j);
                    } else if (visited[j] == color) {
                        return false;
                    }
                }

            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
