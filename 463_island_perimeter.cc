#include <cstdlib>
#include <ctime>
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
    int islandPerimeter(vector<vector<int>>& grid) {
		int len = 0, m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j])
                    continue;
                int once = 0;
                if (i - 1 < 0 || !grid[i - 1][j])
                    ++once;
                if (i + 1 == m || !grid[i + 1][j])
                    ++once;
                if (j - 1 < 0 || !grid[i][j - 1])
                    ++once;
                if (j + 1 == n || !grid[i][j + 1])
                    ++once;
                len += once;
            }
        }
        return len;
    }
};

int main()
{
    return 0;
}
