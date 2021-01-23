#include <cstdarg>
#include <functional>
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
    bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (const auto& e : prerequisites) {
            ++indegree[e[0]];
            graph[e[1]].push_back(e[0]);
        }
        stack<int> stk;
        for (int i = 0; i < numCourses; ++i) {
            if (!indegree[i])
                stk.push(i);
        }
        int cnt = 0;
        while (!stk.empty()) {
            ++cnt;
            int coures_id = stk.top();
            stk.pop();
            for (const auto& e : graph[coures_id]) {
                if (--indegree[e] == 0 )
                    stk.push(e);
            }
        }
        return cnt == numCourses;
    }
};

int main()
{
    return 0;
}
