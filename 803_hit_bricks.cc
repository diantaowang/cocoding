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

class DSU {
public:
    DSU(int n) : rank(n, 1), size(n, 1) {
        for (int i = 0; i < n; ++i)
            fa.push_back(i);
    }
    
    inline int find(int x) {
        return fa[x] == x ? x : (fa[x] = find(fa[x]));
    }

    inline void merge(int x, int y) {
        int xx = find(x), yy = find(y);
        if (xx == yy)
            return;
        if (rank[xx] < rank[yy])
            swap(xx, yy);
        fa[yy] = xx;
        if (rank[xx] == rank[yy])
            ++rank[xx];
        size[xx] += size[yy];
    }

    inline int getSize(int x) {
        return size[find(x)];
    }

private:
    vector<int> fa;
    vector<int> rank;
    vector<int> size;
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size(), size = hits.size();
        vector<vector<int>> arr = grid;
        DSU dsu(m * n + 1);
        
        for (int i = 0; i < size; ++i) {
            arr[hits[i][0]][hits[i][1]] = 0;
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i][j]) {
                    if (i == 0)
                        dsu.merge(i * n + j, m * n);
                    if (i > 0 && arr[i - 1][j])
                        dsu.merge(i * n + j, (i - 1) * n + j);
                    if (j > 0 && arr[i][j - 1])
                        dsu.merge(i * n + j, i * n + j - 1);
                }
            }
        }

        vector<int> result(size);
        for (int i = size - 1; i >= 0; --i) {
            if (grid[hits[i][0]][hits[i][1]] == 0)
                continue;
            int pre_cnt = dsu.getSize(m * n); 
            for (int j = 0; j < 4; ++j) {
                int x = hits[i][0] + dx[j], y = hits[i][1] + dy[j];
                if (x >= 0 && x < m && y >= 0 && y < n && arr[x][y])
                    dsu.merge(x * n + y, hits[i][0] * n + hits[i][1]);
            }
            arr[hits[i][0]][hits[i][1]] = 1;
            if (hits[i][0] == 0)
                dsu.merge(hits[i][0] * n + hits[i][1], m * n);
            result[i] = max(0, dsu.getSize(m * n) - 1 - pre_cnt); 
        }
        return result;
    }
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
};

int main()
{
    return 0;
}
