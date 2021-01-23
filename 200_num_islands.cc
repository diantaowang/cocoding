#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <queue>
#include <tuple>

using namespace::std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n)
            return;
        if (grid[row][col] != '1')
            return;
        grid[row][col] = '2';
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
    }

    void bfs(vector<vector<char>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        grid[row][col] = '2';
        queue<pair<int, int>> que;
        que.push({row, col});
        while (!que.empty()) {
            int i, j;
            tie(i, j) = que.front();
            que.pop();
            if (j + 1 < n && grid[i][j + 1] == '1') {
                grid[i][j + 1] = '2';
                que.push({i, j + 1});
            }
            if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                grid[i][j - 1] = '2';
                que.push({i, j - 1});
            }
            if (i + 1 < m && grid[i + 1][j] == '1') {
                grid[i + 1][j] = '2';
                que.push({i + 1, j});
            }
            if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                grid[i - 1][j] = '2';
                que.push({i - 1, j});
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    ++result;
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
