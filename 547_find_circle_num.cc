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
    int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
        if (!n) return 0;
        vector<int> visited(n, 0);
        stack<int> stk;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                visited[i] = 1;
                stk.push(i);
                ++cnt;
            }
            while (!stk.empty()) {
                int idx = stk.top();
                stk.pop();
                for (int j = 0; j < n; ++j) {
                    if (M[idx][j] && !visited[j]) {
                        visited[j] = 1;
                        stk.push(j);
                    }
                }
            }
        }
        return cnt;
    }
};

int main()
{
    return 0;
}
