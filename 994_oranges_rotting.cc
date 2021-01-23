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
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0, cnt = 0, old = fresh;
        stack<pair<int, int>> stk;
        while (1) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (cnt == 0 && grid[i][j] == 1)
                        ++fresh;
                    else if (grid[i][j] == 1) {
                        for (int k = 0; k < 4; ++k) {
                            int nx = i + dx[k], ny = j + dy[k];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 2) {
                                stk.push({i, j});
                                --fresh;
                                break;;
                            }
                        }                     
                    }
                }
            }
            while (!stk.empty()) {
                auto pos = stk.top();
                grid[pos.first][pos.second] = 2;
                stk.pop();
            }

            if (fresh == 0)
                return cnt;
            else if (fresh == old)
                return -1;
            ++cnt;
            old = fresh;
        }
    }
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
};

int main()
{
    return 0;
}
