#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>

using namespace::std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n)
            return 0;
        if (grid[row][col] != 1)
            return 0;
        int cnt = 1;
        grid[row][col] = 2;
        cnt += dfs(grid, row, col + 1);
        cnt += dfs(grid, row, col - 1);
        cnt += dfs(grid, row + 1, col);
        cnt += dfs(grid, row - 1, col);
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
	    int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    result = max(result, dfs(grid, i, j));
            }
        }
        return result;	
    }
};

int main()
{
    return 0;
}
